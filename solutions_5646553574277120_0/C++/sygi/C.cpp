#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(I,N) for(int (I) = 0; (I) < (N); (I)++)

typedef pair<int,int> pii;
typedef long long ll;

bool can[37];
int v;
set<int> den;
void add(int x){
    den.insert(x);
    for(int i = v; i - x >= 0; i--){
        can[i] |= can[i-x];
    }
}
bool tryings[32][32];
bool canAll(int r){
    rep(i, v)
        if (!tryings[i+1][r]){
            return false;
        }
    return true;
}
void addNew(int den, int r){
    rep(i, v+1)
        tryings[i][r] = tryings[i][r-1];
    for(int i = v; i - den >= 0; i--){
        tryings[i][r] |= tryings[i-den][r];
    }
}
int best;
vector<int> possible;
bool usable[37];
void backtrack(int i, int fromWhere){ //now im filling i-th row
    if (canAll(i-1)){
        best = min(best, i-1);
        return;
    }
    if (i-1 >= best)
        return;

    for(int pos = fromWhere; pos < possible.size(); pos++){
        addNew(possible[pos], i);
        backtrack(i+1, pos + 1);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    can[0] = true;
    rep(testId,t){
        den.clear();
        printf("Case #%d: ", testId+1);
        int c,d;
        scanf("%d%d%d",&c,&d,&v);
        rep(i, v){
           can[i + 1] = false;
           usable[i] = true;
        }
        int x;
        rep(i, d){
            scanf("%d",&x);
            add(x);
        }
        best = v-1;
        possible.clear();
        rep(i, v){
            if (den.find(i+1) == den.end()){
                possible.pb(i+1);
            }
        }
        rep(i, v+1)
            tryings[i][0] = can[i];
        backtrack(1,0);
        printf("%d\n", best);
    }
}
