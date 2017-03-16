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
double arr[100001];
double bnr[100001];
int main()
{
    int tc;
    cin>>tc;
    int count=1;
    while (tc--)
    {
        int a,b;
        cin>>a>>b;
        bnr[0]=1;
        for (int i=1;i<=a;i++)
        {
            cin>>arr[i];
            bnr[i] = bnr[i-1]*arr[i];
        }
        double ans=b+2.0;
        for (int i=0;i<=a;i++)
        {
            double benar, salah;
            int sb, ss;
            sb = b-a+1 + (2*i);
            ss = sb+b+1;
            double temp = ss*(1-bnr[a-i]) + sb*bnr[a-i];
            //cout<<ss<<" "<<sb<<" "<<temp<<endl;
            ans = min(ans, temp);
        }
        printf("Case #%d: %.6lf\n", count++, ans);
        
    }
    
    //system("pause");
    return 0;
}
