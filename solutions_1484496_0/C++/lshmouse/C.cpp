
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;


int n, A[1024];

void print(int x) {
    for (int i = 0; i < n; i++){
        if ((x & (1 << i)) > 0) {
            printf("%d ", A[i]);
        }
    }
    printf("\n");
}

void solve() {
    vector<pair<int, int> > states;
    for(int i = 1; i < (1<<20); i++){
       int sum = 0;
       for(int j = 0; j < n; j++){
            if ((i & (1 <<j)) > 0) {
                sum += A[j];
            }
       }
       states.push_back(make_pair(sum, i));
    }

    sort(states.begin(), states.end());

    for(int i = 0; i < states.size(); i++) {
        for(int j = i + 1 ; j< states.size(); j++) {
            if(states[i].first != states[j].first) break;
            if ((states[i].second & states[j].second)== 0) {
                print(states[i].second);
                print(states[j].second);
                return;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int cases = 1; cases <= T; cases++) {
        scanf("%d",&n);
        for(int i = 0;i < n; i++){
            scanf("%d", &A[i]);
        }
        printf("Case #%d:\n", cases);
        solve();
    }
    return 0;
}
