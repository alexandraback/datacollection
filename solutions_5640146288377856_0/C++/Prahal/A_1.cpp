#include <fstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

#define MAX_N 10000000

using namespace std;

ifstream fin("D:\\Input.txt");
ofstream fout("D:\\Output.txt");

int T, R, C, W, answer;

int main(int argc, const char* argv[])
{
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		R = C = answer = 0;
		fin >> R >> C >> W;
		answer += W;
		if(C > W)
			answer += C / W - (C % W == 0 ? 1 : 0);
		answer *= R;
		fout << "Case #" << i + 1 << ": " << answer << "\n";
	}
	return 0;
}