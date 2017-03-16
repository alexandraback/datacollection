// RandomUsername (Nikola Jovanovic)
// GCJ 2016 1B
// B

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(long long i=a; i<=b; i++)
#define fb(i,a,b) for(long long i=a; i>=b; i--)
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXN 30

using namespace std;

lld t;
char c[MAXN];
char j[MAXN];
char kc[MAXN];
char kj[MAXN];
char sc[MAXN];
char sj[MAXN];
lld n;

bool DFS(lld i, lld dir)
{
    if(dir == 420) return false;
    //dir = 0 OK
    //dir = 1 C NAMESTI DA BUDE VECI
    //dir = -1 C NAMESTI DA BUDE MANJI
    if(i == n)
    {
        // end
        return true;
    }
    if(dir == 0)
    {
        // try to be the same
        if(c[i] == '?' && j[i] == '?')
        {
            c[i] = '0';
            j[i] = '0';
            DFS(i+1, 0);
        }
        else if(c[i] == '?')
        {
            c[i] = j[i];
            DFS(i+1, 0);
        }
        else if(j[i] == '?')
        {
            j[i] = c[i];
            DFS(i+1, 0);
        }
        else
        {
            if(c[i] == j[i])
                DFS(i+1, 0);
            else if(c[i] < j[i])
                DFS(i+1, 1);
            else
                DFS(i+1, -1);
        }
    }
    else if(dir == 1)
    {
        // NAMESTI DA C BUDE STO VECI DA UBLAZIS RAZLIKU KOJA POSTOJI
        if(c[i] == '?' && j[i] == '?')
        {
            c[i] = '9';
            j[i] = '0';
            DFS(i+1, 1);
        }
        else if(c[i] == '?')
        {
            c[i] = '9';
            DFS(i+1, 1);
        }
        else if(j[i] == '?')
        {
            j[i] = '0';
            DFS(i+1, 1);
        }
        else
        {
            DFS(i+1, 1);
        }
    }
    else
    {
        // NAMESTI DA C BUDE STO manji DA UBLAZIS RAZLIKU KOJA POSTOJI
        if(c[i] == '?' && j[i] == '?')
        {
            c[i] = '0';
            j[i] = '9';
            DFS(i+1, -1);
        }
        else if(c[i] == '?')
        {
            c[i] = '0';
            DFS(i+1, -1);
        }
        else if(j[i] == '?')
        {
            j[i] = '9';
            DFS(i+1, -1);
        }
        else
        {
            DFS(i+1, -1);
        }
    }
    return true;
}

lld modify(lld z)
{
    // returns dir or -1
    ff(i, 0, n-1)
    {
        if(c[i] != '?' && j[i] != '?' && c[i] != j[i])
        {
            // OVDE PRAVIMO MODIFIKACIJU SIGURNO, ako ne moze jbg
            if(c[i] < j[i])
            {
                // pravimo prednost za C sto manju pa C sto manje pa J sto manje
                lld it = i - z;
                while(it > 0)
                {
                    if(c[it-1] == '?' && j[it-1] == '?')
                    {
                        c[it-1] = '1';
                        j[it-1] = '0';
                        return 0;
                    }
                    else if(c[it-1] == '?')
                    {
                        if(j[it-1] == '9')
                            return 420;
                        c[it-1] = j[it-1] + 1;
                        return 0;
                    }
                    else if(j[it-1] == '?')
                    {
                        if(c[it-1] == '0')
                            return 420;
                        j[it-1] = c[it-1] - 1;
                        return 0;
                    }
                    else if(c[it-1] > j[it-1])
                        return 0;
                    else if(c[it-1] < j[it-1])
                        return 420;
                    else if(c[it-1] == j[it-1])
                        it--;
                }
            }
            else if(c[i] > j[i])
            {
                // pravimo loss za C sto manju pa C sto manje pa J sto manje
                lld it = i - z;
                while(it > 0)
                {
                    if(c[it-1] == '?' && j[it-1] == '?')
                    {
                        c[it-1] = '0';
                        j[it-1] = '1';
                        return 0;
                    }
                    else if(c[it-1] == '?')
                    {
                        if(j[it-1] == '0')
                            return 420;
                        c[it-1] = j[it-1] - 1;
                        return 0;
                    }
                    else if(j[it-1] == '?')
                    {
                        if(c[it-1] == '9')
                            return 420;
                        j[it-1] = c[it-1] + 1;
                        return 0;
                    }
                    else if(c[it-1] > j[it-1])
                        return 420;
                    else if(c[it-1] < j[it-1])
                        return 0;
                    else if(c[it-1] == j[it-1])
                        it--;
                }
            }
            return 420;
        }
    }
    return 420;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B_new.out", "w", stdout);
    scanf("%lld", &t);
    ff(tt, 1, t)
    {
        scanf("%s", c);
        scanf("%s", j);
        strcpy(kc, c);
        strcpy(kj, j);
        n = strlen(c);
        DFS(0, 0);
       // cout<<"AFTER:"<<endl;

        lld C = 0;
        ff(i, 0, n-1)
            C = C * 10 + (c[i] - '0');
        lld J = 0;
        ff(i, 0, n-1)
            J = J * 10 + (j[i] - '0');
        lld diff = round(abs(C - J));
       // cout<<"original "<<diff<<" : "<<C<<" "<<J<<endl;

        // drugo resenje?
        strcpy(sc, c);
        strcpy(sj, j);
        ff(z, 0, n)
        {
            strcpy(c, kc);
            strcpy(j, kj);
            if( DFS(0, modify(z)) )
            {
                lld CC = 0;
                ff(i, 0, n-1)
                    CC = CC * 10 + (c[i] - '0');
                lld JJ = 0;
                ff(i, 0, n-1)
                    JJ = JJ * 10 + (j[i] - '0');
                lld diff2 = round(abs(CC - JJ));

                //cout<<"new "<<diff2<<" : "<<CC<<" "<<JJ<<endl;
             //   cout<<diff<<" "<<diff2<<" "<<C<<" "<<J<<" "<<CC<<" "<<JJ<<endl;

                // bolji od(sc, sj), (c, j)
                if(diff2 < diff || (diff2 == diff && CC < C) ||
                (diff2 == diff && CC == C && JJ < J)    )
                {
                    diff = diff2;
                    strcpy(sc, c);
                    strcpy(sj, j);
                }
            }
        }
         printf("Case #%lld: %s %s\n", tt, sc, sj);
    }
    return 0;
}