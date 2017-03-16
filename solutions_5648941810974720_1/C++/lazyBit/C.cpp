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
int num[20];
string str;

int main()
{
	// #ifndef ONLINE_JUDGE
 //        input;
 //        output;
 //    #endif
	int n,i,j,k,l,m,t,s=0,d;
	S(t);
	l=1;
	while(t--){
		Reset(a,0);
		cin>>str;
 		for(i=0;i<str.size();i++) {
 			a[str[i]]++;
 		}

 		Reset(num,0);
 		
 		//////0//////////
 		num[0]=a['Z'];
 		a['E']-=num[0];
 		a['R']-=num[0];
 		a['O']-=num[0];


 		//////6//////////
 		num[6]=a['X'];
 		a['S']-=num[6];
 		a['I']-=num[6];

 		//////8//////
 		num[8]=a['G'];
 		a['E']-=num[8];
 		a['I']-=num[8];
 		a['H']-=num[8];
 		a['T']-=num[8];


 		//////2///////
 		num[2]=a['W'];
 		a['T']-=num[2];
 		a['O']-=num[2];



 		////////4/////
 		num[4]=a['U'];
 		a['F']-=num[4];
 		a['O']-=num[4];
 		a['R']-=num[4];


 		//////1//////
 		num[1]=a['O'];
 		a['N']-=num[1];
 		a['E']-=num[1];

 		////5/////

 		num[5]=a['F'];
 		a['I']-=num[5];
 		a['V']-=num[5];
 		a['E']-=num[5];

 		/////7////
 		num[7]=a['V'];
 		a['S']-=num[7];
 		a['E']-=num[7];
 		a['E']-=num[7];
 		a['N']-=num[7];


 		////3///
 		num[3]=a['T'];
 		a['H']-=num[3];
 		a['R']-=num[3];
 		a['E']-=num[3];
 		a['E']-=num[3];

 		num[9]=a['I'];
 		a['N']-=num[9];
 		a['N']-=num[9];
 		a['E']-=num[9];


printf("Case #%d: ",l);
l++;
 		for(i=0;i<=9;i++) {
 			for(j=0;j<num[i];j++) {
 				printf("%d",i);
 			}
 		}

printf("\n");


	}
	return (0);
} 
