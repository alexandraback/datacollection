#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

bool us[10000010];

int main() {
    int nt;
    scanf("%d",&nt);

    for (int ct=1;ct<=nt;ct++) {
        int a,b;

        scanf("%d%d",&a,&b);

        memset(us,0,sizeof(us));

        int a2=a,pow=1;
        while (a2>9) {
            a2/=10;
            pow*=10;
        }

        long long res=0;
        for (int i=a;i<=b;i++) {
            int q=0,x=i;
            
            while (!us[x]) {
                if (x>=a && x<=b) q++;
                us[x]=true;

                x=(x%10)*pow+(x/10);
            }
            res+=(q*(q-1))/2;
        }

        printf("Case #%d: %lld\n",ct,res);
    }
    return 0;
}

