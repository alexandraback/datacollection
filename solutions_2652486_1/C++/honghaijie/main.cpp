#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

int r,n,m,k;
int sz[100];

struct mp
{
    mp(int ix, int iy):x(ix),y(iy) {}
    int x,y;
};

bool isprime(int x)
{
    bool flag=true;
    for (int i=2;i<=sqrt(x);i++)
    {
        if (x%i==0) {flag=false; break;}
    }
    return flag;
}

int operator<(const mp& a, const mp& b)
{
    return a.x<b.x || (a.x==b.x && a.y>b.y);
}

int main()
{
    freopen("C-small-2-attempt0.in","r",stdin);
    freopen("C-small-2-attempt0.out","w",stdout);
    int T;
    cin>>T;
    while (T--)
    {
        cin>>r>>n>>m>>k;
        printf("Case #1:\n");

        for (int cc=0; cc<r; cc++)
        {
            for (int i=0; i<k; i++)
            {
                cin>>sz[i];
            }
            vector< mp > fac;
            for (int i=2; i<=m; i++)
            {
                int flag=0;
                for (int j=0; j<k; j++)
                {
                    if (sz[j]%i==0)
                    {
                        flag++;
                    }
                }
                if (flag!=0 && isprime(i)) fac.push_back( mp(10000+flag,i) );
                else fac.push_back( mp(flag,i) );
            }
            sort(fac.begin(),fac.end());
            reverse(fac.begin(),fac.end());
            while (fac[fac.size()-1].x==0 )
            {
                fac.pop_back();
            }
            for (int i=0;i<n;i++)
            {
                int ni=i%fac.size();
                cout<<fac[ni].y;
            }
            cout<<endl;
        }

    }

    fclose(stdin);
    fclose(stdout);
}

