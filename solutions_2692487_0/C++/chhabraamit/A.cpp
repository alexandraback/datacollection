#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <string.h>

#define SZ(c) c.size()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define SORT(a) sort(a.begin(),a.end())
#define tests int test; scanf("%d",&test); while(test--)
#define dbg(n) cout<<#n<<" = "<<n<<endl;

using namespace std;

int strToInt(string str) {int ans; stringstream s; s<<str; s>>ans; return ans;}
string intToStr(int n) {string str; stringstream s; s<<n; s>>str; return str;}
int MAX(int a,int b) {if(a >b) return a; return b;}
int MIN(int a,int b) {if(a <b) return a; return b;}
int ABS(int a,int b) {if(a >0) return a; return -a;}

int arr[1000];

int solve(int len, int val)
{
    int ans=0;
   for(int i=0;i<len;i++)
   {
       while(val <= arr[i])
       {
           if(val <=1) return 1000000;
           val += (val-1);
           ans++;
       }
       val += arr[i];
   }
   return ans;
}
int main()
{
    freopen("read.txt","r",stdin);
    freopen("write.txt","w",stdout);
    int test;
    scanf("%d",&test);
    int a,n;
    int caseNo=0;
    while(test--)
    {
        ++caseNo;
        scanf("%d %d",&a,&n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n);
        int ans = 1000,temp;
        for(int rem =0;rem <=n;rem++)
        {
            temp = rem;
            temp += solve(n-rem, a);
            ans = MIN(ans, temp);
        }
        printf("Case #%d: %d\n",caseNo,ans);
    }
    return 0;
}



