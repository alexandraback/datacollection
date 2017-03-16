#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long int pow2(unsigned long int n)
{
    if (n==0){return 1;}
    if (n%2==0){unsigned long int y=pow2(n/2);return y*y;}
    if (n%2==1){return 2*pow2(n-1);}
}

string otv[60];


int main()
{
for (int i=0;i<60;i++){otv[i]="00000000000000000000000000000000000000000000000000000000000000000000000";}
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    cin >> t;
    for (int i=0;i<58;i++)
    {
        for (int j=i+1;j<58;j++)
        {
            otv[i][j]='1';
        }
    }
    for (int gp=1;gp<=t;gp++)
    {
        unsigned long long int n,m;
        cin>> n >> m;
        cout << "Case #" << gp << ": ";
        unsigned long long int q=pow2(n-2);
        if(q<m){cout  << "IMPOSSIBLE" << endl;continue;}
        if(q==m)
        {cout << "POSSIBLE" << endl;
        cout << 0;
            for (int i=2;i<=n;i++){cout << 1;}cout << endl;
            for (int i=2;i<=n;i++){cout << otv[i].substr(1,n) << endl;}continue;
        }
        cout << "POSSIBLE" << endl;
        string h="";
        for (int i=0;i<n-2;i++)
        {
            if (m%2==1)
            {
                h='1'+h;
            }else{h='0'+h;}
            m/=2;
        }
        cout << 0 << h << 0 << endl;
        for (int i=1;i<n;i++)
        {
            cout << otv[i].substr(0,n) << endl;;
        }
    }
    return 0;
}
