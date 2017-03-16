#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> mapa;
int passou[1000001];
int cont = 0;

void resolver(int caso)
{
    int n;
    scanf("%d", &n);
    printf("Case #%d: %d\n", caso, mapa[n]);
}

int inv(int a)
{
    int r = 0;
    while(a>0)
    {
        r*=10;
        r+=a%10;
        a/=10;
    }
    return r;
}

void pre()
{
    queue<int> fila;
    fila.push(1);
    int v, iv;
    mapa[1] = 1;
    passou[1] = 1;
    cont++;
    while(!fila.empty())
    {
        if(cont==1000000)
            break;
        v = fila.front();
        fila.pop();
        if(mapa.count(v+1)==0)
        {
            if(v+1<=1000000)
            {
                cont++;
                passou[v+1] = 1;
            }
            fila.push(v+1);
            mapa[v+1] = mapa[v]+1;
        }
        iv = inv(v);
        if(mapa.count(iv)==0)
        {
            if(iv<=1000000)
            {
                cont++;
                passou[iv] = 1;
            }
            fila.push(iv);
            mapa[iv] = mapa[v]+1;
        }
    }
}

int main()
{
    pre();
    int t, i;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
