#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL
#define ll long long

int main()
{
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;++tc)
	{
		int n;
		cin >> n;
		string A[n][2];
		for(int i=0;i<n;++i)
			cin >> A[i][0] >> A[i][1];
		int res = 0;
		for(int i=0;i<(1<<n);++i)
		{
			set<string> F, S;
			for(int j=0;j<n;++j)
				if(i&(1<<j))
				{
					F.insert(A[j][0]);
					S.insert(A[j][1]);
				}
			bool possible = true;
			for(int i=0;i<n;++i)
			{
				if(!F.count(A[i][0]))
					possible = false;
				if(!S.count(A[i][1]))
					possible = false;
			}
			if(possible)
				res = max(res,n-__builtin_popcount(i));
		}
		cout << "Case #" << tc << ": " << res << endl;
	}
	return 0;
}
