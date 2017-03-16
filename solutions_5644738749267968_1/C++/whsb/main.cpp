#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
double A[1024];
double B[1024];
bool used[1024];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int casT;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        printf("Case #%d: ",cas);

        int winOld=0,winNew=0;

        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%lf",&A[i]);
        for(int j=0;j<N;j++) scanf("%lf",&B[j]);
        sort(A,A+N);
        sort(B,B+N);

        memset(used,0,sizeof(used));

        for(int i=0;i<N;i++)
        {
            int cannot=1;
            for(int j=0;j<N;j++) if(used[j]==false&&A[i]<B[j]) {cannot=0;used[j]=true;break;}
            winOld+=cannot;
        }

        int Bh=0,Bt=N;

        for(int i=0;i<N;i++)
        {
            if(A[i]>B[Bh])
            {
                Bh++;winNew++;
            }
            else Bt--;
        }

        printf("%d %d\n",winNew,winOld);

    }
    return 0;
}
