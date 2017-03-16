#include <iostream>
using namespace std;

// こんなのでいいのかな
bool isUse[10];
bool isAllUse() {
    for (int i = 0; i < 10; ++i)
        if (!isUse[i]) return false;
    return true;
}
    
void proc()
{
	int N;
	cin >> N;
    if (N == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }

    int ans = N;
    for (int i = 0; i < 10; ++i) isUse[i] = false;
    while(true) {
        string str = to_string(ans);
        for (int i = 0; i < str.length(); ++i)
            isUse[int(str[i] - '0')] = true;
        if (isAllUse()) break;
        ans += N;
    }
	cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
    for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		proc();
	}
}
