#include<iostream>
#include<algorithm>
#include<functional>
#include <vector>
using namespace std;
#define MAXN 101
int T, N, S, p;
vector<int> t(MAXN,0);
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	cin>>T;
	for(int te=1;te<=T;te++)
	{
		cin>>N>>S>>p;
		for (int i=0;i<N;i++)
			cin>>t[i];
		sort(t.begin(), t.begin()+N, greater<int>());
		int ans = 0;
		for(int i=0;i<N;++i)
		{
			if(t[i]<3*p-4)
				break;
			if(t[i]/3>=p)
				ans++;
			else
			if(p>=1 && t[i]>=max(3*p-2, 0))
				ans++;
			else
			if(p>=2 && S>0)
			{
				S--;
				ans++;
			}
		}
		printf("Case #%d: %d\n", te, ans);
	}
	return 0;
}
