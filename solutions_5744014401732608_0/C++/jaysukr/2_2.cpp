#include<bits/stdc++.h>

#define repi(n) for(int i=0;i<(n);++i)
#define repj(n) for(int j=0;j<(n);++j)
#define repr(i,m,n) for(int i=(m);i<=(n);++i)
#define rep1i(n) for(int i=1;i<=(n);++i)
#define sz(a) int((a).size)
#define pb(v) push_back(v)
#define mp(a,b)	make_pair((a),(b))
#define all(v) (v).begin(),(v).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i!=(c).end();++i)
#define pre(c,v) ((c).find()!=(c).end)
#define vpre(c,v) (find(all(c))!=(c).end())
#define nl cout<<endl

#define fi first
#define sec second

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vii;
typedef vector<vl> vll;
typedef pair<int,int> ii;



int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int test;
	cin >> test;
	for(int cs=1;cs<=test;++cs)
	{
		ll n, m;
		cin >>n >> m;
		ll max = ((n-1)*(n-2))/2+1;		
		
		cout << "Case #" << cs <<": ";
			vii a(n+1);
			repi(n+1)
			{
				a[i].resize(n+1,0);
			}
			if(m>0)
			{
				a[1][n]=1;
				m--;
			}
			
			for(int i=2;m && i<n;++i)
			{
				a[1][i]=a[i][n]=1;
				m--;
			}
			for(int i=2;m && i<(n-1);++i)
			{
				for(int j=i+1;m && j<n;++j)
				{
					a[1][i]=1;
					a[i][j]=1;
					a[j][n]=1;
					m--;
				}
			}
			for(int i=2;m && i<(n-2);++i)
			{
				for(int j=i+1;m && j<(n-1);++j)
				{
					for(int k=j+1;m && k<n;++k)
					{
						a[1][i]=1;
						a[i][j]=1;
						a[i][k]=1;
						a[j][n]=1;
						m--;
					}
				}
			}
		if(m && n==6)
		{
			a[1][2]=a[2][3]=a[3][4]=a[4][5]=a[5][6]=1;
			m--;
		}
		
//		cout << m << endl;
		if(m>0)
			cout << "IMPOSSIBLE\n";
		else
		{
			cout << "POSSIBLE\n";
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
					cout << a[i][j] ;
				cout << endl;
			}
		}
		
	}

  	return 0;
}

