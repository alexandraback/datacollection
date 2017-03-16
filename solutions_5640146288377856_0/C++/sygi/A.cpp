#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(I,N) for(int (I) = 0; (I) < (N); (I)++)

typedef pair<int,int> pii;
typedef long long ll;

bool knowWay(int c, int w){
    if (w == 1) return true;
    if (c <= 2 * w)
        return true;
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    rep(testId,t){
        printf("Case #%d: ", testId+1);
        int r,c,w;
        scanf("%d%d%d",&r,&c,&w);
        printf("%d\n", r * (c/w) + w - ((c % w) == 0));
    }
}
