/**
 * @author: Ruben S. Andrist
 * @version: 0.1
 * @date: 2014-04-11
 * Contact: lasrach[at]gmail.com
 */

#include <deque>
#include <cstdio>
#include <algorithm>
using namespace std;

#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()

deque<double> get_blocks(int N) {
    deque<double> blocks;
    for (int i=0; i<N; i++) {
        double x;
        scanf(" %lf", &x);
        blocks.push_back(x);
    }
    sort(all(blocks));
    return blocks;
}

int main() {
    int cases = 0;
    scanf(" %d", &cases);
    for (int caseno = 1; caseno <= cases; caseno++) {
        printf("Case #%d: ", caseno);

        int N = 0;
        scanf(" %d", &N);
        deque<double> naomi = get_blocks(N);
        deque<double> ken = get_blocks(N);

        // note: ken's strategy is to play x+eps
        // to score when he can, otherwise his
        // smallest block

        // for dwar, just abuse the second part
        // (the smallest block fallback) by announcing
        // 1-eps for every block that can beat something
        int dwar = 0;
        for (int j=0, k=0; j<N; j++) {
            if (naomi[j] > ken[k]) {
                dwar++; k++;
            }
        }
        printf("%d ", dwar);

        // for war we can only win when we hold
        // the current champion block
        int war = 0;
        for (int j=N-1, k=N-1; j>=0; j--) {
            if (naomi[j] > ken[k]) {
                war++;
            }else{
                k--;
            }
        }
        printf("%d\n", war);
    }
    return 0;
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
