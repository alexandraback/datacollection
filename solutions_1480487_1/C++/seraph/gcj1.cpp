// Template By Fendy Kosnatha (Seraph)
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
#include <cstring>
#include <string.h>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>

using namespace std;
double arr[300];
int main()
{
    int tc;
    cin>>tc;
    int count=1;
    while (tc--)
    {
        int n;
        cin>>n;
        double temp=0;
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
            temp+=arr[i];
        }
        double t = temp;
        temp*=2;
        temp/=n;
        double tt=0;
        cout<<"Case #"<<count++<<":";
        vector<double> ans;
        double minus = 0;
        double byk=0;
        for (int i=0;i<n;i++)
        {
            double a;
            a = (temp-arr[i])/t;
            a*=100;
            if (a<0) {minus+=a;byk+=1;}
            ans.push_back(a);
        }
        double ts = minus/(n-byk);
        for (int i=0;i<n;i++)
        {
            if (ans[i]<0) printf(" %.6lf", 0.0000000);
            else
            {
                printf(" %.6lf", ans[i]+ts);
            }
        }
        cout<<endl;
    }
    return 0;
}
