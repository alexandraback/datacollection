#include <bits/stdc++.h>

using namespace std;

namespace Solve {

	template<class T> inline bool _min(T& data, const T& comp) {
		if (comp < data) {
			comp = data;
			return true;
		}
		return false;
	}

	template<class T> inline bool _max(T& data, const T& comp) {
		if (data < comp) {
			comp = data;
			return true;
		}
		return false;
	}

	template<class T> inline vector<T>& operator<< (vector<T> &storage, const T& data) {
		storage.push_back(data);
		return storage;
	}

	template<class T> inline void operator!(const vector<T>& vect) {
		for(const T& data : vect) {
			cout << data << " ";
		}
	}

	template<class T> inline queue<T>& operator<< (queue<T> &storage, const T& data) {
		storage.push(data);
		return storage;
	}

	template<class T> inline stack<T>& operator<< (stack<T> &storage, const T& data) {
		storage.push(data);
		return storage;
	}

	template<class T> inline priority_queue<T>& operator<< (priority_queue<T> &storage, const T& data) {
		storage.push(data);
		return storage;
	}

	template<class T> inline queue<T>& operator>> (queue<T> &storage, T& data) {
		data = storage.front();
		storage.pop();
		return storage;
	}

	template<class T> inline stack<T>& operator>> (stack<T> &storage, T& data) {
		data = storage.top();
		storage.pop();
		return storage;
	}

	template<class T> inline priority_queue<T>& operator>> (priority_queue<T> &storage, T& data) {
		data = storage.top();
		storage.pop();
		return storage;
	}

	queue<long> Q;
	queue<long> S;

	long dist[1048576];

	inline long reverse(long orig) {
		while(orig) {
			S.push(orig % 10);
			orig = orig / 10;
		}
		long ret = 0;
		while(S.size()) {
			ret = ret * 10 + S.front();
			S.pop();
		}
		return ret;
	}

	long solve(const long &target) {
		if (target == 1) return 1;
		memset(dist, -1, sizeof dist);
		dist[1] = 1;
		while(Q.size()) Q.pop();
		Q.push(1);
		while(Q.size()) {
			long now = Q.front();
			Q.pop();
			long next = now + 1;
			if (next <= 1000000) {
				if(next == target) return dist[now] + 1;
				if(dist[next] == -1) {
					dist[next] = dist[now] + 1;
					Q.push(next);
				}
			}
			next = reverse(now);
			if(next == target) return dist[now] + 1;
			if (dist[next] == -1) {
				dist[next] = dist[now] + 1;
				Q.push(next);
			}
		}
		return -1;
	}

	void main(void) {
		ios::sync_with_stdio(false);
		register long i, j;
		long T;
		cin >> T;
		for(auto t = 1; t <= T; ++ t) {
			long N;
			cin >> N;
			cout << "Case #" << t << ": " << solve(N) << endl; 
		}
	}
}

int main(void) {
	Solve::main();
}
