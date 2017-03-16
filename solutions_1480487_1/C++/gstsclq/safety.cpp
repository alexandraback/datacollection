#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>

using namespace std;
typedef long long LL;

int main()
{
    freopen("safety.in","r",stdin);
    freopen("safety.out","w",stdout);
    int tc;
    cin>>tc;
    for (int tcc=1;tcc<=tc;tcc++)
    {
        int n;
        cin>>n;
        vector<int> v;
        int s=0;
        for (int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            v.push_back(k);
            s+=k;
        }
        cout<<"Case #"<<tcc<<": ";
        for (int i=0;i<n;i++)
        {
            double lo=0., hi=100.;
            for (int t=0;t<100;t++)
            {
                double mid=(lo+hi)/2;
                double sc=v[i]+s*mid/100., k=0;
                for (int j=0;j<n;j++)
                    if (i!=j && sc>v[j]) k+=(sc-v[j])*100./s;
//                cout<<i<<" "<<v[i]<<" "<<mid<<" "<<sc<<" "<<k<<endl;cin.get();
                if (k+mid>100) hi=mid;
                else lo=mid;
            }
            printf("%.6lf ",lo);
//            cout<<lo<<" ";
        }
        cout<<endl;
    }
}
