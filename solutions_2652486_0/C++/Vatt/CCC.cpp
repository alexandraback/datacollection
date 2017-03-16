#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
using namespace std;
int N;
bool mm[2200][16400];
int ans[2200][16400],th,nowm,noww[10],rr,b[10],now,a[50000],M,T,R,K,know[15];
map<int,int> mapp;
int nub=1;
void go2(int h)
{
        if(h==N)
        {
                ans[th][nowm]++;
                //printf("%d %d\n",a[th],nowm);
                return;
        }
        go2(h+1);
        nowm*=noww[h];
        go2(h+1);
        nowm/=noww[h];
} 
void go(int h)
{
        if(h==N)
        {
                for(int i=0;i<N;i++)
                {
                        b[i]=noww[i];
                }
                sort(&b[0],&b[N]);
                now=0;
                nowm=1;
                for(int i=0;i<N;i++)
                {
                        now*=10;
                        now+=b[i];
                }
                if(mapp[now]==0)
                {
                        a[nub]=now;
                        th=nub;
                        mapp[now]=nub;
                        nub++;
                }
                else th=mapp[now];
                go2(0);
                return;
        }
        for(int i=2;i<=M;i++)
        {
                noww[h]=i;
                go(h+1);
        }
}
main()
{
        freopen("C-small-1-attempt1.in","r",stdin);
        freopen("outCCC.txt","w",stdout);
        scanf("%d",&T);
        for(rr=1;rr<=T;rr++)
        {
                nub=0;
                scanf("%d %d %d %d",&R,&N,&M,&K);
                //printf("MMM %d\n",M);
                printf("Case #%d:\n",rr);
                go(0);
                //system("pause");
                for(int rrr=0;rrr<R;rrr++)
                {
                        for(int i=0;i<K;i++)
                        {
                                scanf("%d",&know[i]);
                        }
                        long long anss=-1;
                        int p;
                        for(int i=0;i<nub;i++)
                        {
                                int con = mapp[a[i]];
                                //printf("%d (%d):", a[i],con);
                                long long nn=1;
                                for(int j=0;j<K;j++)
                                {
                                        nn*=ans[con][know[j]];
                                        //printf("%d ",ans[con][know[j]]);
                                }
                                //printf("\n");
                                if(nn>anss)
                                {
                                        anss=nn;
                                        p=a[i];
                                }
                        }
                        printf("%d\n",p);      
                }
        }
        //system("pause");
}
