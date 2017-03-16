#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[2][2];

int main(){
    
    int T;
    scanf(" %d",&T);
    for(int t=0;t<T;t++){
        int N,c = 0;
        scanf(" %d",&N);
        for(int i=0;i<N;i++){
            int x,y,z;
            scanf(" %d %d %d",&x,&y,&z);
            for(int j=0;j<y;j++,c++)
                a[c][0] = x, a[c][1] = z+j;
        }
        if(c<=1){
            printf("Case #%d: 0\n",t+1);
            continue;
        }
        int ans = 0;
        if(a[0][0] > a[1][0]){
            swap(a[0][0],a[1][0]);
            swap(a[0][1],a[1][1]);
        }
        double timea,timeb;
        if(a[0][1] < a[1][1]){ // A is faster than B
            timea = ((double)(360-a[0][0])/360.0f)*a[0][1] + a[0][1];
            timeb = (double)(360-a[1][0])/360.0f*a[1][1];
            if(timea <= timeb)  ans = 1;
        }else{ // B is faster
            timea = ((double)(360-a[0][0])/360.0f)*a[0][1];
            timeb = (double)(360-a[1][0])/360.0f*a[1][1] + a[1][1];
            if(timeb <= timea)  ans = 1;
        }
        printf("Case #%d: %d\n",t+1,ans);
    }

    return 0;
}
