#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
LL X,L;
char pa[22000];

/// 1=> 1, 2=>i, 3=>j ,4=>k
int biao[5][5] = {
{0,0,0,0,0},
{0,1, 2, 3, 4},
{0,2,-1, 4,-3},
{0,3,-4,-1, 2},
{0,4, 3,-2,-1}
};
int sgn(int a)
{
    return a>=0?1:-1;
}
int abs(int a)
{
    return a>0?a:-a;
}
int mul(int a,int b)
{
    if(a==1||a==-1||b==1||b==-1) return a*b;
    int sgna = sgn(a);
    int sgnb = sgn(b);
    return sgna*sgnb*biao[abs(a)][abs(b)];
}
int change(char key)
{
    switch(key){
        case 'i':return 2;
        case 'j':return 3;
        case 'k':return 4;
        default :return 1;
    }
    return 1;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int casT;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        cin>>L>>X;
        scanf("%s",pa);
        bool ans = true;
        LL N = L*X;
        LL len = min(N,L*4);
        int le = 1,ri=1;
        LL pl=0,pr=0;
        while(pl<len)
        {
            le=mul(le,change(pa[pl%L]));
            pl++;
            if(le==2) break;
        }
        if(le!=2) ans=false;
        while(pr<len)
        {
            ri = mul(change(pa[(N-pr-1LL)%L]),ri);
            pr++;
            if(ri==4) break;
        }
        if(ri!=4) ans=false;
        if(pl+pr>=N) ans = false;
        //cout<<pl<<" "<<pr<<endl;


        pr = N - pr - 1LL;
        int mid = 1;
        if(pr-pl<=4*L)
        {
            for(LL i=pl;i<=pr;i++) mid=mul(mid,change(pa[i%L]));
            if(mid!=3) ans=false;
        }
        else
        {
            int full = 1;
            for(int i=0;i<L;i++) full = mul(full,change(pa[i]));
            LL segL = pl/L;
            LL segR = pr/L;
            LL MIDNUM = (segR-segL-1)%4;
            LL L_last = ((segL+1LL)*L);
            for(LL i=pl;i<L_last;i++)  mid= mul(mid,change(pa[i%L]));
            for(int k=0;k<MIDNUM;k++)  mid= mul(mid,full);
            for(LL i=segR*L;i<=pr;i++) mid= mul(mid,change(pa[i%L]));
            if(mid!=3) ans =false;
        }


        printf("Case #%d: %s\n",cas,ans?"YES":"NO");
    }

    return 0;
}
