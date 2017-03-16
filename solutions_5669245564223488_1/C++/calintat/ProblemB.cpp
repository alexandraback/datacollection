#include <cstdio>
#include <cstring>
using namespace std;
struct ltr
{
    long long pos1;
    long long pos2;
    long long pos3;
    long long pos4;
};
char word[101];
ltr ap[26],v[101];
ltr set_zero();
long long t,i,j,k,T,N,M,P,ok,ok1,ok3,ok4,p1,p2,Nn,Nx,x;
int main()
{
    freopen("ProblemB.in","r",stdin);
    freopen("ProblemB.out","w",stdout);
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld",&N);
        Nn=N;
        for(i=1;i<=26;i++)
        ap[i]=set_zero();
        for(i=1;i<=N;i++)
        {
            scanf("%s",&word);
            M=strlen(word);
            v[i]=set_zero();
            for(j=0;j<=M-1;j++)
            {
                k=j;
                while(j<=M-2 && word[j]==word[j+1]) j++;
                if(k==0 && j==M-1)
                {
                    v[i].pos4=int(word[0])-96;
                    ap[int(word[0])-96].pos4++;
                }
                else
                {
                    if(k==0)
                    {
                        v[i].pos1=int(word[0])-96;
                        ap[int(word[0])-96].pos1++;
                    }
                    else if(j==M-1)
                    {
                        v[i].pos3=int(word[j])-96;
                        ap[int(word[j])-96].pos3++;
                    }
                    else
                    ap[int(word[j])-96].pos2++;
                }
            }
        }
        P=1;
        ok=1;
        for(j=1;j<=26 && ok;j++)
        {
            if(ap[j].pos2>1)
            ok=0;
            else
            {
                if(ap[j].pos2)
                {
                    if(ap[j].pos1 || ap[j].pos3 || ap[j].pos4)
                    ok=0;
                }
                else
                {
                    if(ap[j].pos1>1)
                    ok=0;
                    else if(ap[j].pos3>1)
                    ok=0;
                    else if(ap[j].pos4)
                    {
                        x=ap[j].pos4;
                        for(k=1;k<=x;k++)
                        P=P*k%1000000007;
                    }
                }
            }
            if(ok)
            {
                ok1=ap[j].pos1;
                ok3=ap[j].pos3;
                ok4=ap[j].pos4;
                Nx=0;
                for(k=1;k<=N;k++)
                {
                    if(ok1)
                    {
                        if(v[k].pos1==j)
                        {
                            p1=k;
                            Nx++;
                        }
                    }
                    if(ok3)
                    {
                        if(v[k].pos3==j)
                        {
                            p2=k;
                            Nx++;
                        }
                    }
                    if(ok4)
                    {
                        if(v[k].pos4==j)
                        {
                            v[k]=set_zero();
                            Nx++;
                        }
                    }
                }
                if(Nx!=0)
                Nn-=Nx-1;
                if(ok1 && ok3)
                {
                    if(p1!=p2)
                    {
                        v[p2].pos3=v[p1].pos3;
                        v[p1]=set_zero();
                    }
                    else
                    ok=0;
                }
            }
        }
        if(ok)
        {
            for(k=1;k<=Nn;k++)
            P=P*k%1000000007;
            printf("Case #%lld: %lld\n",t,P);
        }
        else
        printf("Case #%lld: 0\n",t);
    }
}
ltr set_zero()
{
    ltr myLetter;
    myLetter.pos1=0;
    myLetter.pos2=0;
    myLetter.pos3=0;
    myLetter.pos4=0;
    return myLetter;
}
