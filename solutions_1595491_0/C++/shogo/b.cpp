#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int no = 1; no<=T; ++no) {
        int N, S, p;
        int ans = 0;
        int A = 0, B = 0;
        cin >> N >> S >> p;
        for(int i=0;i<N;++i) {
            int point;
            cin >> point;
            bool canS = (2<=point && point<=28);
            bool canSge = canS && ((point-p)/2 >= p-2);
            bool canNSge = (point>=p) && ((point-p)/2 >= p-1);

            if(canSge && !canNSge) ++A;
            if(canNSge) ++B;
        }
        ans = min(S, A) + B;
        cout << "Case #" << no << ": " << ans << endl;
    }
    return 0;
}
