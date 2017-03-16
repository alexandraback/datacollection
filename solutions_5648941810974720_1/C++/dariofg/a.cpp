#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int I=0;I<T;I++)
	{
		string s;
		cin >> s;
		cout << "Case #" << I+1 << ": ";
		vector<int> frec(256);
		for(int i=0;i<s.size();i++)
			frec[s[i]]++;
		vector<int> frecnum(10);
		frecnum[0] = frec['Z'];
		frecnum[2] = frec['W'];
		frecnum[4] = frec['U'];
		frecnum[6] = frec['X'];
		frecnum[8] = frec['G'];
		frecnum[1] = frec['O']-frecnum[0]-frecnum[2]-frecnum[4];
		frecnum[3] = frec['H']-frecnum[8];
		frecnum[5] = frec['F']-frecnum[4];
		frecnum[7] = frec['V']-frecnum[5];
		frecnum[9] = frec['I']-frecnum[5]-frecnum[6]-frecnum[8];
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<frecnum[i];j++)
				cout << i;
		}
		cout << endl;
	}
}
