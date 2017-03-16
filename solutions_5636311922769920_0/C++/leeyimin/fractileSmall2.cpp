#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int main(){

    int t,k,c,s;
    scanf("%d ",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d %d ",&k,&c,&s);
        long long unsigned int cal=1;
        for(int j=1;j<c;j++){
            cal*=k;
        }
        printf("Case #%d:",i+1);
        long long unsigned int x=0;
        for(int j=0;j<k;j++){
            printf(" %llu",x*cal+1);
            x++;
        }
        printf("\n");
    }

}
