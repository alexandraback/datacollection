/**
  * This template is designed to easily solve problems over multiple threads
  * multiple threads.
  * 
  * @author Ryan Hechenberger
  */

// Default build command: g++ -O3 -std=c++11 -o test -pthread palindrome_test.cc

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

// use to seed random number generators before calling runNextCase()
mt19937 seeder;

// called before any cases are loaded, you may modify it
// returns the number of test cases there are, or -1 if
// the end case is not expressly given
int pre_initialize()
{
	int T;
	cin >> T;
	return T;
}

// called after all cases have completed and all threads have closed
// print anything extra needed
// returns what the program code should be (0 is success, otherwise failure)
int post_finalize()
{
	return 0;
}

class Solver
{
	friend class CaseThread;
	unique_lock<mutex>* mReadUnlock_;
	int mCaseNo_;
public:
	using random_type = mt19937; // add _64 for 64-bit generators
	random_type rand;
	ostringstream cout;
	int printf(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		char *out = nullptr;
		int ret = vasprintf(&out, format, args);
		va_end (args);
		cout << out;
		free(out);
		return ret;
	}
private:
	// set last to true to indicate that this is the final case
	// DO NOT MODIFY
	void runNextCase()
	{
		//cerr << (to_string(mReadAccess->load()) + ' ' + to_string(mID) + '\n');
		mReadUnlock_->unlock();
	}
	
	// feel free to initialize variables hree, but do not add extra parameters
	Solver(unique_lock<mutex>& readUnlock, int id) : mReadUnlock_(&readUnlock), mCaseNo_(id)
	{
		// random number generator, seeds this thread random number generator
		// to use it, just call rand()
		array<int, random_type::word_size * random_type::state_size / 32> seedval;
		generate(seedval.begin(), seedval.end(), ref(seeder));
		seed_seq seq(seedval.begin(), seedval.end());
		rand.seed(seq);
	}
	
public:
	// DO NOT MODIFY
	int getCaseID() const
	{
		return mCaseNo_;
	}
	
	int A, B, C, K;
	map<pii, int> gr[3];
	vector<tuple<int,int,int>> res;
	vector<tuple<int,int,int>> best;
	
	bool canAdd(int a, int b, int c) {
		return gr[0][pii(a,b)] < K && gr[1][pii(a,c)] < K && gr[2][pii(b,c)] < K;
	}
	void push(int a, int b, int c) {
		gr[0][pii(a,b)]++;
		gr[1][pii(a,c)]++;
		gr[2][pii(b,c)]++;
		res.emplace_back(a,b,c);
		if (res.size() > best.size()) {
			best = res;
		}
	}
	void pop() {
		int a, b, c;
		tie(a,b,c) = res.back(); res.pop_back();
		gr[0][pii(a,b)]--;
		gr[1][pii(a,c)]--;
		gr[2][pii(b,c)]--;
	}
	
	void recurse(int a, int b, int c)
	{
		for ( ; a <= A; ++a, b = 1)
		for ( ; b <= B; ++b, c = 1)
		for ( ; c <= C; ++c) {
			if (canAdd(a, b, c)) {
				push(a,b,c);
				recurse(a,b,c+1);
				pop();
			}
		}
	}
	
	// main code for your problem, BE CAREFUL when using the global space
	void solve()
	{
		// add reading in from stdin/cin
		cin >> A >> B >> C >> K;
		runNextCase(); // do not call on last test case, do not call multiple times
		
		recurse(1,1,1);
		printf("Case #%d: %d\n", getCaseID()+1, (int)best.size());
		for (auto r : best) {
			int x, y, z;
			tie(x, y, z) = r;
			printf("%d %d %d\n", x, y, z);
		}
	}
};


/**
  * The beginning of the controller for each case
  * DO NOT MODIFY PAST THIS POINT
  */

class CaseThread
{
public:
	static unsigned sMaxCases; /// maximum number of test cases
private:
	static int sReadCase; /// the next case number to test
	static int sWriteCase;
	static mutex sReadMutex; /// the mutex for the reading cond-var
	static mutex sWriteMutex; /// used by main for the write cond-var
	static unordered_map<int, string> sOutput; /// buffers the output for each case, enable correct ordering

public:
	CaseThread()
	{ }
	
	void observe()
	{
		unique_ptr<Solver> solver(nullptr);
		while (true) {
			unique_lock<mutex> reader(sReadMutex);
			if ((unsigned)sReadCase >= sMaxCases)
				break;
			int id = sReadCase++;
			solver.reset(new Solver(reader, id));
			solver->solve();
			if (reader.owns_lock()) {
				sReadCase = -1;
				reader.unlock();
			}
			
			lock_guard<mutex> writelck(sWriteMutex);
			sOutput.emplace(id, move(solver->cout.str()));
			for (auto it = sOutput.find(sWriteCase); it != sOutput.end(); it = sOutput.find(++sWriteCase)) {
				cout << it->second;
				sOutput.erase(it);
			}
		}
	}
};

unsigned CaseThread::sMaxCases = UINT_MAX;
int CaseThread::sReadCase = 0;
int CaseThread::sWriteCase = 0;
mutex CaseThread::sReadMutex;
mutex CaseThread::sWriteMutex;
unordered_map<int, string> CaseThread::sOutput(512);

struct OutputCombo
{
	static ofstream cout;
	static int printf(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		char *out = nullptr;
		int ret = vasprintf(&out, format, args);
		va_end (args);
		cout << out;
		free(out);
		return ret;
	}
};
ofstream OutputCombo::cout;

int main(int argc, char** argv)
{
	int cores = 2 * thread::hardware_concurrency();
	if (cores == 0) cores = 2;
	mt19937 seed(chrono::high_resolution_clock::now().time_since_epoch().count());
	array<int, mt19937::state_size> seedval;
	generate(seedval.begin(), seedval.end(), ref(seed));
	seed_seq seq(seedval.begin(), seedval.end());
	seeder.seed(seq);
	
	int mt = pre_initialize();
	CaseThread::sMaxCases = (unsigned)mt;
	
	vector<unique_ptr<CaseThread>> process;
	vector<thread> threads;
	for (int i = 0; i < cores; ++i) {
		process.emplace_back();
		threads.emplace_back(&CaseThread::observe, ref(*process.back()));
	}
	
	for (auto& thr : threads) {
		thr.join();
	}
	
	int ret = post_finalize();
	return ret;
}
