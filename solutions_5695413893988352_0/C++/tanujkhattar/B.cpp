//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef unsigned long long int 	LL;

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


string a,b;
string A,B;
LL mn;
LL get(string& s){
	LL ret = 0;
	for(auto c:s)
		ret = (ret*10 + (c-'0'));
	return ret;
}
void solve(int pos,int curr){
	if(pos==SZ(a)){
		LL c1 = get(a);
		LL c2 = get(b);
		if(c1 < c2)swap(c1,c2);
		if(c1-c2 < mn)
			A = a,B=b,mn=c1-c2;
		else if(c1-c2==mn && (a < A || (a == A && b < B)))
			A = a, B = b;
		return;
	}
	if(a[pos]=='?' && b[pos]=='?'){
		if(curr == 0){
			a[pos]='0';b[pos]='0';solve(pos+1,0);
			a[pos]='1';b[pos]='0';solve(pos+1,1);
			a[pos]='0';b[pos]='1';solve(pos+1,-1);
		}
		else if(curr == 1){
			a[pos]='0';b[pos]='9';solve(pos+1,1);
		}
		else if(curr == -1){
			a[pos]='9';b[pos]='0';solve(pos+1,-1);
		}
		a[pos]='?';b[pos]='?';
	}
	else if(a[pos]=='?'){
		if(curr == 0){
			a[pos]=b[pos];solve(pos+1,0);
			if(b[pos]!='9'){a[pos]=1 + b[pos];solve(pos+1,1);}
			if(b[pos]!='0'){a[pos]=b[pos] - 1;solve(pos+1,-1);}
		}
		else if(curr == 1){
			a[pos]='0';solve(pos+1,1);
		}
		else if(curr == -1){
			a[pos]='9';solve(pos+1,-1);
		}
		a[pos]='?';
	}
	else if(b[pos]=='?'){
		if(curr == 0){
			b[pos]=a[pos];solve(pos+1,0);
			if(a[pos]!='9'){b[pos]=1 + a[pos];solve(pos+1,-1);}
			if(a[pos]!='0'){b[pos]=a[pos] - 1;solve(pos+1,1);}
		}
		else if(curr == 1){
			b[pos]='9';solve(pos+1,1);
		}
		else if(curr == -1){
			b[pos]='0';solve(pos+1,-1);
		}
		b[pos]='?';
	}
	else{
		if(curr==0)curr = (a[pos]>b[pos]?1:(a[pos]<b[pos]?-1:0));
		solve(pos+1,curr);
	}
}
int main()
{
	int t;si(t);
	for(int T=1;T<=t;T++){
		printf("Case #%d: ",T);
		cin>>a>>b;
		A = a; B = b;mn = LL(1e19);
		solve(0,0);
		cout<<A<<" "<<B<<endl;
	}
	return 0;
}
