#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>

using namespace std;

int v[10];

void mostrar(multiset<int> f)
{
    multiset<int>::iterator it;
    for(it=f.begin();it!=f.end();it++)
    {
        printf("%d ", *it);
    }
    printf("\n");
}


int rec(multiset<int> fila, int a, int q)
{
    int menor, menor2, i, m3;
    int topo = *(fila.rbegin());
    //printf("Topo: %d\n", topo);
    //system("PAUSE");
    //mostrar(fila);
    if(topo<4)
        return topo+q-1;
    fila.erase(fila.find(topo));
    fila.insert(topo-a);
    fila.insert(a);
    menor = (*fila.rbegin())+q;
    for(i=2;i<=(*fila.rbegin())/2;i++)
    {
    //printf("%d\n", fila.size());
        menor2 = rec(fila, i, q+1);
        if(menor2<menor)
        {
            menor = menor2;
            m3 = i;
        }
    }
    fila.erase(fila.find(topo-a));
    fila.erase(fila.find(a));
    fila.insert(topo);
    return menor;
}

int func()
{
    int d, i, p, menor, m, topo, menor2;
    multiset<int> fila;
    scanf("%d", &d);
    for(i=0;i<d;i++)
    {
        scanf("%d", &p);
        fila.insert(p);
    }
    menor = *fila.rbegin();
    for(i=2;i<=(*fila.rbegin())/2;i++)
    {
        //printf("%d\n", fila.size());
        menor2 = rec(fila, i, 1);
        if(menor2<menor)
            menor = menor2;
    }
    /*int q = 0;
    while((*fila.rbegin())>3)
    {
        int topo = *(fila.rbegin());
        //printf("%d - %d\n", topo, v[topo]);
        mostrar(fila);
        fila.erase(fila.find(topo));
        fila.insert(topo-v[topo]);
        fila.insert(v[topo]);
        q++;
        if(*fila.rbegin()+q<menor)
            menor = *fila.rbegin()+q;
    }
    mostrar(fila);
    if(*fila.rbegin()+q<menor)
            menor = *fila.rbegin()+q;*/
    return menor;
}

int main()
{
    int t, i, j, m, m2, m3;
    scanf("%d", &t);
    /*for(i=9;i>=4;i--)
    {
        multiset<int> ms;
        ms.insert(i);
        m = i;
        for(j=2;j<=i/2;j++)
        {
            m2 = rec(ms, j, 1);
            if(m2<=m)
            {
                m = m2;
                m3 = j;
            }
        }
        v[i] = m3;
    }*/
    for(j=1;j<=t;j++)
    {
        int r = func();
        printf("Case #%d: %d\n", j, r);
    }
    return 0;
}
