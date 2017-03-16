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

int t,n;
pie list[2000];
int now[2000];
int hv=0,cnt=0;
pie srt[1000];
int main(int argc,char * argv[])
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	for (int tc=1;tc<=t;tc++)
	{
		cin>>n;
		show(n);
		for (int i=0;i<n;i++) cin>>list[i].first>>list[i].second;
		for (int i=0;i<n;i++) srt[i]=pie(list[i].second,i);
		sort(srt,srt+n,greater<pie> ());
		for (int i=0;i<n;i++) now[i]=0;
		hv=cnt=0;
		while (hv<2*n)
		{
			for (int i=0;i<n;i++) if (now[i]<2 && list[i].second<=hv)
			{
				hv+=(2-now[i]);
				cnt++;
				now[i]=2;
				goto nex;
			}
			for (int i=0;i<n;i++) if (now[srt[i].second]<1 && list[srt[i].second].first<=hv)
			{
				hv++;
				cnt++;
				now[srt[i].second]=1;
				goto nex;
			}
			cnt=-1;
			break;
nex:;
		}
		cout<<"Case #"<<tc<<": ";
		if (cnt==-1)
			cout<<"Too Bad"<<endl;
		else
			cout<<cnt<<endl;
	}
	return 0;
}
