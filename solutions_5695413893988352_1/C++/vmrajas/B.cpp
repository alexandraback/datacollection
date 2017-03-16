//Vanjape Rajas Mangesh

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

int A[19],B[19];
int n;
set<pair<LL, pair<LL,LL> > > ans;
void func(int pos,int eq)
{
	if(pos==n)
	{
		LL tp1=0,tp2=0;
		for(int i=0;i<n;i++)
		{
			tp1*=10;
			tp2*=10;
			tp1+=A[i];
			tp2+=B[i];
		}
		ans.insert(MP(abs(tp1-tp2),MP(tp1,tp2)));
		return ;
	}
	if(eq==0)
	{
		if(A[pos]==-1&&B[pos]==-1)
		{
			int old1=A[pos],old2=B[pos];
			A[pos]=0;B[pos]=0;
			func(pos+1,eq);
			A[pos]=1;B[pos]=0;
			func(pos+1,1);//1 means A dominates B
			A[pos]=0;B[pos]=1;
			func(pos+1,-1);//-1 means B dominates A
			A[pos]=old1;B[pos]=old2;
		}
		else if(A[pos]!=-1&&B[pos]!=-1)
		{
			if(A[pos]==B[pos])
				func(pos+1,0);
			else if(A[pos]>B[pos])
				func(pos+1,1);
			else
				func(pos+1,-1);
		}
		else if(A[pos]==-1)
		{
			int curr=B[pos];
			A[pos]=curr;
			func(pos+1,0);
			if(curr+1<10)
			{
				A[pos]=curr+1;
				func(pos+1,1);
			}
			if(curr-1>=0)
			{
				A[pos]=curr-1;
				func(pos+1,-1);
			}
			A[pos]=-1;
		}
		else
		{
			int curr=A[pos];
			B[pos]=curr;
			func(pos+1,0);
			if(curr+1<10)
			{
				B[pos]=curr+1;
				func(pos+1,-1);
			}
			if(curr-1>=0)
			{
				B[pos]=curr-1;
				func(pos+1,1);
			}
			B[pos]=-1;
		}
	}
	else if(eq==1)
	{
		
		int old1=A[pos],old2=B[pos];
		if(A[pos]==-1)
		{
			A[pos]=0;
		}
		if(B[pos]==-1)
		{
			B[pos]=9;
		}
		func(pos+1,1);
		A[pos]=old1;B[pos]=old2;

	}
	else
	{
		int old1=A[pos],old2=B[pos];
		if(A[pos]==-1)
			A[pos]=9;
		if(B[pos]==-1)
			B[pos]=0;
		func(pos+1,-1);
		A[pos]=old1;B[pos]=old2;
	}
}
int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		ans.clear();
		cout<<"Case #"<<t<<": ";
		string s1,s2;
		cin>>s1>>s2;
		n=SZ(s1);
		for(int i=0;i<n;i++)
		{
			if(s1[i]=='?')
				A[i]=-1;
			else
				A[i]=s1[i]-'0';
		}
		for(int i=0;i<n;i++)
		{
			if(s2[i]=='?')
				B[i]=-1;
			else
				B[i]=s2[i]-'0';
		}
		func(0,0);
		LL a1=(*ans.begin()).S.F,a2=(*ans.begin()).S.S;
		LL b1=a1,b2=a2;
		int ct1=0,ct2=0;
		while(b1)
		{
			b1/=10;
			ct1++;
		}
		if(a1==0)
			ct1=1;
		while(b2)
		{
			b2/=10;
			ct2++;
		}
		if(a2==0)
			ct2=1;
		for(int i=0;i<n-ct1;i++)
			cout<<"0";
		cout<<a1<<" ";
		for(int i=0;i<n-ct2;i++)
			cout<<"0";
		cout<<a2<<"\n";
	}
	return 0;
}
