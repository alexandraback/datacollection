#include<iostream>
#include<vector>
#include<fstream>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int T, R, C, W;
	ifstream in ("input.txt");
	ofstream out("output.txt");
	in >> T;
	for (int i = 1; i <= T; i++){
		in >> R >> C >> W;
		int rest = R - 1;
		int score = 0;
		int each = C / W;
		
		/*score += R*each;
		int delta = C%W;
		score += delta + W - 1;*/


		if (C%W == 0)
		{
			score += R*each;
			score += W - 1;
		}
		else
		{
			score += rest*each;
			score += each - 1;
			score += W + 1;
		}
		


		cout << "Case #" << i << ": " << score << endl;
		out << "Case #" << i << ": " << score << endl;
	}



	in.close();
	out.close();
}