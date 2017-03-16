
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <string>
#include <map>
#include <assert.h>
#include <time.h>
#include <list>
#include <deque>


#include <fstream>
#include <sstream>

#include <iomanip>


#define FFF freopen("test","r",stdin)
using namespace std;

const int N=55;
const int mod=1000000007;






int n;



int b[2505];
vector<int> ans;

void deal()
{
    scanf("%d",&n);
    memset(b,0,sizeof(b));
    for(int i=1;i<=n*2-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            b[x]++;
        }
    }
    ans.clear();
    for(int i=1;i<=2500;i++) if(b[i]&1) ans.push_back(i);
    assert(ans.size()==n);
    for(int i=1;i<=n;i++) printf(" %d",ans[i-1]);
    puts("");

}

int main()
{


    freopen("B-large.in","r",stdin);;
    freopen("ans","w",stdout);
    int T;
    scanf("%d",&T);
    int num=0;
    while(T--)
    {
        printf("Case #%d:",++num);
        deal();
    }
}
