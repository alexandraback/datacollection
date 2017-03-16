#include<cstdio>
#include<vector>
#define MX 202
#define MZ 1100000
using namespace std;
int type[MX],numkey[MX],haskey[MX];
int nowkey[MX];
vector<int> getkey[MX];
int reach[MZ];
int main() {
    int t,tt,k,n,i,j,l,m,tmp;
    scanf("%d",&tt);
    for(t=1;t<=tt;t++) {
        scanf("%d",&k);
        scanf("%d",&n);
        for(i=0;i<MX;i++) {
            haskey[i] = 0;
        }
        for(i=0;i<k;i++) {
            scanf("%d",&tmp);
            haskey[tmp]++;
        }
        for(i=0;i<n;i++) {
            scanf("%d",&type[i]);
            scanf("%d",&numkey[i]);
            getkey[i].clear();
            for(j=0;j<numkey[i];j++) {
                scanf("%d",&tmp);
                getkey[i].push_back(tmp);
            }
        }
        reach[(1<<n)-1] = MZ;
        for(j=(1<<n)-2;j>=0;j--) {
            reach[j] = -1;
            for(l=0;l<MX;l++) {
                nowkey[l] = haskey[l];
            }
            for(l=0;l<n;l++) {
                if((1<<l)&j) {
                    nowkey[type[l]]--;
                    for(m=0;m<numkey[l];m++) {
                        nowkey[getkey[l][m]]++;
                    }
                }
            }
            /*printf("[%d] ",j);
            for(l=0;l<4;l++) {
                printf("%d ",nowkey[l]);
            }*/
            for(l=0;l<n;l++) {
                //if(j==11) {
                //    printf("(%d,%d,%d,%d)",l,(1<<l)&j,reach[j|(1<<l)],nowkey[type[l]]);
                //}
                //printf("X");
                if(((1<<l)&j) == 0) {
                  //printf("Y");
                  if(reach[j|(1<<l)] != -1) {
                    //printf("E");
                    if(nowkey[type[l]] > 0) {
                      //printf("S");
                      reach[j] = l;
                      break;
                    }
                  }
                }
            }
            //printf("<%d>\n",reach[j]);
        }
        printf("Case #%d: ",t);
        if(reach[0] == -1) {
            printf("IMPOSSIBLE");
        }else{
            j = 0;
            while(reach[j] != MZ) {
                printf("%d ",reach[j]+1);
                j |= (1<<reach[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
