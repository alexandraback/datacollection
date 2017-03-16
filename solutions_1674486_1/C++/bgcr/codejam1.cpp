#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int t,n,m;
int mark[1001];
bool pode;

int main(){
	scanf("%d",&t);
	for ( int cas = 1 ; cas <= t ; cas++ ){
		scanf("%d",&n);
		vector<int> lista[1010];
		for ( int i = 1 ; i <= n ; i++ ){
			scanf("%d",&m);
			int a;
			for ( int j = 0 ; j < m ; j++ ){
				scanf("%d",&a);
				lista[i].push_back(a);
			}
		}
		pode = false;
		for ( int i = 1 ; i <= n ; i++ ){
			memset(mark,0,sizeof(mark));
			queue<int> fila;
			fila.push(i);
			while ( !fila.empty() ){
				int aux=fila.front();
				fila.pop();
				mark[aux]++;
				if ( mark[aux] > 2 ) continue;
				for ( int j = 0 ; j < lista[aux].size() ; j++ ){
					fila.push(lista[aux][j]);
				}
			}
			for ( int j = 1 ; j <= n ; j++ ){
				if ( mark[j] > 1 && j != i ){
					pode=true;
					break;
				}
			}
			if ( pode ) break;
		}
		printf("Case #%d: %s\n",cas,pode?"Yes":"No");
	}
	return 0;
}