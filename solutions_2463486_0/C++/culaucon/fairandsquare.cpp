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
#include <cstring>

using namespace std;
typedef long long LL;

LL a[39]={1LL,4LL,9LL,121LL,484LL,10201LL,12321LL,14641LL,40804LL,44944LL,1002001LL,1234321LL,4008004LL,100020001LL,102030201LL,104060401LL,121242121LL,123454321LL,125686521LL,400080004LL,404090404LL,10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};
/*bool check(LL n)
{
    vector<int> a;
    while (n>0)
    {
        a.push_back(n%10);
        n/=10;
    }
    for (int i=0;i<a.size();i++)
        if (a[i]!=a[a.size()-i-1]) return 0;
    return 1;
}*/
int go(LL n)
{
    for (int i=0;i<39;i++)
        if (a[i]>n) return i;
    return 39;
}
int main()
{
    freopen("fairandsquare.in","r",stdin);freopen("fairandsquare.out","w",stdout);
    int nt, tt=1;
    cin>>nt;
    while (nt--)
    {
        LL x, y;
        cin>>x>>y;
        cout<<"Case #"<<tt++<<": "<<go(y)-go(x-1)<<endl;
    }
}
