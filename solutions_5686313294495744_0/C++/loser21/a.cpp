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
#define MAXL 18
#define pii pair<int,int>
#define vpi vector< pair<int,int> >
#define vvpi vector< vector<pair<int,int>> >
#define pi acos(-1)
#define eps 1e-8

using namespace std;



#define maxn 1009


int main()
{
	int t;
	icin(t);

	for(int tc=1;tc<=t;tc++)
	{
		
		int ans = 0;


		int mr[maxn],mc[maxn];
		int canr[maxn],canc[maxn];

		memset(canr,0,sizeof(canr));
		memset(canc,0,sizeof(canc));
		memset(mr,-1,sizeof(mr));
		memset(mc,-1,sizeof(mc));

		int n;
		icin(n);


	
		int c1=1,c2=1;
		map<string,int> m1,m2;
		for(int i=0;i<n;i++)
		{
			string s1,s2;
			cin >> s1 >> s2;
			if(m1[s1]==0)
				m1[s1]=c1++;
			if(m2[s2]==0)
				m2[s2]=c2++;
			if(mr[m1[s1]]==-1 && mc[m2[s2]]==-1)
			{
				mr[m1[s1]]=0;
				mc[m2[s2]]=0;
			}
			else if(mr[m1[s1]]==0 && mc[m2[s2]]==0)
				ans++;
			else if(mr[m1[s1]]==0)
				canr[m1[s1]]++;
			else
				canc[m2[s2]]++;	
		}
		for(int i=1;i<=n;i++)
		{
			if(canr[i]>0)
			ans += canr[i]-1;
			if(canc[i]>0)
			ans +- canc[i]-1;
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}