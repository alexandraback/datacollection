#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

#define REP(n,N) for(int n = 0; n < N; ++n)

using namespace std;

int N;
vector<double> A, B;

int main() {
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> N;
        A = B = vector<double>(N);
        
        REP(n,N) cin >> A[n];
        REP(n,N) cin >> B[n];
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        /* playing fair */
        int pointsFair = 0; {
            set<double> Bob(B.begin(), B.end());
            
            for(double a : A) {
                auto it = Bob.upper_bound(a);
                Bob.erase(it == Bob.end() ? (++pointsFair, Bob.begin()) : it);
            }
        }
        
        int pointsUnfair = 0; {
            deque<double> Bob(B.begin(), B.end());
            
            for(double a : A) {
                if (a > Bob.front()) {
                    pointsUnfair++;
                    Bob.pop_front();
                } else {
                    Bob.pop_back();
                }
            }
        }
        
        cout << "Case #" << t << ": " << pointsUnfair << " " << pointsFair << endl;
    }
}