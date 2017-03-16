#include <iostream>
#include <string>
#include <map>
using namespace std;

string s[2][20];
int N;
map<string, int> m[2];

int valid(int mask){
    m[0].clear();
    m[1].clear();
    int dup=mask;
    for(int i=0; i<N; i++){
        if(mask%2 == 0){
            m[0][s[0][i]]++;
            m[1][s[1][i]]++;
        }
        mask /= 2;
    }
    mask = dup;
    for(int i=0; i<N; i++){
        if(mask%2){
            if(m[0].find(s[0][i]) == m[0].end() || m[1].find(s[1][i]) == m[1].end()) return 0;
        }
        mask /= 2;
    }
    return 1;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        int max=0;
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            cin >> s[0][i];
            cin >> s[1][i];
        }
        for(int mask=0; mask<(1<<N); mask++){ // 1 = FAKE
            if(valid(mask) && __builtin_popcount(mask) > max) max = __builtin_popcount(mask);
        }
        printf("Case #%d: %d\n", test, max);
    }
}