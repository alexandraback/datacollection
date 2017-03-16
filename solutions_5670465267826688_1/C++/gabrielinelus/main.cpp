#include <cstdio>
#include <cstring>

#define Nmax 100005

using namespace std;

long long N,L;
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
        ///if(i == 3292)
           /// printf("aici");
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
    {
         /// printf(">>%d %d %d<<",pzi,pzk,N);
        return 1;
    }
    return 0;
}
int solve2()
{
    int rez = 1,rez2 = 1;
    int pzi = N + 1,pzk = 0;
    for(int i = 1; i <= N; ++i)
    {
        ///if(i == 3292)
           /// printf("aici");
        nou[i] = codif(c[i]);
        rez = calc(rez,nou[i]);
        if(rez == 2 && pzi == N + 1)
            pzi = i;
        nou[N-i+1] = codif(c[N-i+1]);
        rez2 = calc(nou[N-i+1],rez2);
        if(rez2 == 4 && pzk == 0)
            pzk = N - i + 1;
    }
    if(pzi < pzk)
    {
          ///printf(">>%d %d %d<<",pzi,pzk,N);
        return 1;
    }
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
        scanf("%lld%lld\n%s\n",&N,&L,&aux);

        c[0] = '#';
        c[1] = 0;

        if( (long long)N*1LL*L <= 50000)
        {
            N = N * L;
            for(int i = 1; i <= L; ++i)
                strcat(c,aux);
            if(solve())
                printf("Case #%d: YES\n",tst);
            else
                printf("Case #%d: NO\n",tst);
        }
        else
        {
            int rez = 1,sgn = 1;
            for(int i = 0; i < N; ++i)
                rez = calc(rez,codif(aux[i]));
            if(rez < 0){
                rez *= -1;
                sgn *= -1;
            }

            if(L % 2 == 0 && sgn == -1)
                sgn = 1;

            if(rez != 1 && rez != -1)
            {
                if(L % 4 == 0)
                    rez = 1;
                else
                    if(L % 4 == 1)
                        rez = rez; /// neschimbat
                    else
                        if(L % 4 == 2)
                            rez = -1;
                        else
                            rez = -rez;
            }
            else
                if(L%2 == 0)
                    rez = 1;

            rez *= sgn;

            if(rez != -1)
            {
                printf("Case #%d: NO\n",tst);
                continue;
            }
            ///printf("Case #%d: MAYBE\n",tst);
            int times = 50000 / N;
            c[0] = '#';
            c[1] = 0;
            if(times > L)
                times = L;
            N = N*times;
            for(int i = 1; i <= times; ++i)
                strcat(c,aux);
            if(solve2())
                printf("Case #%d: YES\n",tst);
            else
                printf("Case #%d: NO\n",tst);
        }
    }
    return 0;
}
