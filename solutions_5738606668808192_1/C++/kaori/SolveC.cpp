#include <iostream>
using namespace std;

// 高校数学あやうし
void proc()
{
    int N, J;
    cin >> N >> J;
    char ans[N+1];
    memset(ans, 0, sizeof(ans));
    ans[0] = ans[N-1] = '1';
    
    for (int num = 0; num < J; ++num) {
        for (int idx = 0; idx < N/2 - 1; ++idx)
            ans[idx+1] = ans[N-2-idx] = (num >> idx & 1) ? '1' : '0';
        cout << ans << " 3 4 5 6 7 8 9 10 11" << endl;
    }
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":" << endl;
		proc();
	}
}
