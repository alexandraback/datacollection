#include <iostream>
#include <vector>

using namespace std;
int N;

int par[1005];
// Longest chain to a 2-cycle?
bool two[1005];
int twolen[1005];
int oth[1005];
bool iso[1005];

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        for(int i = 1; i <= N; i++) {
            iso[i] = true;
            two[i] = false;
            twolen[i] = 0;
        }
        for(int i = 1; i <= N; i++) {
            cin >> par[i];
            iso[par[i]] = false;
        }
        int longchain = 0;
        for(int i = 1; i <= N; i++) {
            int at = i;
            int s = 0;
            do {
                at = par[at];
                s++;
            } while (at != i && s <= 2*N);
            if(s <= N) {
                longchain = max(longchain, s);
            }
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(par[i] == j && par[j] == i) {
                    two[j] = true;
                    two[i] = true;
                    oth[i] = j;
                    oth[j] = i;
                }
            }
        }
        for(int i = 1; i <= N; i++) {
            if(iso[i] && !two[i]) {
                // Check chain
                int at = i;
                int s = 0;
                int check;
                do {
                    check = at;
                    at = par[at];
                    s++;
                } while (!two[at] && s <= 2*N);
                if(s > N) {
                    continue;
                }
                // At is a two-cycle
                twolen[check] = max(twolen[check], s);
                //cerr << "Check cycle " << check << " " << s << "\n";

            }
        }

    /*    for(int i = 1; i <= N; i++) {
            //cerr << twolen[i] << " ";
        }
        //cerr << "\n";*/

        int twoans = 0;
        int groups = 0;
        for(int i = 1; i <= N; i++) {
            if(two[i]) {
                    //cerr << i << " is a two group\n";
                    groups++;
                    vector<int> cands;
                    for(int j = 1; j <= N; j++) {
                        if(par[j] == i) {
                            //cerr << "Hanging could be  " << j << "\n";
                            cands.push_back(twolen[j]);
                        }
                    }
                    sort(cands.begin(), cands.end());
                    reverse(cands.begin(), cands.end());
                    twoans += cands[0];
            }
        }
        twoans += groups;
        int ans = max(twoans, longchain);
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
