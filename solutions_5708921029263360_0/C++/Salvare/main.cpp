#include<bits/stdc++.h>
using namespace std;


int a[500];
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.txt","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int J,P,S,K;
        scanf("%d%d%d%d",&J,&P,&S,&K);
        int k=0;
        for(int i=0;i<J;i++)
        for(int j=0;j<P;j++)
                a[k++]=i*100+j*10;
        int p[20],b[20],fin=0;
        for(int i=0;i<k;i++)p[i]=i;
        do
        {
            int f[3][5][5],ans=0;
            memset(f,0,sizeof(f));
            for(int j=0;j<S;j++)
            for(int i=0;i<k;i++)
            {
                int x=a[p[i]]/100,y=a[p[i]]/10%10,z=j,ok=1;
                if(f[0][x][y]==K)ok=0;
                if(f[1][y][z]==K)ok=0;
                if(f[2][x][z]==K)ok=0;
                if(ok)
                {
                    f[0][x][y]++;
                    f[1][y][z]++;
                    f[2][x][z]++;
                    ans++;
                }
            }
            if(ans>fin)
            {
                fin=ans;
                memcpy(b,p,sizeof(p));
            }
        }while(next_permutation(p,p+k));
        printf("Case #%d: %d\n",ti++,fin);
            int f[3][5][5],ans=0;
            memset(f,0,sizeof(f));
            for(int j=0;j<S;j++)
            for(int i=0;i<k;i++)
            {
                int x=a[p[i]]/100,y=a[p[i]]/10%10,z=j,ok=1;
                if(f[0][x][y]==K)ok=0;
                if(f[1][y][z]==K)ok=0;
                if(f[2][x][z]==K)ok=0;
                if(ok)
                {
                    f[0][x][y]++;
                    f[1][y][z]++;
                    f[2][x][z]++;
                    printf("%d %d %d\n",x+1,y+1,z+1);
                }
            }
    }
	return 0;
}
