#include<cstdio>
#include<queue>
using namespace std;
int T;
#define MAXN 1000

int main(){
    scanf("%d",&T);
    for(int z=0;z<T;z++){
        bool o[MAXN],t[MAXN];
        int one[MAXN],two[MAXN];
        int s=0,a=0,tn=0;
        int N;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d %d",one+i,two+i);
            t[i]=false;
            o[i]=false;
        }
        bool stuck=false;
        while(!stuck&&tn!=N){
            int i;
            stuck=true;
            for(i=0;i<N;i++)
                if(two[i]<=s&&!t[i])
                    break;
            if(i!=N){
                t[i]=true;
                if(o[i])s+=1;
                else s+=2;
                stuck=false;
                a++;
                tn++;
                continue;
            }
            int b=-1;
            int bi=0;
            for(i=0;i<N;i++){
                if(one[i]<=s&&!t[i]&&!o[i]&&two[i]>b){
                    b=two[i];
                    bi=i;
                }
            }
            if(b!=-1){
                o[bi]=true;
                s+=1;
                stuck=false;
                a++;
                continue;
            }
        }
        if(tn==N)
            printf("Case #%d: %d\n",z+1,a);
        else
            printf("Case #%d: Too Bad\n",z+1);
    }
    
    return 0;
}

