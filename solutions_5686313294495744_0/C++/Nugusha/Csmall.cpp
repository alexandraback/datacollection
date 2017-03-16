// __   _   _   _   _____   _   _   _____   _   _       ___
//|  \ | | | | | | /  ___| | | | | /  ___/ | | | |     /   |
//|   \| | | | | | | |     | | | | | |___  | |_| |    / /| |
//| |\   | | | | | | |  _  | | | | \___  \ |  _  |   / / | |
//| | \  | | |_| | | |_| | | |_| |  ___| | | | | |  / /  | |
//|_|  \_| \_____/ \_____/ \_____/ /_____/ |_| |_| /_/   |_|

#include<bits/stdc++.h>
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define fi first
#define se second
#define ll long long
#define pii pair< int, int >
#define MEM(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define R return(0)
#define INF int(1e9)
#define MAX_5 int(1e5+5)
#define MAX_6 int(1e6+6)
#define ll long long
#define tree int h,int l1,int r1
#define left 2*h,l1,(l1+r1)/2
#define right 2*h+1,(l1+r1)/2+1,r1
using namespace std;
int a[1005],n;
string s1[1050],s2[1005];
	pair<string,string> S[100005];
	pair<string,string> S1[10005];
int sol()
{
	
	for(int i=0;i<n;i++)a[i]=i;
	
		map<string,int>m1,m2;
		
		
	for(int i=0;i<n;i++)
	{
		m1[s1[i]]++;
		m2[s2[i]]++;
	}
	int N=0,NN=0;
	
	
	for(int i=0;i<n;i++)
	 if(m1[s1[i]]==1 || m2[s2[i]]==1)
	 	S1[NN++]=MP(s1[i],s2[i]);else
	 	S[N++]=MP(s1[i],s2[i]);
	 	
	 	sort(S1,S1+NN);
	 	
	 	m1.clear();
	 	m2.clear();
	 	
	 	int ans=0;
	 	
//	for(int i=0;i<NN;i++)cout<<S1[i].fi<<"-"<<S1[i].se<<endl;
//	for(int i=0;i<N;i++)cout<<S[i].fi<<"-"<<S[i].se<<endl;
	
	
	for(int i=0;i<NN;i++)
	{
		if(m1[S1[i].fi] && m2[S1[i].se])ans++;
		m1[S1[i].fi]=1;
		m2[S1[i].se]=1;		
	}
	 	
	for(int i=0;i<N;i++)
	{
		if(m1[S[i].fi] && m2[S[i].se])ans++;
		m1[S[i].fi]=1;
		m2[S[i].se]=1;
	}
	 	
	
	
	return ans;
	
}
main()
{

       READ("a.in");WRITE("a.out");
          int tt;
		  cin>>tt;
          for(int q=0;q<tt;q++)
		  {
		  	cin>>n;
		  	for(int i=0;i<n;i++)cin>>s1[i]>>s2[i];
			cout<<"Case #"<<q+1<<": ";
			cout<<sol()<<endl;
		  }

}
