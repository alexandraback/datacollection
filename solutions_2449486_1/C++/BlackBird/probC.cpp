
#include<cstdio>
#include <vector>

using namespace std ;

int G[111][111];

#define MP make_pair

typedef pair<int,int> pii; 

vector<pii> V[111] ; 

void solve(){ 
	int n, m ;
	scanf("%d%d", &n,&m);
	for ( int i = 0 ; i < 111 ; i ++ ) { 
		V[i].clear();
	}
	for ( int i = 0 ; i < n ; i ++ ) { 
		for ( int j = 0 ; j < m ; j ++ ) { 
			scanf("%d",&G[i][j]);
			V[G[i][j]].push_back(MP(i,j));
		}
	}
	for (int num = 1; num < 111 ; num ++ ) { 
		int L = V[num].size();
		for ( int z = 0 ; z < L ; z ++ ) {
			int x = V[num][z].first ;
			int y = V[num][z].second ;
			bool okay = true ;
			for ( int i  = 0 ; i < n ; i ++ ) { 
				if ( G[i][y] > num ) { 
					okay = false ;
					break ;
				}
			}
			if ( okay ) { 
				continue ;
			}
			okay = true ;
			for ( int j = 0 ; j < m ; j ++ ) { 
				if ( G[x][j] > num ) { 
					okay = false ; 
					break ;
				}
			}
			if ( okay ) { 
				continue ; 
			} else {
				printf("NO\n"); 
				return ; 
			}
		}
	}
	printf("YES\n");
	return ;
}

int main() { 
	int t ;
	int no = 1; 
	for ( scanf("%d", &t) ; t -- ; ) { 
		printf("Case #%d: ", no++);
		solve();
	}
	return 0;
}
