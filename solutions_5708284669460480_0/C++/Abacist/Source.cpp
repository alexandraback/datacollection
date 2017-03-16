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

int maxFix(char * pat, int size)
{
	int * next = new int[size + 1];
	next[0] = 0;
	next[1] = 0;
	int longest = 0;
	for (int i = 2; i <= size; i++){
		while (longest > 0 && pat[longest] != pat[i - 1])
			longest = next[longest];
		if (pat[longest] == pat[i - 1])
			longest++;
		next[i] = longest;
	}
	return next[size];
}


int main()
{
	int T, K, L, S;
	ifstream in ("input.txt");
	ofstream out("output.txt");
	in >> T;
	for (int i = 1; i <= T; i++){
		in >> K >> L >> S;
		int ab[26]{0};
		for (int j = 0; j < K; j++){
			char temp;
			in >> temp;
			ab[temp - 'A'] ++;
		}
		char* pat = new char[L];
		for (int j = 0; j < L; j++){
			in >> pat[j];
		}
		double p = 1.0;
		for (int j = 0; j < L; j++){
			p = p*((double)ab[pat[j] - 'A'] / K);
		}
		double result;
		if (p == 0 || p == 1)
		{
			result = 0;
		}
		else
		{
			/*double maxTime = S - L + 1;
			double maxOccur = S / L;
			result = maxOccur * (1 - p);*/
			int fix = maxFix(pat, L);
			int maxOccur = 1 + (double)(S - L) / (L - fix);
			result = (double)maxOccur - (1+S-L)*p;
		}
		

		cout.precision(10);
		out.precision(10);
		cout << "Case #" << i << ": " << result << endl;
		out << "Case #" << i << ": " << result << endl;
	}



	in.close();
	out.close();
}