#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ans[100];
int h[1000];

ifstream fin("b.in");
ofstream fout("ans.txt");
#define cin fin
#define cout fout

int main()
{
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++)
	{
		memset(ans, 0, sizeof(ans));
		memset(h, 0, sizeof(h));
		string s;
		cin>>s;
		cout<<"Case #"<<t<<": ";
		
		for(int i = 0; i <= s.length(); i++)
		h[s[i]]++;
		
		ans[0]=h['Z'];
		ans[2]=h['W'];
		ans[4]=h['U'];
		ans[1]=h['O']-ans[0]-ans[4]-ans[2];
		ans[5]=h['F']-ans[4];
		ans[7]=h['V']-ans[5];
		ans[8]=h['G'];
		ans[6]=h['X'];
		ans[3]=h['R']-ans[0]-ans[4];
		ans[9]=h['I']-ans[5]-ans[6]-ans[8];
		
		for(int i = 0; i <= 9; i++)
		{
			for(int j = 0; j < ans[i]; j++)
			cout<<i;
		}
		cout<<endl;
	}
	
	
	return 0;
}
//zero, one, two, three, four, five, six, seven, eight, nine
/*
4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER
*/

