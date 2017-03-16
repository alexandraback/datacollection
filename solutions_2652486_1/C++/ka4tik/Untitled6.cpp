//cc:Kartik Singal@ka4tik
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<string>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<climits>
#include<ctime>
#include<string>
#include<fstream>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#ifndef ONLINE_JUDGE
#define DEBUG 1
#include<conio.h>
#endif

using namespace std;

#define LL                    long long
#define ss(n)                 scanf("%s",n)
#define P(x)                  printf("%d\n",x);
#define Pll(x)                printf("%lld\n",x);
#define rep(x,n)              forr(x,0,n)
#define all(c)                (c).begin(),(c).end()
#define pb                    push_back
#define MOD                   1000000007
#define ones5                 11111
#define ones6                 111111
#define ones7                 1111111
#define ones8                 11111111
#define X                     first
#define Y                     second
#define db(x) 		          if(debug) cout << #x << " : " << x <<endl;
#define db2(x,y) 	          if(debug) cout << #x << " : " << #y <<" : " << x <<" "<<y<<endl;
#define db3(x,y,z) 	          if(debug)	cout << #x << " : " << #y <<" : " << #z<<" : "<< x <<" "<<y<<" "<<z<<endl;
#define dbs(str)	          if(debug) puts("str");
#define forr(x, b, e)         for (int x = (b); x <= (e); x++)
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define iii                   pair<pair<int,int>,int>
#define ii                    pair<int,int>
#define vi                    vector<int>
#define bitcount(n)           __builtin_popcount(n)

const int debug=1;
template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> inline string tostring(const T& x) { ostringstream  os; os << x; return os.str(); }
inline int toint(const string& s) { istringstream  is(s); int x; is >> x; return x; }
inline double todouble(const string& s) { istringstream  is(s); double x; is >> x; return x; }
inline string tobinary( int a) { string s; while( a != 0 ) { s = (char)(a%2+'0') + s; a>>=1; } return s; }
int dx[] = {0, 1, 0, -1};int dx2[] = {0, 1, 0, -1,1,-1,1,-1};
int dy[] = {1, 0, -1, 0};int dy2[] = {1, 0, -1, 0,1,-1,-1,1};
long long modexp(int n, int p) {long long r = 1, b = n;while(p > 0) {if(p & 1) { r = r * b; if(r >= MOD) r %= MOD; }p >>= 1;b = b * b; if(b >= MOD) b %= MOD;}return r;}
template<class T> inline void s( T &n ) {n=0;T ch=getchar();T sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}while( ch >= '0' && ch <= '9' )n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();n=n*sign;}

/*Main Code Begins Now*/

#define NAME "problem"

void gernatetests(int N)
{
  srand(time(NULL));
  ofstream myfile;
  myfile.open (NAME "in.txt");
  myfile<<N<<endl;
  for(int i=0;i<N;i++)
  myfile<<rand()<<" ";

  myfile.close();
}
#define MAXN ones7
int testnum;
int N,M,K,c=0;
vector<int> v;

void preprocess(void)
{

}
int solve()
{
	v.resize(K);
	for(int i=0;i<K;i++)
	s(v[i]);
	
	for(int i=M;i>=2;i--)
	{
		for(int j=2;j<=M;j++)
		{
			for(int k=M;k>=2;k--){
				
				int found=0;
				int l;
				for(l=0;l<K;l++)
				{
					if(v[l]==1)
					continue;
				    int flag=0;	
					if(i*j==v[l])
					flag=1;
					if(i==v[l])
					flag=1;
					if(j==v[l])
					flag=1;
					if(k==v[l])
					flag=1;
					if(k*i==v[l])
					flag=1;
					if(k*j==v[l])
					flag=1;
					if(k*j*i==v[l])
					flag=1;
					
					
					if(!flag)
					break;
					
				}
				if(l==K)
				{
					c++;
					cout<<i<<j<<k<<endl;
					return 0;
				}
				
				
				
			}
		}
		
	}
	cout<<M<<M<<M<<endl;
	return 0;

}
int main()
{
    #ifndef ONLINE_JUDGE
     // gernatetests(1000);
      freopen(NAME "in.txt", "r", stdin);
      freopen(NAME "out.txt", "w", stdout);
    #endif

    double cl = clock();
    preprocess();
int T = 1;
   s(T);
    
    s(T);
    s(N);s(M);s(K);
   // db(M);
   printf("Case #1: \n");
    for(testnum=1;testnum<=T;testnum++)
    {
        solve();
    }
//db(c);

    fprintf(stderr, "Total Time: %lf\n", (clock() - cl) / CLOCKS_PER_SEC);
    return 0;
}






























