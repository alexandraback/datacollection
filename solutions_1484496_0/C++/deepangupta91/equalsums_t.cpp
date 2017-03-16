
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
vector<int> m[2100000];

int main()
{
	int cases=0,n,a[100];
	int flag,s1,s2,tmpi,sflag;

	T(t)
	{
		FOR(i,0,2100000)
			m[i].clear();
		flag=0;
		cases++;
		S(n);
		FOR(i,0,n)
		{
			S(a[i]);
		}
		printf("Case #%d:\n",cases);
		FOR(i,1,1<<n)
		{
			s1=0;s2=0;
			FOR(j,0,n)
			{
				if(i&(1<<j))
				{
					s1+=a[j];
				}
			}
			if(m[s1].size()==0)
			{
//				else
//					s2+=a[j];
				m[s1].push_back(i);
			}
			else
			{

				FOR(l,0,m[s1].size())
				{
					sflag=0;
					FOR(k,0,n)
					{
							if(i&(1<<k)&&m[s1][l]&(1<<k))
							{
								sflag=1;
								break;
							}
					}
					if(sflag==0)
					{
						flag=1;
						tmpi=m[s1][l];
						break;
					}
				}
				m[s1].push_back(i);
			}

			
			if(flag==1)
			{
			//	flag=1;		
				FOR(j,0,n)
				{
					if(tmpi&(1<<j))
					{
						printf("%d ",a[j]);
//						s1+=a[i];
					}
				//	else
				//		s2;
				}
				cout<<endl;
				FOR(j,0,n)
				{
					if(i&(1<<j))
					{
				//		s1;
						printf("%d ",a[j]);
//						s1+=a[i];
					}
				//	else
				//		printf("%d ",a[j]);
				//		s2+=a[i];
				}
				break;
			}	
		}
		if(!flag)
			printf("Impossible");
		cout<<endl;

	}
	return 0;
}

