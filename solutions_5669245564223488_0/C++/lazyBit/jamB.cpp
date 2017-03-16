#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>

#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <string> vs;

typedef long long LL; //NOTES:int64
typedef unsigned long long ULL; //NOTES:uint64
typedef unsigned uint;

const double pi = acos(-1.0); //NOTES:pi
const double eps = 1e-11; //NOTES:eps
const int MAXI = 0x7fffffff;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dz[] = "SENW";

#define rep(i,n)        for (int i=0;i<n;i++)
#define loop(i,a,b)     for (int i=(a),_b=(b); i<_b; i++)
#define rloop(i,b,a)    for (int i=(b)-1,_a=(a); i>=_a; i--)
#define Reset(a,b)      memset((a),(b),sizeof(a))

#define endline         putchar('\n')
#define space           putchar(' ')
#define EXIT(x)         {cout << x;return 0;}

#define fi              first
#define se              second
#define pb              push_back

#define S(x)            scanf("%d",&x);
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define deb(i,a,n) for(i=0;i<n;i++){cout<<a[i]<<" ";}
#define db(x,y)          printf("%d %d\n",x,y);
#define debug(args...)	{dbg,args; cerr<<endl;}
#define dline			cerr<<endl	
#define INF				(int)1e9
#define LINF			(long long)1e18
#define EPS				1e-9
#define maX(a,b)		((a)>(b)?(a):(b))
#define miN(a,b)		((a)<(b)?(a):(b))
#define abS(x)			((x)<0?-(x):(x))
#define mod             1000000007

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
} dbg;

void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

char a[110],b[110];
LL ans=0;
char str[110];
int vis[110];
 long long gcd(long long x, long long y)
 {
     if(x*y == 0)
         return x+y;
     else
         return gcd(y%x, x);
 }
bool isPowerOfTwo (LL x)
{
  return ((x != 0) && ((x & (~x + 1)) == x));
}
int pr[11];
bool check(int n,int kk){
	vis[a[pr[0]-1]]=kk;
	vis[b[pr[0]-1]]=kk;
	for(int i=1;i<n;i++){
		if(a[pr[i]-1]!=b[pr[i-1]-1]){
			if(vis[a[pr[i]-1]]==kk)
				{/*cout<<char(a[pr[i]-1]+'a')<<' ';*/return false;}
			vis[a[pr[i]-1]]=kk;
		}
		if(b[pr[i]-1]!=a[pr[i]-1]){
			if(vis[b[pr[i]-1]]==kk) {/*cout<<char(a[pr[i]-1]+'a')<<' ';*/return false;}
			vis[b[pr[i]-1]]=kk;
		}
	}
	return true;
}
int vis1[256];
int main()
{
	#ifndef ONLINE_JUDGE
        input;
        output;
    #endif
	int n,i,j,k,l,m,t,s=0,d,c=0;
	bool f=0;
	S(t);
	LL p,q,r;
	
	for(int it=1;it<=t;it++){
		Reset(vis,0);
		Reset(vis1,0);
		ans=0;
	cin>>n;
	f=0;
	int prev=1;

	for(i=0;i<n;i++){
		cin>>str;
		a[i]=str[0]-'a';
		b[i]=str[strlen(str)-1]-'a';
		if(vis1[a[i]+'a']==prev||vis1[b[i]+'a']==prev)
			{f=1;break;}
		l=0;
		r=strlen(str)-1;
		while(l+1<=r&&str[l]==str[l+1]) l++;
		while(r>l&&str[r]==str[r-1]) r--;
		// cout<<l<<' '<<r<<endl;
		c=0;
		for(j=l+1;j<r;j++){
			// cout<<str[j]<<' ';
			c++;
			if(vis1[str[j]]==prev){f=1;break;}
			vis1[str[j]]=prev+1;
			
		}
		prev++;
		if(a[i]==b[i]&&c>0)
			f=1;
		if(f==1)
			break;
		// cout<<a[i]<<' '<<b[i]<<endl;
	}
	if(f==1)
	{
		printf("Case #%d: %d\n",it,0);
		continue;
	}
	for(i=1;i<=n;i++){
		pr[i-1]=i;
	}

	if(check(n,1))
		ans++;
	// cout<<ans<<endl;
	int kk=2;
	// Reset(vis[0]);
	while(next_permutation(pr,pr+n)){
		// for(i=0;i<n;i++){
		// 	cout<<pr[i]<<' ';
		// }
		if(check(n,kk))
			ans++;
		kk++;
	}

	printf("Case #%d: %d\n",it,ans%mod);

	}
		
	return (0);
}


