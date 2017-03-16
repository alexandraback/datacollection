#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define mp make_pair

int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    
    int _T;
    scanf("%d", &_T);
    for (int _t = 1; _t <= _T; _t++){
        int R,C,W;
        int ans = 0;
        scanf("%d%d%d", &R, &C, &W);
        ans += R * (C/W+(C%W?1:0));
        ans += W-1;
        printf("Case #%d: %d\n", _t, ans);
    }
    return 0;
}
