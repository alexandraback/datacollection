#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <cstring>

#define MAX
#define INF
#define MOD
#define MP make_pair
#define AA first
#define BB second
#define IS(X) cout << #X << " = " << X << endl;
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef queue<int> QI;
typedef priority_queue<int> PQI;
LL b,m;
int gra[55][55];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;cin >> t;
    int cc = 0;
    while(t--) {
        cin >> b >> m;
        for(int i = 0;i < b;i++) {
            for(int j = i+1;j < b;j++) {
                gra[i][j] = 1;
            }
        }
        LL ans = (1<<(b-2)) - m;
        //IS(ans);
        printf("Case #%d: ",++cc);
        if(ans < 0) {
            puts("IMPOSSIBLE");continue;
        } else {
            puts("POSSIBLE");
        }
        for(int i = 0;i < b-2;i++) {
            if((1 << i) & ans) {
                gra[i+1][b-1] = 0;
            }
        }
        for(int i = 0;i < b;i++) {
            for(int j = 0;j < b;j++) {
                printf("%d",gra[i][j]);
            }puts("");
        }
    }
    return 0;
}
