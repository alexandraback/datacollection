#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int main(){

    int t,k,c,s;
    vector<long long unsigned int> merged;
    scanf("%d ",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d %d ",&k,&c,&s);
        int cal=c*s;
        if(cal<k){
            printf("Case #%d: IMPOSSIBLE\n",i+1);
            continue;
        }
        int firstLeft=0;
        merged.clear();
        for(int j=0;j<s && j<k;j++){
            merged.push_back(0);
        }
        for(int j=0;j<c;j++){
            for(int m=0;m<(int)merged.size();m++){
                merged[m]=merged[m]*k;
                if(firstLeft<k){
                    merged[m]+=firstLeft;
                    firstLeft++;
                }
            }
        }
        printf("Case #%d:",i+1);
        for(int m=0;m<(int)merged.size();m++){
            printf(" %llu",merged[m]+1);
        }
        printf("\n");
    }

}
