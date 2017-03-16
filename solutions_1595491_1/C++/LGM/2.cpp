//In the name of Allah
//
//
//////////////////////
// Program: 
// Written By Alireza Farhadi (LGM)
//////////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <vector>
#include <bitset>
#include <deque>
#include <iomanip>
#include <complex>
#include <fstream>
#include <sstream>
#include <map>
//#include <climits>
//#include <list>

using namespace std;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define show(x) cerr<<((#x))<<" = "<<((x))<<" "<<endl
#define bit(a,b) (((a)>>(b))&1)
#define gcd __gcd
#define endl '\n'
#define bcnt(x) ((__builtin_popcount(x)))
#define sz(x) ((int((x).size())))
#define sqr(x) ((((x))*((x))))
#define fx(x) fixed<<setprecision(x)

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;

const double eps=1e-9;
const ld leps=1e-14;
const int MN=200+10;
int t,n,p,s;
int d[MN][MN];
int list[MN];
int fll(int a,int b)
{
	if (a<0) return 0;
	if (b>a+1) return -1000;
	int & res=d[a][b];
	if (res!=-1) return res;
	res=-1000;
	for (int i=0;i<=10;i++) for (int j=i;j<=min(10,i+2);j++) for (int k=j;k<=min(10,i+2);k++) if (i+j+k==list[a])
	{
		if (k-i==2 && b!=0)
			smx(res,fll(a-1,b-1)+(k>=p));
		else if (k-i<2)
			smx(res,fll(a-1,b)+(k>=p));
	}
	return res;
}
int main(int argc,char * argv[])
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	for (int tc=1;tc<=t;tc++)
	{
		cout<<"Case #"<<tc<<": ";
		memset(d,-1,sizeof(d));
		cin>>n>>s>>p;
		for (int i=0;i<n;i++)
			cin>>list[i];
		cout<<fll(n-1,s)<<endl;
	}
	return 0;
}
