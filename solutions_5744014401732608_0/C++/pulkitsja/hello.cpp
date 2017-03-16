#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define mp make_pair
#define f first
#define s second
#define maxn 1000100
#define sz(x) x.size()
typedef pair <int,char> pp;
int mat[60][60];
int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for (int T = 1; T <= t; ++T)
	{   printf("Case #%d: ",T);
        for(int i=1;i<=55;i++){for(int j=1;j<=55;j++)mat[i][j]=0;}
		ll ans=0;
		int b;
		ll m;
		cin>>b>>m;
		ll poww = powl(2,b-2);
		if(m>poww)
		{
			ans = -1;
		}
		else
		{
			 for(int i=1;i<=50;i++)
			 {
			 	for(int j=i+1;j<=50;j++)
			 		mat[i][j]=1;
			 }
			 ll val = poww-m;
			 int ctr=2;
			 while(val!=0)
			 {
			 	ll d = val%2;
			 	if(d==1)
			 		mat[ctr][b]=0;
			 	val/=2;
			 	ctr++;
			 }
		}
		if(ans==0)
		{
			printf("POSSIBLE\n");
			for(int i=1;i<=b;i++)
			{
				for(int j=1;j<=b;j++)
					cout<<mat[i][j];
				cout<<"\n";
			}
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}