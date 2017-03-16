#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int N,P,S,T;

int main(){
    freopen("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\test.txt","r",stdin);
    freopen("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\ans.txt","w",stdout);
    int i,j,cs,n=0,sum;
    scanf("%d",&cs);
    while(cs--){
        n++;
        sum=0;
        scanf("%d%d%d",&N,&S,&P);
        for(i=1;i<=N;i++){
            scanf("%d",&T);
            if(T>=3*P-2)   sum++;
            else if(T>=3*P-4 && S && 3*P-4>=0){
                sum++;   S--;
            }
        }
        printf("Case #%d: %d\n",n,sum);
    }
    return 0;
}
