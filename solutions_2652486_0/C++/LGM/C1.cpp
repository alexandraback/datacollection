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
#define fl endl<<flush

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T _rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;
typedef pie pii;
typedef complex<double> point;

const double eps=1e-8;
const ld leps=1e-14;
const int MN=1000;
int t,r,n,m,k;
int no[MN];
int cnt[100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t>>r>>n>>m>>k;
	cout<<"Case #1:"<<endl;
	for (int tmp=0;tmp<r;tmp++)
	{
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<k;i++)
			cin>>no[i];
		for (int i=0;i<k;i++)
			for (int j=2;j<=m;j++)
			{
				int t=0;
				while (no[i]%j==0)
					t++,no[i]/=j;
				if (j!=2)
					smx(cnt[j],t);
				else
					smx(cnt[2],t%2),smx(cnt[4],t/2);
			}
		int p=0;
		for (int i=2;i<=m;i++)
			for (int j=0;j<cnt[i] && p<n;j++,p++)
				cout<<i;
		for (;p<n;p++)
			cout<<2;
		cout<<endl;
	}
	return 0;
}
