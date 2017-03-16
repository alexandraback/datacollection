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
			scanf("%d %d",level[i],level[i]+1);
		}
		
		int maxe = n;
		int best = (1<<29);
		int k;
		
		for(i=0;i<(1<<maxe);i++){
			int t = 0;
			for(j=0;j<maxe;j++){
				mark[j][0] = 0;
				mark[j][1] = 1;
				
				if( (i & (1<<j)) != 0 ){ mark[j][0] = 1;t++;}
			}
			if(t >= best) continue;
			
			vector< pair<int, pair<int,int> > > jog;
			for(k=0;k<n;k++){
				for(int w=0;w<=1;w++){
					if(mark[k][w]) jog.push_back(make_pair(level[k][w],make_pair(k,w)));
				}
			}
			sort(ALL(jog));
			int moedas =0;
			for(k=0;k<jog.size();k++){
				if(jog[k].first > moedas) break;
				
				int ll = jog[k].second.first;
				int mod = jog[k].second.second;
				int inc = 1;
				if(mod == 1 && mark[ll][0] == 0)
					inc++;
				
				moedas += inc;				 
			}
			if(k < jog.size()) continue;
			best = t;
		}
		if(best == (1<<29)) printf("Too Bad\n");
		else printf("%d\n",best+n);
	}
	
}
