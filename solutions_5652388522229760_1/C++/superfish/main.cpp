#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i,n) for (int i=1;i<=(n);++i)
#define rep2(i,x,y) for (int i=(x);i<=(y);++i)
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;

void MAIN()
{
    int n;
    scanf("%d",&n);
    if (n==0) {printf("INSOMNIA\n"); return;}
    LL cur=n, state=0;
    while (state!=1023)
    {
        LL tmp=cur;
        while (tmp>0)
        {
            state|=1<<(tmp%10);
            tmp/=10;
        }
        cur+=n;
    }
    cout <<cur-n<<endl;
};

int main() {
    //freopen("C:\\Users\\Administrator\\ClionProjects\\gcj\\A-large.in","r",stdin);
    //freopen("C:\\Users\\Administrator\\ClionProjects\\gcj\\A-large.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    rep(i,tt)
    {
        printf("Case #%d: ",i);
        MAIN();
    }
    return 0;
}