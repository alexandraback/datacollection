#include <bits/stdc++.h>

using namespace std;

int m[50][50], n, l[50], c[50];

void mostrar(int m[50][50])
{
    int i, j;
    cout<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool comp(vector<int> a, vector<int> b)
{
    int i;
    for(i=0;i<a.size();i++)
    {
        if(a[i]<b[i])
            return true;
    }
    return false;
}

bool encL(vector<int> a, int m[50][50], int in)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<in;j++)
        {
            if(m[j][i]>=a[i])
                return false;
        }
        if(m[in][i]!=0 && m[in][i]!=a[i])
            return false;
    }
    return true;
}

bool encC(vector<int> a, int m[50][50], int in)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<in;j++)
        {
            if(m[i][j]>=a[i])
                return false;
        }
        if(m[i][in]!=0 && m[i][in]!=a[i])
            return false;
    }
    return true;
}

bool chamada(vector<int> v[2500], int i)
{
    if(i==2*n-1)
        return true;
    bool entrou = false;
    int copia[50][50], q, w, j, k;
    for(q=0;q<n;q++)
    {
        for(w=0;w<n;w++)
        {
            copia[q][w] = m[q][w];
        }
    }
    for(j=0;j<n && !entrou;j++)
    {
        if(encL(v[i], m, j) && l[j]==0)
        {
            l[j] = 1;
            for(k=0;k<n;k++)
            {
                m[j][k] = v[i][k];
            }
            //mostrar(m);
            entrou = chamada(v, i+1);
            if(!entrou)
            {
                l[j] = 0;
                for(q=0;q<n;q++)
                {
                    for(w=0;w<n;w++)
                    {
                        m[q][w] = copia[q][w];
                    }
                }
            }
        }
        if(!entrou && encC(v[i], m, j) && c[j]==0)
        {
            c[j] = 1;
            for(k=0;k<n;k++)
            {
                m[k][j] = v[i][k];
            }
            //mostrar(m);
            entrou = chamada(v, i+1);
            if(!entrou)
            {
                c[j] = 0;
                for(q=0;q<n;q++)
                {
                    for(w=0;w<n;w++)
                    {
                        m[q][w] = copia[q][w];
                    }
                }
            }
        }
    }
    return entrou;
}

void resolver(int t)
{
    int i, j, a, k;
    vector<int> v[2500];
    memset(l, 0, sizeof(l));
    memset(c, 0, sizeof(c));
    memset(m, 0, sizeof(m));
    cin>>n;
    for(i=0;i<2*n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a;
            v[i].push_back(a);
        }
    }
    sort(v, v+2*n-1, comp);
    for(i=0;i<n;i++)
    {
        m[0][i] = v[0][i];
    }
    l[0] = 1;
    //mostrar(m);
    chamada(v, 1);
    /*for(i=1;i<2*n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            if(encL(v[i], m, j) && l[j]==0)
            {
                l[j] = 1;
                for(k=0;k<n;k++)
                {
                    m[j][k] = v[i][k];
                }
                j = n;
            }
            else if(encC(v[i], m, j) && c[j]==0)
            {
                c[j] = 1;
                for(k=0;k<n;k++)
                {
                    m[k][j] = v[i][k];
                }
                j = n;
            }
        }
        mostrar(m);
    }*/
    cout<<"Case #"<<t<<":";
    for(i=0;i<n;i++)
    {
        if(l[i]==0)
            for(j=0;j<n;j++)
            {
                cout<<" "<<m[i][j];
            }
        if(c[i]==0)
            for(j=0;j<n;j++)
            {
                cout<<" "<<m[j][i];
            }
    }
    cout<<endl;
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
