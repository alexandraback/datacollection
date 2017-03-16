#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int T,n,m;
int h;

struct dtype
{
    int a,b;
};

int c[200][200];
int f[200][200];
int v[200][200];
double t[200][200];
dtype q[2000000];
const double zero=1e-9;

int inmap(dtype d)
{
    return (d.a>=1 && d.a<=n && d.b>=1 && d.b<=m);
}

double cango(dtype s,dtype tt)
{
    double t0=t[s.a][s.b];
    double h0=h-t0*10;
    if (f[s.a][s.b]+50>c[tt.a][tt.b]) return -1;
    if (c[s.a][s.b]-50<f[tt.a][tt.b]) return -1;
    if (f[tt.a][tt.b]+50>c[tt.a][tt.b]) return -1;
    
    double tm1=0,tm2=0;
    if (h0+50>c[tt.a][tt.b]+zero) tm1=(50-(c[tt.a][tt.b]-h0))/10.0;
    
    if (h0-tm1*10>f[s.a][s.b]+20-zero) tm2=1;else tm2=10;
    if (t0+tm1<zero) tm2=0;
    return t0+tm1+tm2;
}

void spfa()
{
    int o,c;
    o=1;c=0;
    v[1][1]=1;
    q[1].a=1;q[1].b=1;
    
    while (c<o)
    {
        c++;
        dtype tmp;
        
        tmp.a=q[c].a+1;
        tmp.b=q[c].b;
        if (inmap(tmp))
        {
            double tt=cango(q[c],tmp);
            if (tt>-1e-8 && (v[tmp.a][tmp.b]==0 || t[tmp.a][tmp.b]>tt))
            {
            
                t[tmp.a][tmp.b]=tt;
                if (v[tmp.a][tmp.b]!=1)
                {
                    o++;
                    q[o]=tmp;
                }
                v[tmp.a][tmp.b]=1;
            }
        }
        
        tmp.a=q[c].a-1;
        tmp.b=q[c].b;
        if (inmap(tmp))
        {
            double tt=cango(q[c],tmp);
            if (tt>-1e-8 && (v[tmp.a][tmp.b]==0 || t[tmp.a][tmp.b]>tt))
            {
            
                t[tmp.a][tmp.b]=tt;
                if (v[tmp.a][tmp.b]!=1)
                {
                    o++;
                    q[o]=tmp;
                }
                v[tmp.a][tmp.b]=1;
            }
        }
        
        tmp.a=q[c].a;
        tmp.b=q[c].b+1;
        if (inmap(tmp))
        {
            double tt=cango(q[c],tmp);
            if (tt>-1e-8 && (v[tmp.a][tmp.b]==0 || t[tmp.a][tmp.b]>tt))
            {
            
                t[tmp.a][tmp.b]=tt;
                if (v[tmp.a][tmp.b]!=1)
                {
                    o++;
                    q[o]=tmp;
                }
                v[tmp.a][tmp.b]=1;
            }
        }
                
        tmp.a=q[c].a;
        tmp.b=q[c].b-1;
        if (inmap(tmp))
        {
            double tt=cango(q[c],tmp);
            if (tt>-1e-8 && (v[tmp.a][tmp.b]==0 || t[tmp.a][tmp.b]>tt))
            {
            
                t[tmp.a][tmp.b]=tt;
                if (v[tmp.a][tmp.b]!=1)
                {
                    o++;
                    q[o]=tmp;
                }
                v[tmp.a][tmp.b]=1;
            }
        }
        
        v[q[c].a][q[c].b]=2;
    }
    
    if (0) for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) cout << t[i][j] << ' ' ;
        cout << endl;
    }
}
                
        

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("Bsmall1.txt","w",stdout);
    cin >> T;
    int Ncase=0;
    while (Ncase<T)
    {
        Ncase++;
        
        cin >> h >> n >> m;
        
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> c[i][j];
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> f[i][j];
        
        memset(t,0,sizeof t);
        memset(v,0,sizeof v);
        
        spfa();
        
        printf("Case #%d: %.7lf\n",Ncase,t[n][m]);
    }
}
