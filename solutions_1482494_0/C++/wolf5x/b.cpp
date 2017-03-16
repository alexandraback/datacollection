#line 2 "EllysJuice.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int T,N, A[1111],B[1111];
int lv[1111];

int main()
{
    freopen("B-small-attempt0.in", "r", stdin); freopen("b.out","w",stdout);
    scanf("%d", &T);
    FOR(CAS, 1, T){
        scanf("%d", &N);
        REP(i,N) scanf("%d%d", &A[i], &B[i]);
        memset(lv, 0, sizeof(lv));
        int ans = 0, star = 0;
        while(true){
            int id1 = -1, id2 = -1;
            REP(i,N){
                if(lv[i] < 2)
                    if(B[i] <= star)
                        id2 = i;
                if(lv[i] < 1)
                    if(A[i] <= star)
                        if(id1 == -1 || B[i] > B[id1])
                            id1 = i;
            }
            if(id1 < 0 && id2 < 0) break;
            if(id2 >= 0) star += 2-lv[id2], ans++, lv[id2] = 2;
            else if(id1 >= 0) star += 1-lv[id1], ans++, lv[id1] = 1;
        }
        bool flag = true;
        REP(i, N) if(lv[i] < 2) flag = false;
        printf("Case #%d: ", CAS);
        if(flag) printf("%d\n", ans);
        else printf("Too Bad\n");
    }
    return 0;
}
