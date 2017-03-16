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
	int t,cnt,l;
	LL A,B,M;
	string a[2],ans1,ans2;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>a[0]>>a[1];
		cout<<"Case #"<<z<<": ";
		cnt=0;
		M=1e18;
		vector< PII > V;
		l=a[0].length();
		for(int j=0;j<2;j++)
		{
			for(int i=0;i<l;i++)
			{
				if(a[j][i]=='?')
				{
					cnt++;
					V.pb(mp(j,i));
				}
			}
		}
		if(cnt==6)
		{
			for(int i=0;i<l;i++)
			{
				a[0][i]='0';
				a[1][i]='0';
			}
		}
		else if(cnt==5)
		{
			for(int i=0;i<l;i++)
			{
				if(a[0][i]!='?') a[1][i]=a[0][i];
				else if(a[1][i]!='?') a[0][i]=a[1][i];
				else
				{
					a[0][i]='0';
					a[1][i]='0';
				}
			}
		}
		else
		{
			for(int i=0;i<pow(10,cnt);i++)
			{
				int temp=i;
				for(int j=cnt-1;j>=0;j--)
				{
					int x=V[j].f, y=V[j].s;
					a[x][y]=temp%10+'0';
					temp/=10;
				}
				stringstream ss1;
				ss1<<a[0];
				ss1>>A;
				stringstream ss2;
				ss2<<a[1];
				ss2>>B;
				if(abs(A-B)<M)
				{
					M=abs(A-B);
					ans1=a[0];
					ans2=a[1];
				}
			}
			a[0]=ans1;
			a[1]=ans2;
		}
		cout<<a[0]<<" "<<a[1]<<endl;
	}
	return 0;
}