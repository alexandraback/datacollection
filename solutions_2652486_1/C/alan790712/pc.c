#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define swap(x,y){int t=x;x=y;y=t;}
int r,n,m,k;
int v[12345];
int s[12345];
int ans[16]={8,9,8,9,8,9,8,9,8,9,8,9,8,9};
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int ansNum;
int main(){
    clock_t start;
    int T;
    int i,j,g;
    scanf("%d",&T);
    printf("Case #1:\n");
    scanf("%d %d %d %d",&r,&n,&m,&k);
    int X = r;
    while(r--){

        for(i=0;i<k;++i){
            scanf("%d",&v[i]);
            s[i] = v[i];
        }
        fprintf(stderr,"#%d\n",r);
        start = clock();
        while(1){
            for(i=0;i<k;++i)v[i] = s[i];
            for(i=0;i<k;++i){
                j = rand()%k;
                swap(v[i],v[j]);
            }
            ansNum = 0;
            for(i=0;i<k;++i){
                for(j=m;j>=2&&v[i]>1;--j){
                    while(v[i]%j==0){
                        ans[ansNum++] = j;
                        v[i]/=j;
                        for(g=i+1;g<k;++g){
                            if(v[g]%j==0)v[g]/=j;
                        }
                    }
                }
            }
            if(ansNum <= n){

                break;
            }
            if(clock()-start > 1500){
                    --X;
                    break;
            }
        }
        for(i=0;i<n;++i)printf("%d",ans[i]);
        puts("");
        fprintf(stderr,"#%d\n",X);
    }


    return 0;
}

