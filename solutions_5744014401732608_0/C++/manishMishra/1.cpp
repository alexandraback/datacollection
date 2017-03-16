#include<bits/stdc++.h>
using namespace std;
  
#define MOD 1000000007
#define MAX 1000000007
#define gc getchar()  
#define sc(a) scanf("%d",&a)
#define scs(a) scanf("%s",a+1);
#define pri(a) printf("%d\n",a);
#define rep(a,b,c) for(a=b;a<c;a++) 
#define rrep(a,b,c) for(a=b;a>c;a--)  
#define vit vector<int > :: iterator
#define viit vector<ii > :: iterator
#define mp(a,b)  make_pair(a,b)
#define pb(a,b) a.push_back(b)
#define trv(it,v) for(it=v.begin();it!=v.end();it++)
#define F first
#define S second
#define all(v)	v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout);

int mat[60][60];	

long long powa(long long a,long long b)
{
	long long c=1;
	while(b)
	{
		c=c*a;
		b--;
	}
	return c;
}
int main()
{	
	read("input.in");
	write("output.out");
	int t,ta;
	cin>>t;
	for(ta=1;ta<=t;ta++)
	{
		int B;long long M;
		cin>>B>>M;
		cout<<"Case #"<<ta<<": ";
		
		memset(mat,0,sizeof(mat));
		for(int i=1;i<=B-2;i++)
		{
			for(int j=i+1;j<=B-1;j++)
			{
				mat[i][j]=1;
			}
		}
		if(M>(powa(2,B-2)))
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		cout<<"POSSIBLE"<<endl;
		if(M==powa(2,B-2))
		{	
			for(int i=1;i<=B-1;i++)
			mat[i][B]=1;
			
		}
		else
		{
			int j=2;
			while(M)
			{
				if(M&1)
				{
					mat[j][B]=1;	
				}
				M>>=1;
				j++;
			}
		}
		for(int i=1;i<=B;i++)
		{
			for(int k=1;k<=B;k++)
			cout<<mat[i][k];
			cout<<endl;
		}
	}
	return 0;
}
