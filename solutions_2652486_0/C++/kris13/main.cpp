#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long r,n,m,k,i,j,mas[10],a[10],mas2[10],ans;
int main()
{
    //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
    cout << "Case #" << 1 << ":\n";
    cin >>r;
    cin >> r >> n >> m >> k;
    for (i=0;i<r;i++)
    {
        for (j=0;j<k;j++)
            cin >> a[j];
        for (j=2;j<=m;j++)
            mas[j]=0;
        for (j=0;j<k;j++)
        {
            int t=a[j],kof=2;
            while (t!=1)
            {
                if (t%kof==0)
                {
                    t/=kof;
                    mas2[kof]++;
                }
                else
                    kof++;
            }
            for (int u=2;u<=m;u++)
            {
                mas[u]=max(mas[u],mas2[u]);
                mas2[u]=0;
            }
        }
        if (mas[2]>0 && mas[3]>0 && mas[5]>0)
        {
            ans=1;
            for (int u=0;u<mas[2];u++)
                ans*=2;
            cout << ans;
            ans=1;
            for (int u=0;u<mas[3];u++)
                ans*=3;
            cout << ans;
            ans=1;
            for (int u=0;u<mas[5];u++)
                ans*=5;
            cout << ans;
        }
        else
            if (mas[5]>0 && mas[3]>0)
                if (mas[5]>1)
                {
                    cout << "5";
                    ans=1;
                    for (int u=0;u<mas[3];u++)
                        ans*=3;
                    cout << ans;
                    ans=1;
                    for (int u=0;u<mas[5]-1;u++)
                        ans*=5;
                    cout << ans;
                }
                else
                {
                    cout << "3";
                    ans=1;
                    for (int u=0;u<mas[3]-1;u++)
                        ans*=3;
                    cout << ans;
                    ans=1;
                    for (int u=0;u<mas[5];u++)
                        ans*=5;
                    cout << ans;
                }
            else
                if (mas[2]>0 && mas[3]>0)
                    if (mas[2]>1)
                    {
                        cout << "2";
                        ans=1;
                        for (int u=0;u<mas[3];u++)
                            ans*=3;
                        cout << ans;
                        ans=1;
                        for (int u=0;u<mas[2]-1;u++)
                            ans*=2;
                        cout << ans;
                    }
                    else
                    {
                        cout << "3";
                        ans=1;
                        for (int u=0;u<mas[3]-1;u++)
                            ans*=3;
                        cout << ans;
                        ans=1;
                        for (int u=0;u<mas[2];u++)
                            ans*=2;
                        cout << ans;
                    }
                else
                    if (mas[5]>0 && mas[2]>0)
                        if (mas[5]>1)
                        {
                            cout << "5";
                            ans=1;
                            for (int u=0;u<mas[2];u++)
                                ans*=2;
                            cout << ans;
                            ans=1;
                            for (int u=0;u<mas[5]-1;u++)
                                ans*=5;
                            cout << ans;
                        }
                        else
                        {
                            cout << "2";
                            ans=1;
                            for (int u=0;u<mas[2]-1;u++)
                                ans*=2;
                            cout << ans;
                            ans=1;
                            for (int u=0;u<mas[5];u++)
                                ans*=5;
                            cout << ans;
                        }
                    else
                        if (mas[5]>0)
                        {
                            cout << "55";
                            ans=1;
                            for (int u=0;u<mas[5]-2;u++)
                                ans*=5;
                            cout << ans;
                        }
                        else
                            if (mas[2]>0)
                            {
                                cout << "22";
                                ans=1;
                                for (int u=0;u<mas[2]-2;u++)
                                    ans*=2;
                                cout << ans;
                            }
                            else
                                if (mas[3]>0)
                                {
                                    cout << "33";
                                    ans=1;
                                    for (int u=0;u<mas[3]-2;u++)
                                        ans*=3;
                                    cout << ans;
                                }
                                else
                                {cout << "222";}
        cout << endl;
    }
    return 0;
}

