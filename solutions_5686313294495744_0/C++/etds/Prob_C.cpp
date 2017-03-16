
#define PROBLEM_NAME "C"
#define PROBLEM_SMALL_INPUT "-small-attempt3"
#define PROBLEM_LARGE_INPUT "-large"

#include <set>
#include <vector>

using namespace std;


int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in");
	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in", PROBLEM_NAME PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in", PROBLEM_NAME PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		int N;
		fin >> N;

		typedef pair<string, string> topic;
		list<topic> topics;

		multiset<string> key1, key2;

		for (int i=0; i<N; ++i)
		{
			string a, b;
			fin >> a >> b;
			topics.push_back(make_pair(a, b));
			key1.insert(a);
			key2.insert(b);
		}

		list<topic> uniques;
		set<string> uniquekey1, uniquekey2;

		list<topic>::iterator it = topics.begin();
		while (it != topics.end())
		{
			topic& t = (*it);
			if (key1.count(t.first) == 1 || key2.count(t.second) == 1)
			{
				uniques.push_back(t);
				uniquekey1.insert(t.first);
				uniquekey2.insert(t.second);
				it = topics.erase(it);
			}
			else
			{
				++it;
			}
		}

		list<topic> fakes;

		it = topics.begin();
		while (it != topics.end())
		{
			topic& t = (*it);
			if (uniquekey1.find(t.first) != uniquekey1.end() && uniquekey2.find(t.second) != uniquekey2.end())
			{
				fakes.push_back(t);
				it = topics.erase(it);
			}
			else
			{
				++it;
			}
		}

		it = topics.begin();
		while (it != topics.end())
		{
			topic& t = (*it);
			if (uniquekey1.find(t.first) == uniquekey1.end() && uniquekey2.find(t.second) == uniquekey2.end())
			{
				uniques.push_back(t);
				uniquekey1.insert(t.first);
				uniquekey2.insert(t.second);
				it = topics.erase(it);
			}
			else
			{
				++it;
			}
		}

		it = topics.begin();
		while (it != topics.end())
		{
			topic& t = (*it);
			if (uniquekey1.find(t.first) == uniquekey1.end())
			{
				uniques.push_back(t);
				uniquekey1.insert(t.first);
				uniquekey2.insert(t.second);
				it = topics.erase(it);
			}
			else if (uniquekey2.find(t.second) == uniquekey2.end())
			{
				uniques.push_back(t);
				uniquekey1.insert(t.first);
				uniquekey2.insert(t.second);
				it = topics.erase(it);
			}
			else
			{
				++it;
			}
		}

		fout << "Case #" << cases << ": " << (fakes.size() + topics.size()) << endl;
	}

	return 0;
}
