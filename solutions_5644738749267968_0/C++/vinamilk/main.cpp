#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <sstream>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long

using namespace std;

const int nm=1002;

int n;double a[nm],b[nm];

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("vd.out","w",stdout);
    int t,it,i,j,d;
    scanf("%d",&t);
    for(it=1;it<=t;++it)
    {
        scanf("%d",&n);
        for(i=1;i<=n;++i) scanf("%lf",&a[i]);
        for(i=1;i<=n;++i) scanf("%lf",&b[i]);
        sort(a+1,a+n+1);sort(b+1,b+n+1);
        i=j=1;d=0;
        while (i<=n && j<=n)
        {
            if (a[i]<b[j]) {}
            else
            {
                d++;j++;
            }
            i++;
        }
        printf("Case #%d: %d ",it,d);
        i=j=1;d=0;
        while (i<=n && j<=n)
        {
            while (j<=n && b[j]<a[i]) j++;
            if (j>n) break;
            j++;i++;
        }
        printf("%d\n",n-i+1);
    }
}
