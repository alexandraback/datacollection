#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int Maxn=1001;
int N,A,data[Maxn],ans;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++) {
        scanf("%d%d",&A,&N);
        //printf("%d %d\n",A,N);
        for (int i=1;i<=N;i++) scanf("%d",&data[i]);
        //printf("%d %d\n",A,N);
        //for (int i=1;i<=N;i++) printf("%d ",data[i]);
        sort(data+1,data+N+1);
        ans=1<<31-1;

        for (int del=0;del<=N;del++) {
            if (del>=ans) break;
            int cnt=del,now=A;
            for (int i=1;i<=N-del;i++) {
                if (now>data[i])
                        now+=data[i];
                else {
                    if (now==1) {cnt=1<<31-1;break;}
                    while (now<=data[i]) {
                        cnt++;
                        now+=now-1;
                    }
                    now+=data[i];
                }
            }
            if (cnt<ans) ans=cnt;
        }
        printf("Case #%d: %d\n",cases,ans);
    }
    return 0;
}
