#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("in6.in", "r", stdin);
    freopen("out6.txt", "w", stdout);
    int t=1, n, i, j, k, l, m, c, d;
    cin>>t;
    string x[20], y[20], p[20], q[20];
    for(l=1; l<=t; l++)
    {
        c=d=0;
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>x[i]>>y[i];
            p[i]=x[i];
            q[i]=y[i];

        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                for(k=0; k<n; k++)
                {
                    if(j!=i && k!=i)
                    {
                        if(x[i]==x[j] && y[i]==y[k])
                        {
                            c++;
                            x[i]="";
                            y[i]="";
                            for(m=0; m<c; m++)
                            {
                                x[i]+="1";
                                y[i]+="1";
                            }
                        }
                    }
                }
            }
        }
        for(i=n-1; i>=0; i--)
        {
            for(j=0; j<n; j++)
            {
                for(k=0; k<n; k++)
                {
                    if(j!=i && k!=i)
                    {
                        if(p[i]==p[j] && q[i]==q[k])
                        {
                            d++;
                            p[i]="";
                            q[i]="";
                            for(m=0; m<d; m++)
                            {
                                p[i]+="1";
                                q[i]+="1";
                            }
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<l<<": "<<max(c,d)<<endl;

    }
    return 0;
}
