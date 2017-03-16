#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

bool primoAux[MAX+1];
int primos[MAX+1], nPrimos;

void crivo()
{
    int m, i, j;

    memset(primoAux, true, sizeof(primoAux));
    primoAux[0] = primoAux[1] = false;
    nPrimos = 1;
    primos[0]=1;
    m = sqrt(MAX);

    for(i=2; i<=MAX; i++)
    {
        if(primoAux[i])
        {
            for(j=i*i; j<=MAX; j+=i)
            {
                primoAux[j] = false;
            }
        }
    }

    for(i=0; i<MAX; i++) if(primoAux[i]) primos[nPrimos++] = i;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    crivo();

    int t;
    scanf("%d",&t);

    for(int caso=1; caso<=t; caso++)
    {
        int c,d,v;

        scanf("%d%d%d",&c,&d,&v);

        bool can[v+1];
        memset(can, false, sizeof(can));
        can[0] = true;

        bool used[200];
        memset(used, false, sizeof(used));

        int cont=0, ans=0;

        for(int i=0; i<d; i++)
        {
            int x;
            scanf("%d",&x);

            used[x] = true;

            for(int j=v; j>=0; j--)
            {
                if(can[j] == true && j+x <= v && can[j+x] == false) can[j+x] = true;
            }
        }

        for(int i=0; i<nPrimos; i++)
        {
            int x = primos[i];

            if(x > v) break;

            if(used[x] == false)
            {
                used[x] = true;
                bool flag = false;

                for(int j=v; j>=0; j--)
                {
                    if(can[j] == true && j+x <= v && can[j+x] == false) flag=true, can[j+x] = true;
                }

                if(flag) ans++;
            }
        }

        for(int x=1; x<=v; x++)
        {
            if(can[x] == false)
            {
                for(int j=v; j>=0; j--)
                {
                    if(can[j] == true && j+x <= v && can[j+x] == false) can[j+x] = true;
                }
                ans++;
            }
        }

        printf("Case #%d: %d\n",caso,ans);
    }


    return 0;
}
