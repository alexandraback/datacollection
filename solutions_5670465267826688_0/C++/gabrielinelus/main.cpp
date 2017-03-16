#include <cstdio>
#include <cstring>

#define Nmax 10005

using namespace std;

int N,L;
char aux[Nmax],c[Nmax];
int nou[Nmax];

int calc(int a,int b)
{
    int sgn1 = 1,sgn2 = 1;

    if(a < 0){
        sgn1 *= -1;
        a *= -1;
    }
    if(b < 0){
        sgn2 *= -1;
        b *= -1;
    }


    if( a == 1 )
        return b*sgn1*sgn2;
    if( b == 1 )
        return a*sgn1*sgn2;
    if(a == 2)
    {
        if(b == 2)
            return -1*sgn1*sgn2;
        if(b == 3)
            return 4*sgn1*sgn2;
        return -3*sgn1*sgn2;
    }
    if(a == 3)
    {
        if(b == 2)
            return -4*sgn1*sgn2;
        if(b == 3)
            return -1*sgn1*sgn2;
        return 2*sgn1*sgn2;
    }
    if(b == 2)
        return 3*sgn1*sgn2;
    if(b == 3)
        return -2*sgn1*sgn2;
    return -1*sgn1*sgn2;
}
int codif(char cr)
{
    if( cr == 'i' )
        return 2;
    if( cr == 'j' )
        return 3;
    return 4;
}

int solve()
{
    int rez = 1,rez2 = 1;
    int pzi = N + 1,pzk = 0;
    for(int i = 1; i <= N; ++i)
    {
        nou[i] = codif(c[i]);
        rez = calc(rez,nou[i]);
        if(rez == 2 && pzi == N + 1)
            pzi = i;
        nou[N-i+1] = codif(c[N-i+1]);
        rez2 = calc(nou[N-i+1],rez2);
        if(rez2 == 4 && pzk == 0)
            pzk = N - i + 1;
    }
    if(rez == -1 && pzi < pzk)
        return 1;
    return 0;
}

int main()
{
    freopen("dijkstra.in","r",stdin);
    freopen("dijkstra.out","w",stdout);

    int T;
    scanf("%d",&T);
    for(int tst = 1; tst <= T; ++tst)
    {
        c[0] = 0;
        scanf("%d%d\n%s\n",&N,&L,&aux);
        N = N * L;
        c[0] = '#';
        c[1] = 0;
        for(int i = 1; i <= L; ++i)
            strcat(c,aux);
        if(solve())
            printf("Case #%d: YES\n",tst);
        else
            printf("Case #%d: NO\n",tst);
    }
    return 0;
}
