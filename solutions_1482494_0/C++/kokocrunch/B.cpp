#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
int TC;
int N;int R[1010][2];
bool v[1010][2];
int c1,c2;
int stars;
int main(){
	int i,j,k;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++){
		scanf("%d",&N);
		c1=0;stars=0;
		c2=0;
		memset(v,false,sizeof v);
		for(i=0;i<N;i++){
			scanf("%d%d",&R[i][0],&R[i][1]);
		}
		bool fail=false;
		int lvl=0;
		ii cur,tmp;
		while(1){
			bool done=false;
			for(j=0;j<N;j++){
				if(!v[j][1]&&R[j][1]<=stars){
					done=true;
					if(!v[j][0])stars+=2;
					else stars++;
					v[j][1]=true;v[j][0]=true;c2++;c1++;lvl++;
					//break;
				}
			}if(c2==N)break;
			if(!done){
				cur=ii(-1,-1);
				for(j=0;j<N;j++){
					if(!v[j][0]&&R[j][0]<=stars){
						cur=max(cur,ii(R[j][1],j));
					}
				}
				if(cur.first==-1){
					fail=true;break;
				}
				stars++;lvl++;
				v[cur.second][0]=true;c1++;
			}
		}
		printf("Case #%d: ",tc);
		if(fail)printf("Too Bad\n");
		else printf("%d\n",lvl);
	}
	return 0;
}	
		
	
