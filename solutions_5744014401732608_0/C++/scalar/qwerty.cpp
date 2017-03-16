#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <thread>
#include <sstream>
#include <mutex>
#include <queue>
using namespace std;

#pragma region unused

class GCJSolverBase
{
public:
	GCJSolverBase(std::istream &a_cin)
		: cin(a_cin)
	{
	}

	void readData(int currentTest)
	{
		mTestNumber = currentTest;
		readTest();
	}

	std::string result()
	{
		cout << "Case #" << mTestNumber << ": ";
		solve();
		return cout.str();
	}

	std::string ans() const
	{
		auto s = cans.str();
		if (s.empty()) return "";
		std::ostringstream os;
		os << "Case #" << mTestNumber << ": ";
		return os.str() + s;
	}
protected:
	std::istream &cin;
	std::ostringstream cout;
	std::ostringstream cans;
	int mTestNumber;

	virtual void readTest() = 0;
	virtual void solve() = 0;
};

#pragma endregion

void init_global()
{
}

void init_thread_local()
{
	
}

class GCJSolver : public GCJSolverBase
{
public:
	GCJSolver(std::istream &cin)
		: GCJSolverBase(cin)
	{

	}

private:
	int b;
	typedef long long int lint;
	lint m;

	void readTest() override
	{
		cin >> b >> m;
	}

	void solve() override
	{
		lint max = 1ll << (b - 2);
		if (max < m)
		{
			cout << "IMPOSSIBLE";
			return;
		}
		cout << "POSSIBLE\n";
		for (int i = 0; i < b - 1; ++i)
		{
			for (int j = 0; j < b - 1; ++j)
			{
				if (i < j) cout << 1;
				else cout << 0;
			}
			if (m == max || i != 0 && ((1ll << (i - 1)) & m)) cout << 1;
			else cout << 0;
			cout << '\n';
		}
		for (int i = 0; i < b; ++i) cout << 0;
	}
};

#pragma region unused

void thread_func(volatile int &current_test, int maxTest, std::vector<std::string> &result, std::istream &cin)
{
	init_thread_local();
	while (1)
	{
		GCJSolver s(cin);
		int cur;
		{
			static std::mutex sInputMutex;
			std::lock_guard<std::mutex> lock(sInputMutex);
			if (current_test > maxTest) break;
			s.readData(current_test);
			cur = current_test;
			++current_test;
		}
		result[cur - 1] = s.result();
	}
}

int main()
{
	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");
	std::ofstream cans("output.txt");

	int totalTests;
	cin >> totalTests;
	init_global();
	std::vector<std::thread> vt;
	int currentTest = 1;
	std::vector<std::string> vs(totalTests);
	for (size_t i = 0; i != std::thread::hardware_concurrency(); ++i)
	{
		vt.push_back(std::thread(std::bind(thread_func, std::ref(currentTest), totalTests, std::ref(vs), std::ref(cin))));
	}
	for (auto &x : vt) x.join();
	for (auto s : vs) cout << s << '\n';
}

#pragma endregion
