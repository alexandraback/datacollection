#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

string V[11] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main(void)
{
	string S;
	cin >> S;
	vector<int> alpha(27), alphb(27);
	for(int i = 0;i < int(S.size());i++) alpha[int(S[i]-'A')]++;

	for(int i = 0;i < 10;i++)
	{
		int tmp = 1707050900;
		alphb.clear(); alphb.resize(27);
		for(int j = 0;j < int(V[i].size());j++) alphb[int(V[i][j]-'A')]++;

		for(int j = 0;j < 27;j++) if(alphb[j]) tmp = min(tmp, alpha[j]/alphb[j]);

		for(int j = 0;j < 27;j++) if(alphb[j]) alpha[j] = int(alpha[j]/alphb[j])*tmp;
		cout << i << " " << tmp << "\n";
		//for(int j = 0;j < tmp;j++) cout << i;
	}
}