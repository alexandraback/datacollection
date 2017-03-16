#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <iomanip>


Federico Javier Pousa



#define EPS 1e-13
typedef pair<int,int> pii;

int di[4]={0,-1,0,1};
int dj[4]={-1,0,1,0};

int main(){
	int T,H,N,M,ch[105][105],fh[105][105];
	double visit[105][105];
	double res;
	scanf("%d", &T);
	for(int caso=1;caso<=T;++caso){
		//~ cerr << caso << endl;
		res=-1.0;
		for(int i=0;i<105;++i){
			for(int j=0;j<105;++j){
				visit[i][j]=100000000000000000000000000000000000000000000000000000000000000000000000.0;
			}
		}
		
		scanf("%d %d %d",&H,&N,&M);
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				scanf("%d",&ch[i][j]);
			}
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				scanf("%d",&fh[i][j]);
			}
		}
		visit[0][0]=0.0;
		
		queue<pii> cola;
		cola.push(pii(0,0));
		pii act;	
		double vis;
		while(!cola.empty()){
			act=cola.front();
			cola.pop();
			if(act.first==N-1&&act.second==M-1){
				//~ res=visit[N-1][M-1];
				//~ break;
				continue;
			}
			//~ cerr << "Actual: " << act.first << " " << act.second << " " << visit[act.first][act.second] << endl;
			for(int k=0;k<4;++k){
				#define mii act.first+di[k]
				#define mij act.second+dj[k]
				if(mii>=0&&mii<N&&mij>=0&&mij<M){
					vis=visit[act.first][act.second];
					if(fh[act.first][act.second]+50>ch[mii][mij])continue;
					if(fh[mii][mij]+50>ch[mii][mij])continue;
					if(fh[mii][mij]+50>ch[act.first][act.second])continue;
					
					vis=max(vis,((double)H-(double)ch[mii][mij]+50.0)/10.0);
					//~ if((double)H-vis*10.0+50.0>(double)ch[mii][mij])continue;
					if(vis<=EPS){
						if(visit[mii][mij]<EPS)continue;
						visit[mii][mij]=0.0;
						cola.push(pii(mii,mij));
						continue;
					}
					if((double)H-vis*10.0-(double)fh[act.first][act.second]>=20.0){
						if(vis+1.0<visit[mii][mij]){
							visit[mii][mij]=vis+1.0;
							cola.push(pii(mii,mij));
						}
					}else{
						if(vis+10.0<visit[mii][mij]){
							visit[mii][mij]=vis+10.0;
							cola.push(pii(mii,mij));
						}
					}
				}
			}
		}
		//~ cout << setprecision(10);
		//~ cout << "Case #" << caso << ": " << res << endl; 
		printf("Case #%d: %.10lf\n",caso,visit[N-1][M-1]);
	}
	return 0;
}
