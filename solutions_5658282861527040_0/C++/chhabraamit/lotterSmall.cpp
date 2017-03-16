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
#include <climits>
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
int ABS(int a) {if(a >0) return a; return -a;}



int main()
{
    freopen("lotteryInput.txt", "r", stdin);
    freopen("lotteryOutput.txt", "w", stdout);
    int test;
    scanf("%d",&test);

    for(int running=1; running<=test; running++)
    {
       int a,b,k;
       cin>>a>>b>>k;
       int ans =0;
       for(int i=0; i<a;i++)
       {
           for(int j=0; j<b; j++)
           {
               if( (i & j) < k)
                ans++;
           }
       }
       printf("Case #%d: %d\n", running, ans);
    }

    return 0;
}

