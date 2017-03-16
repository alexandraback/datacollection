#include <cstdio>
int person[150];
int peoples[150][3];
int tempMod[150];
int numCases,numPpl,numSurprise,limit,ans;

int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&numCases);
    for(int i=0;i<numCases;i++){
        scanf("%d %d %d",&numPpl,&numSurprise,&limit);
        ans=0;
        for(int p=0;p<numPpl;p++){
            scanf("%d",&person[p]);
        }
        for(int p=0;p<numPpl;p++){
            tempMod[p]=person[p]%3;
            peoples[p][0]=person[p]/3+(tempMod[p]>0);
            peoples[p][1]=person[p]/3+(tempMod[p]>1);
            peoples[p][2]=person[p]/3;
        }
        for(int p=0;p<numPpl;p++){
            if(peoples[p][0]>=limit){
                ans++;
                continue;
            }
            if(numSurprise==0){
                continue;
            }
            if(person[p]<2){
                continue;
            }
            if(tempMod[p]==0){
                if(peoples[p][0]==limit-1){
                    numSurprise--;
                    ans++;
                    continue;
                }
            }
            if(tempMod[p]==2){
                if(peoples[p][0]==limit-1){
                    numSurprise--;
                    ans++;
                    continue;
                }
            }
        }
        printf("Case #%d: %d\n",i+1,ans);
    }
    return 0;
}
