#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
// complexity ~ O(T*pMax*D) small: 100*9*6 large: 100*1000*1000 
int main(int argc, char **argv)
{
    // [1, 100]
    int T;
    scanf("%d", &T);
    // cnt[0] = 0 reserved for inf, 
    // cnt[Pi] (Pi > 0) = number of diners with Pi pancakes
    for(int t = 1; t <= T; t++){
        // small [1, 6] large [1, 1000]
        int D;
        scanf("%d", &D);
        vector<int> P(D);
        // Pi small [1, 9] large [1, 1000]
        int pMax = 0;
        for(int i = 0; i < D; i++){
            scanf("%d", &P[i]);
            pMax = max(pMax, P[i]);
        }
        int ans = pMax; 
        for(int lastMax = 2; lastMax < pMax; lastMax ++){
            int cuts = 0;
            for(int i = 0; i < D; i++){
                if(P[i] > lastMax){
                    cuts += (P[i] + lastMax - 1)/lastMax - 1;
                }
            }
            ans = min(ans, cuts + lastMax);
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
