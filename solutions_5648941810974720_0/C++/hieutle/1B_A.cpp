#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

#pragma comment(linker, "/STACK:16777216")

typedef long long int64;
typedef unsigned long long uint64;

int t[10];
int cnt[30];

int main()
{
	int tttt;
	cin>>tttt;

	for (int tt = 1; tt <= tttt; tt++)
	{
		string s;
		cin>>s;

		memset(cnt,0,sizeof(cnt));
		for (int i = 0; i < s.length(); i++) 
			cnt[s[i]-65]++;

		memset(t, 0, sizeof(t));
		t[0] = cnt['Z'-65];
		t[2] = cnt['W'-65];
		t[4] = cnt['U'-65];
		t[3] = cnt['R'-65] - t[0] - t[4];
		t[1] = cnt['O'-65] - t[0] - t[2] - t[4];
		t[5] = cnt['F'-65] - t[4];
		t[6] = cnt['X'-65];
		t[7] = cnt['V'-65] - t[5];
		t[8] = cnt['T'-65] - t[2] - t[3];
		t[9] = cnt['I'-65] - t[5] - t[6] - t[8];

		cout<<"Case #"<<tt<<": ";
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j < t[i]; j++) cout<<i;
		cout<<endl;
	}
	return 0;
}