#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <valarray>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
typedef pair<int,int> pii;

#define MAXN (1024)
int level[MAXN][2];
char mark[MAXN][2];

int main(){
	int nteste,nt;
	
	scanf("%d",&nteste);
	for(nt = 1;nt<=nteste;nt++){
		printf("Case #%d: ",nt);
		
		
		
		int i,n,j;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d",&level[i][0],&level[i][1]);
		}
		
		memset(mark,0,sizeof mark);
		
		int resp = 0;
		int moedas = 0;
		bool complete;
		do{
			complete = true;
			int li,mod,inc = -1;
			
			for(i=0;i<n;i++){
				
				if(mark[i][1]) continue;				
				complete = false;
				
				for(j=0;j<=1;j++){
					
					if(mark[i][j]) continue;
					
					if(level[i][j] <= moedas){
						int inci = ( (j==1 && (mark[i][0] == 0)) ? 2:1);
//						printf("i=%d j=%d inci=%d\n",i,j,inci);
						
						if(inci > inc){
							inc = inci;li = i;mod = j;
						}else if(inci == inc){							
							if(j > mod){
								li = i; mod = j;
							}else if(j == mod){
								//printf("%d %d %d %d %d %d\n",li,mod,i,j,level[li][mod],
//								level[i][j]);
								if(j == 0 && (level[li][mod+1] < level[i][j+1])){
//									printf("%d %d %d %d %d %d\n",li,mod,i,j,level[li][mod],
//									level[i][j]);
									li = i; mod = j;
								}
							}
						}
					}
				}
								
			}
//			printf("inc = %d li = %d mod = %d\n",inc,li,mod);
			
			if(inc < 0) break;
			
			moedas += inc;
			mark[li][mod] = 1;
			resp++;
			
		}while(1);
		
		if(!complete) printf("Too Bad\n");
		else printf("%d\n",resp);
	}
	
}
