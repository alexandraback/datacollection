#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("D:/in.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int itr=1; itr<=tc; itr++)
    {
        long long A,B,K;
        scanf("%lld%lld%lld",&A,&B,&K);
        long long sol[8];
        long long cp[8];
        for (int i=0; i<8; i++)
            sol[i]=0;
        sol[7]=1;
        for (int bit=30; bit>=0; bit--)
        {
            for (int i=0; i<8; i++)
                cp[i]=0;
            for (int pre=0; pre<8; pre++)
                for (int mask=0; mask<4; mask++)
                {
                    int ap,bp,kp;
                    ap=(mask&1)>0;
                    bp=(mask&2)>0;
                    kp=ap&bp;
                    int am,bm,km;
                    am=(pre&1)>0;
                    bm=(pre&2)>0;
                    km=(pre&4)>0;
                    int aa,ba,ka;
                    aa=(A&(1<<bit))>0;
                    ba=(B&(1<<bit))>0;
                    ka=(K&(1<<bit))>0;

                    int al,bl,kl;

                    if (am==1 && ap==1 && aa==0)
                        continue;
                    if (bm==1 && bp==1 && ba==0)
                        continue;
                    if (km==1 && kp==1 && ka==0)
                        continue;

                    if (am==1 && ap==aa)
                        al=1;
                    else
                        al=0;
                    if (bm==1 && bp==ba)
                        bl=1;
                    else
                        bl=0;
                    if (km==1 && kp==ka)
                        kl=1;
                    else
                        kl=0;

                    int nm=al|(bl<<1)|(kl<<2);
                    cp[nm]+=sol[pre];
                }
            for (int i=0; i<8; i++)
                sol[i]=cp[i];
        }
        printf("Case #%d: %lld\n",itr,sol[0]);
    }
}
