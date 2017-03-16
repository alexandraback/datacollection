#include <cstdio>

using namespace std;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int N,n,most;
    int p[1100];
    scanf("%d",&N);
    for(int T=1;T<=N;T++){
        scanf("%d",&n);
        most=-1;
        for(int i=0;i<n;i++)
            scanf("%d",&p[i]);
        for(int i=0;i<n;i++)
            if(p[i]>most)
                most=p[i];
        int time=5000;
        for(int k=1;k<=most;k++){
            int t=0;
            for(int i=0;i<n;i++){
                t+=(p[i]-1)/k;
            }
            t+=k;
            if(t<time)
                time=t;
        }
        printf("Case #%d: %d\n",T,time);
    }
    return 0;
}
