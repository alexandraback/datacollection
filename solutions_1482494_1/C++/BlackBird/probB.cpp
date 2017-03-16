/*
 * Author: blackBird
 * Email: saketbharamberocks@gmail.com
 */
#include <cstdio>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <climits>

using namespace std ;

typedef long long ll ;
typedef pair<int,int> ii ;

#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
#define FOR0(i,a) for(int i=0;i<(a);i++) 
#define FOR1(i,a) for(int i=1;i<(a);i++)
#define REP(i,a,b,c) for(int i=(a);i<(b);i+=(c)) 
#define TRAVERSE(it,s) for(typeof(s.begin()) it=s.begin();it!=s.end();++it)
#define ENDL putchar(10)
#define PB push_back
#define MP make_pair
#define SZ size

#define FILL(a,x) memset(a,x,sizeof a)
#define ALL(c) (c).begin(),(c).end()
#define PRESENT(c,x) (find(ALL(c),x) != (c).end())

#define ABS(a) ((a)<0?-(a):(a))
#define SQ(x) (x)*(x)
#define INF 0x7ffffff00
#define ESP 1e-6

#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MININ(a) *min_element(a.begin(), a.end())
#define MININ_A(a,n) *min_element(a, a+n)
#define MAXIN(a) *max_element(a.begin(), a.end())
#define MAXIN_A(a,n) *max_element(a, a+n)

#define P(x) cout << x 
#define PE(x) cout << x << endl 
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lld",&_x); _x;})
#define SC getchar()
#define SS(n) scanf("%s",n)

vector<ii > vii ; 
int levels[ 11111 ] ; 

bool stillToDo ( int N ) { 
     FOR0(i,N){if ( levels[i] != 2 ) { return true ; } } 
     return false ; 
}

int mycmp ( ii a, ii b ) { 
    if ( a.first == b.first ) { 
         return a.second > b.second ;
    }
    return a.first < b.first ; 
}

void solve ( void ) {
     int N = SI ;
     vii.clear();
     FOR0(i, N) { int a = SI ; int b = SI ; vii.PB(MP(a,b)); } 
//     sort(ALL(vii), mycmp );
     
     FOR0(i,N){levels[i] = 0 ; } 
     int ans = 0 ; 
     int stars = 0 ; 
     
     while ( stillToDo(N) ) { 
     //      cout << levels[0] << " " << levels[1] << " " << levels[2] << " " << levels[3] << " " << levels[4] << " " << stars << " " << ans << endl ;
           bool inc = false ; 
           FOR0(i,N){
                     if ( levels[i] == 0 && stars >= vii[i].second ) { 
                          stars += 2 ; 
                          levels[i] = 2 ; 
                          ans ++; 
                          inc = true ;
                          break ;
                     }
           }
           if ( inc ) { continue ; } 


           int todo = -1 ; 
           FOR0(i,N){
                     if ( levels[i] == 1 && stars >= vii[i].second ) { 
                          if ( todo == -1 ) { todo = i ; } 
                          else if ( vii[i].second < vii[todo].second ) { todo = i ; } 
                     }
           }
           if ( todo != -1 ) { 
                levels[todo] = 2 ;
                stars ++ ;
                ans ++ ;
                inc = true ; 
                continue ;
           }

           todo = -1 ;
           FOR0(i,N){
                     if ( levels[i] == 0 && stars >= vii[i].first ) { 
                          if ( todo == -1 ) { todo = i ; } 
                          else if ( vii[i].second > vii[todo].second ) { todo = i ; } 
                     }
           }
           if ( todo != -1 ) { 
                levels[todo] = 1 ;
                stars ++ ;
                ans ++ ;
                inc = true ;
                continue ;
           }

           if ( !inc ) { ans = -1 ; break ; } 
     }
     
     if ( ans == -1 ) { PE("Too Bad"); } 
     else { PE(ans); }
     return;
}

void solve2( void ) { 
     return ;
}

int main () {
	int Kases = SI ;
	Kases ++ ;
	FOR1(kase, Kases) {
		printf("Case #%d: ", kase);
    	solve();
	}
	return 0 ;
}
