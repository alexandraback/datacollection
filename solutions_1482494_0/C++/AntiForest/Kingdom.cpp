#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int am;
	bool lvl2;
	int id;
};
struct lvlNode{
	int lvl1;
	int lvl2;
	bool done[3];
};

lvlNode allLevels[1050];
node sweepLine[3000];
int num,numLvls;
int tem1,tem2;
node besSoFar;

bool comp(node x,node y){
	return x.am<y.am;
}

int curStars,curFinished,curPos,ans;
bool found1,found2,found3;

int main(){
	freopen("q2small.in","r",stdin);
	freopen("q2small.out","w",stdout);
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		printf("Case #%d: ",i);
		scanf("%d",&numLvls);
		ans=0;
		for(int p=0;p<numLvls;p++){
			scanf("%d %d",&tem1,&tem2);
			sweepLine[2*p].am=tem1;
			sweepLine[2*p+1].am=tem2;
			sweepLine[2*p].lvl2=false;
			sweepLine[2*p+1].lvl2=true;
			sweepLine[2*p].id=sweepLine[2*p+1].id=p;
			allLevels[p].done[0]=allLevels[p].done[1]=false;
			allLevels[p].lvl1=tem1;
			allLevels[p].lvl2=tem2;
		}
		sort(sweepLine,sweepLine+2*numLvls,comp);
		curStars=0;
		curPos=0;
		curFinished=0;
		for(;;){
			for(;sweepLine[curPos].am<=curStars;curPos++){
				//Empty
			}
			found1=false;
			found2=false;
			found3=false;
			for(int t=curPos-1;t>=0;t--){
				if(allLevels[sweepLine[t].id].done[sweepLine[t].lvl2]){
					continue;
				}
				if(sweepLine[t].lvl2){
					curFinished++;
					found1=true;
					found2=true;
					if(!allLevels[sweepLine[t].id].done[0]){
						found3=true;
						allLevels[sweepLine[t].id].done[0]=true;
						allLevels[sweepLine[t].id].done[1]=true;
						curStars+=2;
						break;
					}
					besSoFar.am=1;
					besSoFar.id=sweepLine[t].id;
					break;
				}
				if(!found1){
					found1=true;
					besSoFar.am=allLevels[sweepLine[t].id].lvl2;
					besSoFar.id=sweepLine[t].id;
				} else if(!found2){
					if(allLevels[sweepLine[t].id].lvl2>besSoFar.am){
						besSoFar.am=allLevels[sweepLine[t].id].lvl2;
						besSoFar.id=sweepLine[t].id;
					}
				}
			}
			if(!found1){
				printf("Too Bad\n");
				break;
			}
			ans++;
			if(curFinished==numLvls){
				printf("%d\n",ans);
				break;
			}
			if(found3){
				continue;
			}
			if(found2){
				curStars++;
				allLevels[besSoFar.id].done[1]=true;
			} else{
				curStars++;
				allLevels[besSoFar.id].done[0]=true;
			}
		}
	}
}
