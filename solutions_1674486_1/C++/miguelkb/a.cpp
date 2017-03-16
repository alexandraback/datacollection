/**/
#include<iostream>
#include<algorithm>
#include<vector>

#include<cstring>

using namespace std;
int n;
vector <int> G[1005];
int guarda[1005][1005];
int Funcion(int x , int v){
	if( x == v) return 1;
	if(guarda[ x ][ v ] != -1) return guarda[x][v];
	int res = 0;
	for(int i = 0;i < G[ x ].size(); i++){
		res += Funcion( G[ x ][ i ], v );
		if(res >= 2) res = 2;
	}
	if( res >= 2 ) res = 2;
	return guarda[ x ][ v ] = res;
}
int main(){
	int runs;
	cin >> runs;
	for( int r = 1; r <= runs; r++){
		cin >> n;
		for( int i = 0;i < n; i++) G[ i ].clear();

		for( int i = 0; i < n; i++){
			int m ;
			cin >> m;
			for( int j = 0; j < m; j++){
				int u;
				cin >> u;
				u--;
				G[i].push_back( u );
			}
		}
		memset( guarda, -1, sizeof guarda );
		bool cagao = true;
		for( int i = 0; i < n; i++){
			for( int j = 0; j < n; j++){
				if ( i == j ) continue;
				if( Funcion(i,j) >= 2 ){
					cagao = false;
					goto hell;
				}
			}

		}
		hell:
		cout<<"Case #"<<r<<":";
		if (!cagao) cout<<" Yes"<<endl;
		else cout<<" No"<<endl;
	}
}
/**/
