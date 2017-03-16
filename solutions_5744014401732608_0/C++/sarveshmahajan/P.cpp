
//~        Author : Sarvesh Mahajan                             
//               IIIT,Hyderabad                                   
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define For(i,a,b) for(i=a;i<b;i++)
#define loop(i,b) for(i=0;i<b;i++)
#define Loop(i,b) for(i=1;i<=b;i++)
#define pi(n) cout<<n<<' '
#define si(n) cin>>n
#define int long long 
const int MOD=1e9+7;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
#define F first
#define S second
#define sz(x) (int) x.size()
#define pLL(x) cout<<x<<' '
#define fill(x,c) memset(x,c,sizeof(x))
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
inline void add(LL &x,LL y,int mod=MOD) { x+=y;if(x>=mod) x-=mod;}
inline void sub(LL &x,LL y,int mod=MOD) { x-=y;if(x<0) x+=mod;}
inline LL mult(LL x,LL y,int mod=MOD) { return (x*y)%mod;}
inline bool isset(int mask,int idx) { return (mask>>idx)&1;}
int expo(LL b,LL e,int mod=MOD) { LL ret=1;while(e) { if(e&1) ret=mult(ret,b,mod); b=mult(b,b,mod);e>>=1;} return ret;}

#ifdef DEBUG
#define DB(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
       cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
       const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define DB(...)
#endif








/*#ifdef DEBUG
#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#else
#define DB(x)
#define DB2(x,y)
#define DB3(x,y,z)
#endif
*/

int a[51][51];
int pow2[100];
void print(int a[51][51],int n)
{
	int i,j;
	loop(i,n)
	{
		loop(j,n)
		cout<<a[i][j];
		cout<<'\n';
	}
}





#undef int
int main()
{
#define int long long
ios_base::sync_with_stdio(false);
int n,t,m,l,k,ans,i,j,res=0,fl;
t=1;
int b;
cin>>(t);
int T=t;
pow2[0]=1;
for(i=1;i<60;++i)
	pow2[i]=pow2[i-1]*2;
Loop(t,T)
{
	cout<<"Case #"<<t<<": ";
	cin>>b>>m;
	fill(a,0);
	loop(i,b-1)
	{
		for(j=i+1;j<b-1;++j)
		a[i][j]=1;
	}

	loop(i,b)
		a[b-1][i]=0;

	if(m>pow2[b-2])
	{
		cout<<"IMPOSSIBLE\n";
		continue;
	}

	cout<<"POSSIBLE\n";
	if(m == pow2[b-2])
	{
		loop(i,b-1)
		a[i][b-1]=1;

		print(a,b);
	}
	else
	{
		for(int i=b-3;i>=0;--i)
		{
			if(isset(m,i))
				a[i+1][b-1]=1;
		}
	        print(a,b);
	}




}
return 0;
}
