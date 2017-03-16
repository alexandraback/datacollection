/*	 Hello World!	*/

#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define s second
#define let(x,a) __typeof(a) x(a)
#define all(a) (a).begin(),(a).end() 
#define endl '\n'
#define present(c,x) ((c).find(x) != (c).end()) 
#define tr(v,it) for( let(it,v.begin()) ; it != v.end() ; it++)
#define rtr(v,it) for( let(it,v.rbegin()) ; it != v.rend() ; it++)
#define rep1(i,n) for(int i=0; i<(int)n;i++)
#define rep2(i,a,b) for(int i=(int)a; i<=(int)b; i++)

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#define LL long long int
#define PII pair<int,int>
#define VI vector<int>
#define inf INT_MAX

using namespace std;

void FastIO()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	FastIO();
	int t,n,cnt;
	string a,b;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>n;
		cout<<"Case #"<<z<<": ";
		cnt=0;
		map<string,int> M;
		vector< PII > V;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			if(!M[a])
			{
				M[a]=++cnt;
			}
			if(!M[b])
			{
				M[b]=++cnt;
			}
			V.pb(mp(M[a],M[b]));
		}
		cnt=0;
		VI marked(n,0);
		for(int h=0;h<10;h++)
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					if(marked[k] || marked[i] || marked[j] || j==k || k==i) continue;
					if(V[i].f == V[k].f && V[j].s == V[k].s)
					{
						marked[k]=1;
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}