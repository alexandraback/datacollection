#include <iostream>
#include <vector>
using namespace std;

struct level { int id,a,b; level(int id,int a,int b):id(id),a(a),b(b){} };

int main() {
    int T; cin >> T;
    for (int t=1; t<=T; ++t) {
        int N; cin >> N;
        vector<level> L;
        for (int n=0; n<N; ++n) { int a,b; cin >> a >> b; L.push_back(level(n,a,b)); }
        vector<int> gained(N,0);

        int stars=0, steps=0;
        while (true) {
            if (stars==2*N) break;
            bool change=false;
            for (int n=0; n<N; ++n) {
                if (gained[n]==2) continue;
                if (L[n].b > stars) continue;
                stars += 2-gained[n];
                steps += 1;
                gained[n] = 2;
                change = true;
            }
            if (change) continue;
            // if we got here, we are forced to play for 1 star
            int best=-1;
            for (int n=0; n<N; ++n) {
                if (gained[n] >= 1) continue;
                if (L[n].a > stars) continue;
                if (best == -1) best = n;
                if (L[n].b > L[best].b) best = n;
            }
            if (best==-1) break; // Too Bad
            stars += 1;
            steps += 1;
            gained[best] = 1;
        }
        if (stars==2*N) {
            cout << "Case #" << t << ": " << steps << endl;
        } else {
            cout << "Case #" << t << ": Too Bad" << endl;
        }
    }
}
