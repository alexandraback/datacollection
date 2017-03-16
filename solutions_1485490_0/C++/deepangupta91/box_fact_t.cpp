
//Author : Deepan
#include <vector>
#include <list>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <climits>
#include <deque>
#include <fstream>
#include <stack>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class A, class B> A cvt(B x) {stringstream s;s<<x;A r;s>>r;return r;}

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i) 
#define REV(i,a,b) for(int i= (int )a ; i >= (int)b ; --i)
#define REP(i,n) FOR(i,0,n)
#define DEP(i,n) REV(i,n,0)
#define PB push_back
#define PP pop()
#define EM empty()
#define INF 1000000000
#define PF push_front
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define V(x) vector< x >
#define Debug false
#define PRINT(x)        cout << #x << " " << x << endl
#define LET(x,a) 	    __typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v)  	IFOR(it,v.begin(),v.end())
#define PRESENT(c,x) 	((c).find(x) != (c).end())
#define SZ(x) 		x.size()
#define CPRESENT(c,x) 	(find(c.begin(),c.end(),x) != (c).end())
#define D(N) 		int N
#define S(N)		scanf("%d",&N)
#define T(t) int t;scanf("%d",&t);while(t--)
#define Pln(N)		printf("%d\n",N);
#define P(N)		printf("%d ",N);
#define FASTIO          1

typedef pair<int,int>   PI;
typedef pair<int,PI>    TRI;
typedef V( int )        VI;
typedef V( PI  )        VII;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

/* FastIO, generally required these days ;) */

#ifndef FASTIO
char *ipos, *opos, InpFile[20000000], OutFile[20000000], DIP[20];
inline int input(int flag=0) {

   while(*ipos <= 32) ++ipos;
   if ( flag  ) return (*ipos++ - '0'); /* For getting Boolean Characters */
   int x=0, neg = 0;char c;
   while( true ) {
      c=*ipos++; if(c == '-') neg = 1;
      else {
	 if (c<=32) return neg?-x:x;
	 x=(x<<1)+(x<<3)+c-'0';
      }
   }
}
inline void output(int x,int flag) {
   int y,dig=0;
   while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
   while (dig--) *opos++=DIP[dig];
   *opos++= flag ? '\n' : ' ';
}
inline void InitFASTIO() {
   ipos = InpFile; opos = OutFile;
   fread_unlocked(InpFile,20000000,1,stdin);
}
inline void FlushFASTIO(vi ) {
   fwrite_unlocked(OutFile,opos-OutFile,1,stdout);	
}
#endif
int n,m;
long long int solve(vector< pair< long long int, long long int> > Nx,vector< pair< long long int, long long int> > Mx , int x,int y)
{
	if(x>=n)
		return 0L;
	if(y>=m)
		return 0L;
	long long int ans=solve(Nx,Mx,x+1,y),tmp=0;

	FOR(i,y,m)
	{
		if(Nx[x].second==Mx[i].second)
		{
			if(Nx[x].first>Mx[i].first)
			{
				tmp+=Mx[i].first;
				Nx[x].first-=Mx[i].first;
				ans=max(ans,tmp+solve(Nx,Mx,x+1,i+1));
			}
			else
			{
				Mx[i].first-=Nx[x].first;
				ans=max(ans,tmp+Nx[x].first+solve(Nx,Mx,x+1,i));
				break;
			}
		}
	}
	ans=max(ans,tmp);
	return ans;
}
int main()
{
	vector< pair< long long int, long long int >  > Nx,Mx;
	pair<long long int , long long int> tmp;
	int cases=0;
	T(t)
	{
		cases++;
		Nx.clear();
		Mx.clear();
		S(n);
		S(m);
		FOR(i,0,n)
		{
//			S(tmp.first);
//			S(tmp.second);
			cin>>tmp.first>>tmp.second;
			Nx.push_back(tmp);
		}

		FOR(i,0,m)
		{
			cin>>tmp.first>>tmp.second;
		//	S(tmp.first);
		//	S(tmp.second);
			Mx.push_back(tmp);
		}
		printf("Case #%d: %lld\n",cases,solve(Nx,Mx,0,0));
//		cout<<
	}
	return 0;
}

