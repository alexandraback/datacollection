#include <fstream>
#include <algorithm>

#define MAX_N 1000000000

using namespace std;

ifstream fin("D:\\Input.txt");
ofstream fout("D:\\Output.txt");

int T, N, answer, h, p_1, s_1, p_2, s_2;

int main(int argc, const char* argv[])
{
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		fin >> N;
		answer = 0;
		h = 0;
		p_1 = s_1 = p_2 = s_2 = -1;
		int a, b, c;
		for(int j = 0; j < N; j++)
		{
			fin >> a >> b >> c;
			h += b;
			if(b == 1)
				if(p_1 == -1)
					p_1 = a, s_1 = c;
				else
					p_2 = a, s_2 = c;
			else
				p_1 = a, s_1 = c, p_2 = a, s_2 = c + 1;
		}
		if(h == 1)
		{
			answer = 0;
			fout << "Case #" << i + 1 << ": " << answer << "\n";
		}
		else
		{
			if(s_1 == s_2)
			{
				answer = 0;
				fout << "Case #" << i + 1 << ": " << answer << "\n";
			}
			else
			{
				double t_1 = (float)s_1 * (float)((float) 360 - p_1) / (float)360, t_2 = (float)s_2 * (float)((float)360 - p_2) / (float)360;
				if(t_1 + (double)s_1 <= t_2)
					answer = 1;
				if(t_2 + (double)s_2 <= t_1)
					answer = 1;
				else
					answer = 0;
				fout << "Case #" << i + 1 << ": " << answer << "\n";
			}
		}
	}
	return 0;
}