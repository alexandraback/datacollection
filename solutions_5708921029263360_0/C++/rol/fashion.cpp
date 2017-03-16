#include<cstdio>
#include<map>
#include<utility>
using namespace std;

int T, J, P, S, K, C=1;
int combos[1 << 10][1 << 2];

int solve(){
    int count = 0;
    map<pair<int, int>, int> JP, JS, PS;
    for(int j = 1; j <= J; ++j){
        for(int p = 1; p <= P; ++p){
            for(int s = 1; s <= S; ++s){
                pair<int, int> pr = make_pair(j, p);
                if(JP.count(pr)){
                    if(JP[pr] == K) continue;
                } else {
                    JP[pr] = 0;
                }
                pr = make_pair(j, s);
                if(JS.count(pr)){
                    if(JS[pr] == K) continue;
                } else {
                    JS[pr] = 0;
                }
                pr = make_pair(p, s);
                if(PS.count(pr)){
                    if(PS[pr] == K) continue;
                } else {
                    PS[pr] = 0;
                }
                combos[count][0] = j; combos[count][1] = p; combos[count][2] = s;
                ++JP[make_pair(j, p)]; ++JS[make_pair(j, s)]; ++PS[make_pair(p, s)];
                ++count;
            }
        }
    }
    return count;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d", &J, &P, &S, &K);
        int days = solve();
        printf("Case #%d: %d\n", C++, days);
        for(int i = 0; i < days; ++i) printf("%d %d %d\n", combos[i][0], combos[i][1], combos[i][2]);
    }
}
