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
#include <random>
 
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
 
int a[100010];
bool vis[100010];
string str1,str2;
string charstr[]={"0","1","2","3","4","5","6","7","8","9"};
vector<string> a1;
vector<string> b1;

vector<int> aa1;
vector<int> bb1;

void dfs1(string str,int i,int n) {
if(i==n) {
	// cout<<str<<endl;
	a1.push_back(str);
	aa1.push_back(stoi(str));
	return;
}
// cout<<str1[i]<<' '<<str<<' '<<i<<' '<<n<<endl;
	if(str1[i]=='?') {
		// printf("hi\n");
		for(int j=0;j<=9;j++) {
			// printf("hi\n");
			string s1=str+charstr[j];
			// cout<<str1[i]<<' '<<str<<' '<<i<<' '<<n<<endl;
			dfs1(s1,i+1,n);
		}
	} else {

		string s1=str+str1[i];
		// cout<<str1<<' '<<s1<<' '<<i<<' '<<n;
		dfs1(s1,i+1,n);
	}
}

void dfs2(string str,int i,int n) {
if(i==n) {
	b1.push_back(str);
	bb1.push_back(stoi(str));
	return;
}
	if(str2[i]=='?') {
		for(int j=0;j<=9;j++) {
			string s2=str+charstr[j];
			dfs2(s2,i+1,n);
		}
	} else {
		string s2=str+str2[i];
		dfs2(s2,i+1,n);
	}
}

int main()
{
	// #ifndef ONLINE_JUDGE
 //        input;
 //        output;
 //    #endif
	int n,i,j,k,l,m,t,s=0,d;
	S(t);
	d=1;

	while(t--){
		cin>>str1;
		cin>>str2;
		a1.clear();
		b1.clear();
		aa1.clear();
		bb1.clear();
		string ans1="";
		string ans2="";
		l=str1.size();
		int l2=str2.size();
		dfs1("",0,l);
		dfs2("",0,l2);
		// cout<<a1.size()<<endl<<str2;
int min =100000000;
		for(i=0;i<a1.size();i++) {
			for(j=0;j<b1.size();j++) {
				if(abs(aa1[i]-bb1[j])<min) {
					ans1=a1[i];
					ans2=b1[j];
					min=abs(aa1[i]-bb1[j]);
				}
			}
		}

		printf("Case #%d: ",d);
		cout<<ans1<<' '<<ans2<<endl;
		d++;
 		
	}
	return (0);
} 
