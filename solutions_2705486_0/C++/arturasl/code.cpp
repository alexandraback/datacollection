#include      <algorithm>
#include      <fstream>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
typedef long long ll;
using namespace std;
vector<string> vectDict;

void readDict() {
	ifstream in("dic.txt");
	string str;
	while (in >> str) vectDict.push_back(str);
	in.close();
}

const int THREADS = 20;
const int SLEEP = 1;
pthread_mutex_t printLock;

#include      <pthread.h>
#include      <unistd.h>
#include      <queue>
template<typename T> class JobQueue {
	private:
		queue<T> m_queueJobs;
		pthread_mutex_t m_lock;
	public:
		JobQueue() { pthread_mutex_init(&m_lock, NULL); }
		~JobQueue() { pthread_mutex_destroy(&m_lock); }
		void addJob(const T &job) {
			pthread_mutex_lock(&m_lock); m_queueJobs.push(job); pthread_mutex_unlock(&m_lock);
		}
		bool getJob(T &job, int nWaitInterval = -1) {
			bool bGot = false;
			while (true) {
				pthread_mutex_lock(&m_lock);
				if (!m_queueJobs.empty()) { job = m_queueJobs.front(); m_queueJobs.pop(); bGot = true; }
				pthread_mutex_unlock(&m_lock);

				if (bGot) return true;
				else if (nWaitInterval != -1) sleep(nWaitInterval);
				else return false;
			}
		}
		int jobCount() {
			int cnt = 0;
			pthread_mutex_lock(&m_lock); cnt = m_queueJobs.size(); pthread_mutex_unlock(&m_lock);
			return cnt;
		}
		void getAll(queue<T> &queueJobs) { pthread_mutex_lock(&m_lock); queueJobs = m_queueJobs; pthread_mutex_unlock(&m_lock); }
};
JobQueue< pair<int, string> > jobsQueue;
JobQueue< pair<int, int> > jobsResult;

pair<int, int> canAdd(int nPos, int nLastChangePos, const string& strTarget, const string &strToAdd) {
	if (nPos + strToAdd.length() > strTarget.length()) {
		return make_pair(-1, -1);
	}
	int nChanges = 0;
	for (size_t i = 0; i < strToAdd.length(); i += 1) {
		if (strToAdd[i] != strTarget[nPos + i]) {
			if (nPos + i - nLastChangePos < 5) return make_pair(-1, -1);
			nLastChangePos = nPos + i;
			nChanges += 1;
		}
	}
	return make_pair(nChanges, nLastChangePos);
}

const int INFTY = numeric_limits<int>::max();
void dfs(int nPos, int nLastChangePos, const string &strTarget, int nChanges, int &nBest, map<pair<int, int>, int> &mapPosToBest) {
	if (nPos == (int) strTarget.length()) {
		nBest = min(nBest, nChanges);
		return;
	}

	if (nChanges >= nBest) {
		return;
	}

	int &nPrevMinChanges = mapPosToBest[make_pair(nPos, nLastChangePos)];
	if (nPrevMinChanges != 0 && nPrevMinChanges <= nChanges) return;
	 nPrevMinChanges = nChanges;

	pair<int, int> ptResult;
	for (size_t i = 0; i < vectDict.size(); i += 1) {
		ptResult = canAdd(nPos, nLastChangePos, strTarget, vectDict[i]);
		if (ptResult.first != -1) {
			dfs(nPos + vectDict[i].length(), ptResult.second, strTarget, nChanges + ptResult.first, nBest, mapPosToBest);
		}
	}
}

void* solve(void*) {
	while (jobsQueue.jobCount()) {
		string strTarget;
		pair<int, string> st;
		jobsQueue.getJob(st, SLEEP);
		map<pair<int, int>, int> mapPosToBest;
		int nBest = INFTY;
		dfs(0, -1000, st.second, 0, nBest, mapPosToBest);
		jobsResult.addJob(make_pair(st.first, nBest));
		cerr << "Finished job" << st.first << endl;
	}
	return NULL;
}

int main(int argc, char **argv) {
	readDict();

	int T;
	cin >> T;
	string strTmp;
	for (int t = 1; t <= T; t += 1) {
		cin >> strTmp;
		jobsQueue.addJob(make_pair(t, strTmp));
	}

	for (int t = 1; t <= THREADS; t += 1) {
		pthread_t thread;
		pthread_create(&thread, NULL, solve, NULL);
	}

	while (jobsResult.jobCount() != T) {
		sleep(SLEEP);
	}

	{
		queue< pair<int, int> > queueResult;
		jobsResult.getAll(queueResult);
		vector< pair<int, int> > vectResults;
		while (!queueResult.empty()) { vectResults.push_back(queueResult.front()); queueResult.pop(); }
		sort(vectResults.begin(), vectResults.end());
		each(vectResults, it) cout << "Case #" << it->first << ": " << it->second << endl;
	}


	return 0;
}
