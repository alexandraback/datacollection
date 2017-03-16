#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
int flag[200],idx;
int main()
{
    freopen("3.in","r",stdin);
    freopen("31.out","w",stdout);
    int T,R,N,M,K;
    cin >> T >> R >> N >> M >> K;
    printf("Case #1:\n");
    while(R--){
        int a[10];
        int b[10];
        for(int i=0;i<K;i++) scanf("%d",&b[i]);
        while(true){
            idx++;
            for(int j=0;j<N;j++)
                a[j]=rand()%(M-1)+2;
            for(int j=0;j<(1<<N);j++){
               int t=1;
               for(int k=0;k<N;k++) {
                   if(1<<k&j) t*=a[k];
               }
               flag[t]=idx;
            }
            int ok=1;
            for(int j=0;j<K;j++){
                if(flag[b[j]]<idx) {
                    ok=0;
                    break;
                }
            }
            if(ok) break;
        }
        for(int i=0;i<N;i++) printf("%d",a[i]);
        puts("");
    }
}
