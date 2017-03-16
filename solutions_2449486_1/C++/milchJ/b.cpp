#include <cstdio>
#include <vector>

using namespace std;

#define PII pair<int, int> 

int map[100][100];
int rowC[100];
int colC[100];

int oo=1000;
vector< PII > p[101];

int main() {

	int T;
	scanf("%d ", &T);
	
	for(int t=0; t<T; ++t) {
	
		int mini=101;
		for(int i=0; i<101; ++i)
			p[i].clear();	
		
		int N,M;
		scanf("%d %d ", &N, &M);
		for(int i=0; i<N; ++i){
			for(int j=0; j<M; ++j) {
				scanf("%d ", &map[i][j]);
				p[map[i][j]].push_back(PII(i,j));
				mini=min(map[i][j], mini);
			}			
		}
		
		for(int i=0; i<N; ++i)
				rowC[i]=0;
		for(int j=0; j<M; ++j)
				colC[j]=0; 
	
		bool okay=true;
		for(int h=mini; h<101 && okay; ++h) {
			if(p[h].size()>0) {
			//printf("height: %d\n", h);
				for(int i=0; i<p[h].size(); i++) {
					rowC[p[h][i].first]++;
					colC[p[h][i].second]++; 					
				}			
				for(int i=0; i<p[h].size(); i++) {
					if(rowC[p[h][i].first]<M && colC[p[h][i].second]<N) {
						//printf("%d %d is not mowable\n", p[h][i].first, p[h][i].second);
						okay=false;
					}
				}		
			}		
		}
		
		if(okay)
			printf("Case #%d: YES\n", t+1);
		else
			printf("Case #%d: NO\n", t+1);
	
	}

	return 0;
}
