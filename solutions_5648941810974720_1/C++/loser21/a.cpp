#include <bits/stdc++.h>
 
 
 
#define icin(x) scanf("%d",&x)
#define lcin(x) scanf("%lld",&x)
#define LL long long
#define F first
#define S second
#define pb push_back
#define mod (LL)(1e9+7)
#define LL long long
#define VVI vector< vector<int> >
#define maxn 1000100
#define MAXL 18
#define pii pair<int,int>
#define vpi vector< pair<int,int> >
#define vvpi vector< vector<pair<int,int>> >
#define pi acos(-1)
#define eps 1e-8

using namespace std;



int main()
{
	int t;
	icin(t);
	int x=0;
	while(t--)
	{
		x++;
		string S;
		cin >> S;
		int ar[26];
		for(int i=0;i<=25;i++)
			ar[i]=0;
		for(int i=0;i<S.length();i++)
			ar[S[i]-'A']++;
		int num[10];
		for(int i=0;i<=9;i++)
			num[i]=0;
		num[0] += ar['Z'-'A'];
		ar['E'-'A'] -= num[0];
		ar['R'-'A'] -= num[0];
		ar['O'-'A'] -= num[0];
		//cout << "HERE" << endl;
		num[2] += ar['W'-'A'];
		ar['T'-'A'] -= num[2];
		ar['O'-'A'] -= num[2];
		num[4] += ar['U'-'A'];
		ar['F'-'A'] -= num[4];
		ar['O'-'A'] -= num[4];
		ar['R'-'A'] -= num[4];
		num[1] += ar['O'-'A'];
		ar['N'-'A'] -= num[1];
		ar['E'-'A'] -= num[1];
		num[5] += ar['F'-'A'];
		ar['I'-'A'] -= num[5];
		ar['V'-'A'] -= num[5];
		ar['E'-'A'] -= num[5];
		num[7] += ar['V'-'A'];
		ar['S'-'A'] -= num[7];
		ar['N'-'A'] -= num[7];
		ar['E'-'A'] -= 2*num[7];
		num[6] += ar['S'-'A'];
		ar['I'-'A'] -= num[6];
		ar['X'-'A'] -= num[6];
		num[9] += ar['N'-'A']/2;
		ar['I'-'A'] -= num[9];
		ar['E'-'A'] -= num[9];
		num[3] += ar['R'-'A'];
		ar['H'-'A'] -= num[3];
		ar['T'-'A'] -= num[3];
		ar['E'-'A'] -= 2*num[3];
		//cout << "HERE" << endl;
		num[8] += ar['I'-'A'];
		//cout << "HERE" << endl;
		string ans;
		for(int i=0;i<=9;i++)
		{
		//	cout << num[i] << " " << endl;
			for(int j=1;j<=num[i];j++)
			{
		//		cout << i << endl;
				ans += (char)(i + '0');
			}
		}
		cout << "Case #" << x << ": " << ans << endl;
	}
}