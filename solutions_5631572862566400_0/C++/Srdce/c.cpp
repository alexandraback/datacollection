#include<bits/stdc++.h>

using namespace std;

queue < int > que;
int q[2000] , dis[2000] , f[2000] , col[2000];
bool vis[2000] , incir[2000];
vector < int > e[2000] , v[2000] , cir , c[2000];

void bfs( int pos , int color ) {
	que.push( pos );
	col[pos] = color;
	while( !que.empty() ) {
		int cur = que.front();
		que.pop();
		for( int i = 0 , sz = e[cur].size() ; i < sz ; i++ )
			if( !col[e[cur][i]] ) {
				que.push( e[cur][i] );
				col[e[cur][i]] = color;
			}
	}
}

int ans_bfs( int pos ) {
	int head = 0 , tail = 1;
	q[head] = pos;
	memset( dis , 0 , sizeof dis );
	dis[pos] = 1;
	while( head < tail ) {
		int cur = q[head++];
		for( int i = 0 , sz = v[cur].size() ; i < sz ; i++ )
			if( !dis[v[cur][i]] && !incir[v[cur][i]] ) {
				q[tail++] = v[cur][i];
				dis[v[cur][i]] = dis[cur]+1;
			}
	}
	for( int i = tail-1 ; i ; i-- ) {
		int cur = q[i];
		dis[f[cur]] = max( dis[f[cur]] , dis[cur] );
	}
	return dis[pos];
}

int main() {
	int t;
	cin >> t;
	for( int ca = 1 ; ca <= t ; ca++ ) {
		int n;
		cin >> n;
		for( int i = 1 ; i <= n ; i++ ) {
			v[i].clear();
			e[i].clear();
			c[i].clear();
		}
		memset( col , 0 , sizeof col );
		memset( vis , 0 , sizeof vis );
		for( int i = 1 ; i <= n ; i++ ) {
			cin >> f[i];
			v[f[i]].push_back( i );
			e[f[i]].push_back( i );
			e[i].push_back( f[i] );
		}
		int color = 0;
		for( int i = 1 ; i <= n ; i++ )
			if( !col[i] )
				bfs( i , ++color );
		for( int i = 1 ; i <= n ; i++ )
			c[col[i]].push_back( i );
		int ans = 0 , maxcir = 0;
		for( int i = 1 ; i <= color ; i++ ) {
			bool flag = 1;
			for( int j = 0 , sz = c[i].size() ; j < sz ; j++ )
				if( v[c[i][j]].empty() ) {
					flag = 0;
					int pos = c[i][j];
					for( ; !vis[pos] ; pos = f[pos] )
						vis[pos] = 1;
					cir.clear();
					cir.push_back( pos );
					memset( incir , 0 , sizeof incir );
					incir[pos] = 1;
					for( int k = f[pos] ; k != pos ; k = f[k] ) {
						cir.push_back( k );
						incir[k] = 1;
					}
					maxcir = max( maxcir , (int)cir.size() );
					break;
				}
			if( flag )
				ans += c[i].size();
			else if( cir.size() == 2 ) {
				for( int j = 0 , sz = cir.size() ; j < sz ; j++ )
					ans += ans_bfs( cir[j] );
			}
		}
		cout << "Case #" << ca << ": " << max( ans , maxcir ) << endl;
	}
	return 0;
}
