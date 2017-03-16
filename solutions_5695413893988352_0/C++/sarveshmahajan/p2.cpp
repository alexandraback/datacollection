
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
int rr;

int n;

void f(string s1,string s2,int idx)
{
	int i,j;
	if(idx == n)
	{
		int v1=stoi(s1);
		int v2=stoi(s2);
		rr=min(rr,abs(v1-v2));
		return;
	}

	if(s1[idx] == '?')
	{
	loop(i,10)
	{
		if(s2[idx] == '?')
		{
		loop(j,10)
		{
			char aa=i+'0';
			char bb=j+'0';
			s1[idx]=aa;
			s2[idx]=bb;
			f(s1,s2,idx+1);
			s2[idx]=s1[idx]='?';
		}
		}
		else
		{
			char aa=i+'0';
			s1[idx]=aa;
			f(s1,s2,idx+1);
			s1[idx]='?';
		}

	}
	}

	else
	{
		if(s2[idx] == '?')
		{
		loop(j,10)
		{
			char bb=j+'0';
			s2[idx]=bb;
			f(s1,s2,idx+1);
			s2[idx]='?';
		}
		}
		else
		f(s1,s2,idx+1);
	}

}

PII mini;
pair<string,string> ann;


void ff(string s1,string s2,int idx)
{
	int i,j;
	if(idx == n)
	{
		int v1=stoi(s1);
		int v2=stoi(s2);
		if(rr == abs(v1-v2))
		{
			if(mp(v1,v2)<mini)
			{
				mini={v1,v2};
				ann={s1,s2};
			}
		}


			
		return;
	}

	if(s1[idx] == '?')
	{
	loop(i,10)
	{
		if(s2[idx] == '?')
		{
		loop(j,10)
		{
			char aa=i+'0';
			char bb=j+'0';
			s1[idx]=aa;
			s2[idx]=bb;
			ff(s1,s2,idx+1);
			s2[idx]=s1[idx]='?';
		}
		}
		else
		{
			char aa=i+'0';
			s1[idx]=aa;
			ff(s1,s2,idx+1);
			s1[idx]='?';
		}

	}
	}

	else
	{
		if(s2[idx] == '?')
		{
		loop(j,10)
		{
			char bb=j+'0';
			s2[idx]=bb;
			ff(s1,s2,idx+1);
			s2[idx]='?';
		}
		}
		else
		ff(s1,s2,idx+1);
	}

}






#undef int
int main()
{
#define int long long
ios_base::sync_with_stdio(false);
int t,m,l,k,ans,i,j,res=0,fl;
t=1;
cin>>(t);
int T=t;
Loop(t,T)
{
	cout<<"Case #"<<t<<": ";
	string s1,s2;
	rr=MOD;
	string S1,S2;
	cin>>s1>>s2;
	S1=s1,S2=s2;
	n=s1.size();
	f(s1,s2,0);
	mini.F=mini.S=MOD;
	s1=S1,s2=S2;
	ff(s1,s2,0);
	cout<<ann.F<<' '<<ann.S<<'\n';
}



return 0;
}
