#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define pp pair<char,char>
#define f find
#define in insert
typedef long long LL;

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        cout<<"Case #"<<i<<": ";
        int n;
        cin>>n;
        vector<long double> s;
        s.resize(n);
        long double sum = 0;
        for (int k = 0; k < n; k++)
        {
            int temp;
            cin>>temp;
            sum+=temp;
            s[k] = temp;
        }
        long double sum_k = sum;
        int kol = 0;
        for (int k = 0; k < n; k++)
        {
            if (s[k]>=2.0*sum/(long double)n)
            {
                kol++;
                sum_k -= s[k];
            }
        }
        for (int k = 0; k < n; k++)
        {
            if ((2.0/(long double)n - s[k]/sum)*100.0 < 0) cout<<"0 ";
            else
            printf("%0.7Lf ",((((sum_k+sum)/(long double)(n-kol))-s[k])/sum)*100.0);
        }
        cout<<endl;
    }
    return 0;
}

