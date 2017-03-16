#include<bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define rep(i,in1,n) for(i=in1;i<=n;i++)
#define repd(i,in1,n) for(i=in1;i>=n;i--)

#define pf(n) printf("%d ",n);
#define sf(n) scanf("%d",&n)
#define sl(n) scanf("%I64d",&n)
#define nl printf("\n")
#define mem(arr,init) memset(arr,init,sizeof(arr))
#define vi vector<int>
#define vvi vector<vi>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp make_pair
#define ep emplace_back//c++11
#define ii pair<int,int>
#define iii pair<ii,i>
//	freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
using namespace std;
string s1,s2;
map<string,int> map1,map2;
vector<string> v1,v2;

map<string,int> mark1,mark2;


int main()
{
	int i,j,k,t,n,m,a,b,c,x,y,z,cs;
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
	for(cs=1;cs<=t;cs++)
	{
		cin>>n;
		map1.clear(); map2.clear();
		v1.clear(); 	v2.clear();
		for(i=1;i<=n;i++)
		{
			cin>>s1>>s2;
			map1[s1]++;
			map2[s2]++;
			v1.pb(s1);
			v2.pb(s2);
		}
		int ans=0;
		for(i=0;i<n;i++)
		{
			if(map1[v1[i]]<2 || map2[v2[i]]<2)
			{
				mark1[v1[i]]++;
				mark2[v2[i]]++;
			//	map1[v1[i]]-=2;
			//	map2[v2[i]]-=2;
				
			}
			
		}
		
		for(i=0;i<n;i++)
		{
			if(mark1.find(v1[i])!=mark1.end() && mark2.find(v2[i])!=mark2.end() && map1[v1[i]]>=2 && map2[v2[i]]>=2)
			{
				ans++;
			//	map1[v1[i]]-=2;
			//	map2[v2[i]]-=2;
				
			}
			mark1[v1[i]]++;
			mark2[v2[i]]++;
		}
		printf("Case #%d: %d",cs,ans);
		nl;
		
	}
    



	return 0;
}



