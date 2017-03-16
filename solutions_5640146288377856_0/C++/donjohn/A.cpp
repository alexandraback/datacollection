#include<iostream>
#include<string>
#include<cstdio>
#include<limits>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define SMALL
//#define LARGE



int main()
{


	#ifdef SMALL
		freopen("A-small-attempt1.in","rt",stdin);
		freopen("A-small.out","wt",stdout);
	#endif

	#ifdef LARGE
		freopen("A-large.in","rt",stdin);
		freopen("A-large.out","wt",stdout);
	#endif

	int i,t;
	cin>>t;
	
	for(i=1;i<=t;i++)
	{
		long long int ans=0,r,c,w;
		cin>>r>>c>>w;
		ans = (r - 1) * (c / w);
		ans += (c-1)/w + w;
		cout<<"Case #"<<i<<": "<<ans <<endl;
	}
	
	return 0;
}
