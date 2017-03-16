#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
 
int A, B, T, N;
int teste = 0;

double prob[100000];

struct level {
    int a, b;
    bool played;
    bool operator< (level ot) const {
        return b<ot.b || (b==ot.b && a<ot.a);
    }
};

level l[1000];

int main() {
    for (scanf("%d", &T); T; --T) {
        memset(l,0,sizeof(l));
        printf("Case #%d: ", ++teste);
        
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &l[i].a, &l[i].b);
        }
        
        sort(l,l+N);
        
        int tally = 0;
        int first_two = 0;
        
        bool poss = true;
        int cnt = 0;
        
        while (first_two < N) {
            while (l[first_two].b <= tally && first_two < N) {
                if (l[first_two].played) tally++;
                else tally += 2;
                cnt++;
                //printf("T Played on %d\n",first_two);
                l[first_two].played=true;
                
                first_two++;
            }
            
            if (first_two == N) break;
            
            int chosen = -1;
            for (int i = N-1; i >= 0; i--) {
                if (l[i].a <= tally && !l[i].played) {
                    chosen = i;
                    break;
                }
            }
            
            if (chosen == -1) {
                poss = false;
                break;
            }
            
            cnt++;
            //printf("Played on %d\n",chosen);
            l[chosen].played=true;
            tally++;
        }
        
        if (!poss) printf("Too Bad\n");
        else printf("%d\n", cnt);
    }
}
