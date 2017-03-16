#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

#pragma comment(linker, "/STACK:16777216")

typedef long long int64;
typedef unsigned long long uint64;

bool m[2000];
string sx[2000], sy[2000];

int main()
{
	int t;
	cin>>t;

	for (int tt = 1; tt <= t; tt++)
	{
		int n;
		cin>>n;

		map<string, int> A, B;
		A.clear();
		for (int i = 0; i < n; i++)
		{
			string x,y;
			cin>>x>>y;
			sx[i] = x;
			sy[i] = y;
			A[x]++;
			B[y]++;
		}

		int res = 0;
		memset(m, 0, sizeof(m));

		set<string> aa, bb;
		for (int i = 0; i < n; i++)
		{
			//cout<<sx[i]<<" "<<sy[i]<<endl;
			if ((A[sx[i]] > 1) and (B[sy[i]] > 1))
			{
				res++;
			}
		}
		
		cout<<"Case #"<<tt<<": "<<res<<endl;
	}
	return 0;
}