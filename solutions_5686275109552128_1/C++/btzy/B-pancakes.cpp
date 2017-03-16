#include<cstdio>
#include<algorithm>
using namespace std;
int tc,d;
int arr[1000];
int best;
int splits;
int main(){
    scanf("%d",&tc);
    for(int ct=1;ct<=tc;++ct){
        scanf("%d",&d);
        for(int i=0;i<d;++i){
            scanf("%d",&arr[i]);
        }
        best=1000;
        for(int limit=1;limit<=1000;++limit){
            splits=0;
            for(int i=0;i<d;++i){
                splits+=(arr[i]-1)/limit;
            }
            best=min(best,splits+limit);
        }
        printf("Case #%d: %d\n",ct,best);
    }
}
