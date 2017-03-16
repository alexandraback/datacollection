#include <iostream>
#include <vector>

using namespace std;



int main() {
    int cases;
    cin >> cases;

    for(int c=0; c<cases; c++) {
        int n, surprising, p;

        cin >> n >> surprising >> p;

        vector<int> scores(n);
        for(int i=0; i<n; i++) cin >> scores[i];

        int ans = 0;
        for(int i=0; i<scores.size(); i++) {
            int mx = (scores[i] + 2) / 3;
            if (mx >= p) ans++;
            else if (surprising > 0) {
                int s = scores[i];

                if (s/3 + 1 >= p && s % 3 == 0 && s >= 2 && s <= 28) {
                    ans++; surprising--;
                }
                else if (s/3 + 2 >= p && s % 3 == 2 && s >= 2 && s <= 28) {
                    ans++; surprising--;
                }
            }
        }

        
        cout << "Case #" <<(c+1) << ": " << ans << endl;
    }
}
