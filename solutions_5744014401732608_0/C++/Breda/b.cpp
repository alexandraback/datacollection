#include <bits/stdc++.h>

using namespace std;

int grafo[6][6];
int passou[100];

int passeio(int b, int a)
{
    int i, r, qtd = 0;
    if(a==b-1)
        return 1;
    for(i=0;i<b;i++)
    {
        if(grafo[a][i]==1 && passou[i]==0)
        {
            passou[i] = 1;
            r = passeio(b, i);
            passou[i] = 0;
            if(r==-1)
                return r;
            qtd+=r;
        }
        else if(grafo[a][i]==1 && passou[i]==1)
        {
            return -1;
        }
    }
    //printf("chegou\n");
    return qtd;
}

void mostrar(int b)
{
    int i, j;
    for(i=0;i<b;i++)
    {
        for(j=0;j<b;j++)
        {
            cout<<grafo[i][j];
        }
        cout<<endl;
    }
}

int rec(int b, int m, int i, int j)
{
    //mostrar(b);
    memset(passou, 0, sizeof(passou));
    passou[0] = 1;
    int t = passeio(b, 0);
    //cout<<t<<endl;
    //system("PAUSE");
    //if(t>0)
        //printf("achou!\n");
    if(t==m)
        return 1;
    int r1;
    if(j+1<b)
    {
        r1 = rec(b, m, i, j+1);
        if(r1==1)
            return 1;
    }
    else if(i+1<b)
    {
        r1 = rec(b, m, i+1, 0);
        if(r1==1)
            return 1;
    }
    if(i!=j && i!=b-1)
    {
        grafo[i][j] = 1;
        if(j+1<b)
        {
            r1 = rec(b, m, i, j+1);
            if(r1==1)
                return 1;
        }
        else if(i+1<b)
        {
            r1 = rec(b, m, i+1, 0);
            if(r1==1)
                return 1;
        }
        grafo[i][j] = 0;
    }
    return 0;
}

void resolver(int t)
{
    int b, m, i, j;
    cin>>b>>m;
    memset(grafo, 0, sizeof(grafo));
    int r = rec(b, m, 0, 0);
    cout<<"Case #"<<t<<": ";
    if(r==1)
    {
        cout<<"POSSIBLE"<<endl;
        for(i=0;i<b;i++)
        {
            for(j=0;j<b;j++)
            {
                cout<<grafo[i][j];
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
}

int main()
{
    int t, i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
