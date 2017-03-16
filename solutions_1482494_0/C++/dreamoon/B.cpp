#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<set>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
struct data{
    int a,b;
    bool operator<(data ha)const{return b<ha.b||(b==ha.b&&a>ha.a);}
}d[2222];
int used[2222];
int main(){
    int T,N,i,j,cs=0;
    scanf("%d",&T);
    while(T--){
        memset(used,0,sizeof(used));
        scanf("%d",&N);
        for(i=0;i<N;i++){
            int x,y;
            cin>>x>>y;
            d[i]=(data){x,y};
        }
        sort(d,d+N);
        int now=0,an=0;
        for(i=0;i<N;i++){
            if(d[i].b<=now){
                an++;
                now+=2-used[i];
                used[i]=2;
            }
            else{
                for(j=N-1;j>=0;j--){
                    if(!used[j]&&d[j].a<=now){
                        an++;
                        used[j]=1;
                        now++;
                        break;
                    }
                }
                if(j<0)break;
                i--;
            }
        }
        printf("Case #%d: ",++cs);
        if(i<N)printf("Too Bad\n");
        else printf("%d\n",an);
    }
    return 0;
}
