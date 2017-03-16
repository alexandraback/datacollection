#include <cstdlib>
#include <fstream>
#include <sstream>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;
int main(int argc, char* argv[])
{
	string inputFileName = "C-small-attempt2.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T, L, X;
	char buf[10010];
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> L >> X;
		input >> buf;
		char ch = '1';
		bool sign = true, flag[] = { false, false };
		for (int more = 0; more < X; ++more)
		{
			for (int j = 0; j < L; ++j)
			{
				if (ch == '1')
				{
					ch = buf[j];
				}
				else if (ch == buf[j])
				{
					sign = !sign;
					ch = '1';
				}
				else
				{
					int tmp = int('i') + 'j' + 'k' - ch - buf[j];
					if (ch == 'i' && buf[j] == 'j'
						|| ch == 'j' && buf[j] == 'k'
						|| ch == 'k' && buf[j] == 'i')
					{

					}
					else
					{
						sign = !sign;
					}
					ch = tmp;
				}
				if (!flag[0])
				{
					if (sign && ch == 'i')
					{
						flag[0] = true;
						ch = '1';
					}
				}
				else if (!flag[1])
				{
					if (sign && ch == 'j')
					{
						flag[1] = true;
						ch = '1';
					}
				}
			}
		}
		if (flag[0] && flag[1] && sign && ch == 'k')
		{
			output << "Case #" << i << ": " << "YES" << endl;
		}
		else
		{
			output << "Case #" << i << ": " << "NO" << endl;
		}
		/*
		bool valid = false, flag[256];
		memset(flag, 0, sizeof(flag));
		bool sign = true, firstSign;
		char ch = '1', firstCH;
		for (int more = 0; !valid && more < MIN(2, X); ++more)
		{
			for (int j = 0; j < L; ++j)
			{
				flag[buf[j]] = true;
				if (ch == '1')
				{
					ch = buf[j];
				}
				else if (ch == buf[j])
				{
					sign = !sign;
					ch = '1';
				}
				else
				{
					int tmp = int('i') + 'j' + 'k' - ch - buf[j];
					if (ch == 'i' && buf[j] == 'j'
						|| ch == 'j' && buf[j] == 'k'
						|| ch == 'k' && buf[j] == 'i')
					{

					}
					else
					{
						sign = !sign;
					}
					ch = tmp;
				}
				if (sign && ch == 'i')
				{
					valid = true;
				}
			}
			if (more == 0)
			{
				firstSign = sign;
				firstCH = ch;
			}
		}

		if (!firstSign)
		{
			if (!(X % 2))
			{
				firstSign = true;
			}
		}
		if (firstCH != '1')
		{
			if (X % 2)
			{
				if (((X - 1) / 2) % 2)
				{
					firstSign = !firstSign;
				}
			}
			else
			{
				if ((X / 2) % 2)
				{
					firstSign = !firstSign;
				}
				firstCH = '1';
			}
		}

		if (firstCH == '1' && !firstSign)
		{
			if (valid && (int(flag['i']) + flag['j'] + flag['k']) > 1)
			{
				output << "Case #" << i << ": " << "YES" << endl;
			}
			else
			{
				output << "Case #" << i << ": " << "NO" << endl;
			}
		}
		else
		{
			output << "Case #" << i << ": " << "NO" << endl;
		}
		*/
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
