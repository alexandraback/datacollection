#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

typedef long long int int64;

int dw(int a){
    int rt = 1;
    while((rt<<1)<=a) rt<<=1;
    return rt;
}

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int tab[101] = {1};
        int C, D, V;
        scanf("%d %d %d", &C, &D, &V);
        for(int lx = 0;lx < D;lx++){
            int inp; scanf("%d", &inp);
            vector<int> toap;
            for(int lv = 0;lv <= V;lv++)
                if(tab[lv] and lv+inp <= V)
                    toap.push_back(lv+inp);
            for(int ly = 0;ly < toap.size();ly++){
                tab[toap[ly]] = 1;
            }
        }
        int cnt = 0;
        for(int lx = 0;lx <= V;lx++){
            if(tab[lx]) continue;
            int inp = lx;
            cnt++;
            vector<int> toap;
            for(int lv = 0;lv <= V;lv++)
                if(tab[lv] and lv+inp <= V)
                    toap.push_back(lv+inp);
            for(int ly = 0;ly < toap.size();ly++)
                tab[toap[ly]] = 1;
        }
        printf("Case #%d: %d\n", lt, cnt);
    }
    return 0;
}
