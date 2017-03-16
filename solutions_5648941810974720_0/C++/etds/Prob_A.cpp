
#define PROBLEM_NAME "A"
#define PROBLEM_SMALL_INPUT "-small-attempt0"
#define PROBLEM_LARGE_INPUT "-large"

#include <list>
#include <set>

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
		string S;
		fin >> S;

		multiset<char> ms;
		for (size_t i=0; i<S.length(); ++i)
		{
			char ch = S[i];
			ms.insert(ch);
		}

		multiset<int> numbers;
		while (!ms.empty())
		{
			if (ms.find('Z') != ms.end())
			{
				ms.erase(ms.find('Z'));
				ms.erase(ms.find('E'));
				ms.erase(ms.find('R'));
				ms.erase(ms.find('O'));
				numbers.insert(0);
				continue;
			}

			if (ms.find('W') != ms.end())
			{
				ms.erase(ms.find('T'));
				ms.erase(ms.find('W'));
				ms.erase(ms.find('O'));
				numbers.insert(2);
				continue;
			}
			if (ms.find('U') != ms.end())
			{
				ms.erase(ms.find('F'));
				ms.erase(ms.find('O'));
				ms.erase(ms.find('U'));
				ms.erase(ms.find('R'));
				numbers.insert(4);
				continue;
			}
			if (ms.find('X') != ms.end())
			{
				ms.erase(ms.find('S'));
				ms.erase(ms.find('I'));
				ms.erase(ms.find('X'));
				numbers.insert(6);
				continue;
			}
			//if (ms.find('V') != ms.end())
			//{
			//	ms.erase('S');
			//	ms.erase('E');
			//	ms.erase('V');
			//	ms.erase('E');
			//	ms.erase('N');
			//	numbers.insert(7);
			//	continue;
			//}
			if (ms.find('G') != ms.end())
			{
				ms.erase(ms.find('E'));
				ms.erase(ms.find('I'));
				ms.erase(ms.find('G'));
				ms.erase(ms.find('H'));
				ms.erase(ms.find('T'));
				numbers.insert(8);
				continue;
			}
			break;
		}

		// 1, 3, 5, 7, 9

		while (!ms.empty())
		{
			if (ms.find('O') != ms.end() && ms.find('N') != ms.end() && ms.find('E') != ms.end())
			{
				ms.erase(ms.find('O'));
				ms.erase(ms.find('N'));
				ms.erase(ms.find('E'));
				numbers.insert(1);
				continue;
			}
			if (ms.find('F') != ms.end() && ms.find('I') != ms.end() && ms.find('V') != ms.end() && ms.find('E') != ms.end())
			{
				ms.erase(ms.find('F'));
				ms.erase(ms.find('I'));
				ms.erase(ms.find('V'));
				ms.erase(ms.find('E'));
				numbers.insert(5);
				continue;
			}
			break;
		}

		// 3, 7, 9
		while (!ms.empty())
		{
			if (ms.find('T') != ms.end())
			{
				ms.erase(ms.find('T'));
				ms.erase(ms.find('H'));
				ms.erase(ms.find('R'));
				ms.erase(ms.find('E'));
				ms.erase(ms.find('E'));
				numbers.insert(3);
				continue;
			}
			if (ms.find('V') != ms.end())
			{
				ms.erase(ms.find('S'));
				ms.erase(ms.find('E'));
				ms.erase(ms.find('V'));
				ms.erase(ms.find('E'));
				ms.erase(ms.find('N'));
				numbers.insert(7);
				continue;
			}
			if (ms.find('I') != ms.end())
			{
				ms.erase(ms.find('N'));
				ms.erase(ms.find('I'));
				ms.erase(ms.find('N'));
				ms.erase(ms.find('E'));
				numbers.insert(9);
				continue;
			}
			break;
		}

		fout << "Case #" << cases << ": ";

		for (multiset<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		{
			fout << (*it);
		}
		fout << endl;
	}

	return 0;
}
