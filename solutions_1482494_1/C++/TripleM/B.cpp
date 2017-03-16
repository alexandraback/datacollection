#include <iostream>
using namespace std;
typedef struct Level {
    int a,b;
    bool done;
    bool operator<(const Level& level) const {
        if (b!=level.b) return b<level.b;
        return a<level.a;
    }
};
Level levels[1000];
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        int N; scanf("%d",&N);
        for (int i=0; i<N; i++) {
            scanf("%d %d",&levels[i].a,&levels[i].b);
            levels[i].done = false;
        }
        sort(levels,levels+N);
        
        int stars = 0;
        int ones = 0;
        bool solved = true;
        for (int i=0; i<N; i++) {
            if (stars>=levels[i].b) {
                if (levels[i].done) stars++;
                else stars += 2;
            } else {
                bool found = false;
                for (int j=N-1; j>=i; j--) {
                    if (!levels[j].done && stars>=levels[j].a) {
                        stars++;
                        levels[j].done = true;
                        found = true;
                        ones++;
                        break;
                    }
                }
                if (!found) {
                    solved = false;
                    break;
                }
                i--;
            }
        }
        printf("Case #%d: ",t);
        if (!solved) printf("Too Bad\n");
        else printf("%d\n",ones+N);
    } 
}
