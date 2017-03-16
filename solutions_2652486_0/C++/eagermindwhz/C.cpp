#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n, a[100],v[100],m,k,r;
void check(int t)
{
    for (int i = 0; i < k; i++)
        if (a[i] == t) v[i] =1;
}

int main()
{
    freopen("C1.in","r",stdin);
    freopen("C1.txt","w",stdout);
    int T;
    cin>>T;

    for (int cas = 1; cas <= T; cas++)
    {
        cout<<"Case #"<<cas<<":"<<endl;
        cin>>r>>n>>m>>k;
        int tt;
        for (tt = 0; tt<r; tt++)
        {
            int x,y,z,i;
            for (i = 0; i < k ; i++) cin>>a[i];
            memset(v,0,sizeof(v));
            int flag = 0;
            for (x = m; x >=2; x--){
                for (y = m; y >=2; y--){
                    for (z = 2; z<= m; z++)                    {
                        int t = x*y*z;
                        check(t);
                        t = x;
                        check(t);
                        t = y;
                        check(t);
                        t = z;
                        check(t);
                        t = x*y;
                        check(t);
                        t = x*z;
                        check(t);
                        t = y*z;
                        check(t);
                        t = 1;
                        check(t);
                        flag = 1;
                        for (i = 0; i < k; i++) if (!v[i]) flag = 0;
                        if (flag) break;
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
            cout<<x<<y<<z<<endl;
        }
    }
    return 0;
}
