#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef vector<int> vi;

void disp(const vi& v) {
    For(i, v.size()) {
        if (i > 0) putchar(' ');
        printf("%d", v[i]);
    }
    puts("");
}

int calcWar(const vi& naomi, const vi& ken) {
    const int n = naomi.size();
    vi used(n);
    
    int naomiWin = 0;
    For(i, n) {
        int bestValue = 0;
        int bestIndex = -1;
        bool win = false;
        For(j, n) {
            if (used[j]) continue;

            if (naomi[i] < ken[j]) {
                if (bestIndex == -1 || bestValue > ken[j]) {
                    bestIndex = j;
                    bestValue = ken[j];
                }
            }
        }

        if (bestIndex == -1) {
            // naomi win
            naomiWin++;
            int minIndex = -1;
            int minValue = 0;

            For(j, n) {
                if (used[j]) continue;
                
                if (minIndex == -1 || minValue > ken[j]) {
                    minIndex = j;
                    minValue = ken[j];
                }
            }
            used[minIndex] = true;
        }
        else {
            // ken win
            used[bestIndex] = true;
        }
    }

    return naomiWin;
}

int calcDeceitfulWar(vi naomi, vi ken) {
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());

    int naomiWin = 0;
    while (!naomi.empty()) {
        if (naomi.back() > ken.back()) {
            naomiWin++;
            naomi.pop_back();
            ken.pop_back();
        }
        else {
            naomi.erase(naomi.begin());
            ken.pop_back();
        }
    }
#if 0
    const int n = naomi.size();
    int kenp = 0;
    For(i, n) {
        if (naomi[i] > ken[kenp]) {
            if (
            return n - i;
        }
        else {
            
        }
    }
    return 0;
#endif
    return naomiWin;
}

void calc(const vi& naomi, const vi& ken) {
    assert(naomi.size() == ken.size());

#if 0    
    vi a(naomi); sort(a.begin(), a.end());
    vi b(ken); sort(b.begin(), b.end());
    puts("");
    printf("naomi: "); disp(a);
    printf("  ken: "); disp(b);
#endif
    
    int war = calcWar(naomi, ken);
//    printf("calcWar:%d\n", war);

    int deceitfulWar = calcDeceitfulWar(naomi, ken);

    printf("%d %d\n", deceitfulWar, war);

        
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int n;
        scanf("%d", &n);

        vi naomi, ken;
        char s[100];
        For(i, n) {
            scanf("%s", s);
            assert(s[1] == '.');
            s[1] = '0';
            naomi.push_back(atoi(s));
        }
        For(i, n) {
            scanf("%s", s);
            assert(s[1] == '.');
            s[1] = '0';
            ken.push_back(atoi(s));
        }

        printf("Case #%d: ", cc+1);
        calc(naomi, ken);
    }
}
