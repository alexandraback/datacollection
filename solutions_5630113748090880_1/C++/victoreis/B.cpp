#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int n; cin >> n;
        int x = n * (2 * n - 1);
        vector<int> occ(2600);
        for(int i = 0; i < x; i++){
            int a; cin >> a;
            occ[a]++;
        }
        printf("Case #%d: ", t);
        for(int i = 1; i < 2600; i++) if(occ[i] % 2 == 1) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
