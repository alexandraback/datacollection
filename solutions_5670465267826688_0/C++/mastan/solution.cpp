#include <cstdio>
#include <algorithm>

using namespace std;

int ml[10][10]=
{
    {

    },
    {
        0,1,2,3,4
    },
    {
        0,2,-1,4,-3
    },
    {
        0,3,-4,-1,2
    },
    {
        0,4,3,-2,-1
    }
};

inline int pomnozi(int l,int r)
{
    int znak=1;
    if (l<0)
    {
        znak*=-1;
        l=-l;
    }
    if (r<0)
    {
        znak*=-1;
        r=-r;
    }
    return ml[l][r]*znak;
}

inline int stepen(int a,long long p)
{
    if (p==0)
        return 1;
    int mid=stepen(a,p>>1);
    mid=pomnozi(mid,mid);
    if (p&1)
        mid=pomnozi(mid,a);
    return mid;
}

char base[10005];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int it=1; it<=tc; it++)
    {
        int ln;
        long long kop;
        scanf("%d%lld",&ln,&kop);
        scanf("%s",base+1);
        for (int i=1; i<=ln; i++)
        {
            if (base[i]=='1')
                base[i]=1;
            if (base[i]=='i')
                base[i]=2;
            if (base[i]=='j')
                base[i]=3;
            if (base[i]=='k')
                base[i]=4;
        }
        int blok=2;
        int state=1;
        int pl=0;
        int steps=0;
        while (1)
        {
            pl++;
            steps++;
            state=pomnozi(state,base[(pl-1)%ln+1]);
            //printf("%d %d %d\n",pl,state,blok);
            if (state==blok)
            {
                steps=0;
                state=1;
                blok++;
                if (blok==4)
                    break;
            }
            if (pl>=ln*kop)
                break;
            if (steps>8*ln)
                break;
        }
        if (blok!=4)
            printf("Case #%d: NO\n",it);
        else
        {
            while (pl%ln)
            {
                pl++;
                state=pomnozi(state,base[(pl-1)%ln+1]);
            }
            int baza=1;
            for (int i=1; i<=ln; i++)
                baza=pomnozi(baza,base[i]);
            state=pomnozi(state,stepen(baza,kop-pl/ln));
            if (state==4)
                printf("Case #%d: YES\n",it);
            else
                printf("Case #%d: NO\n",it);

        }

    }

}
