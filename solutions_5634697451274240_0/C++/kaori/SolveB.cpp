#include <iostream>
using namespace std;

// わかるけど、わからん
void proc()
{
	string S;
	cin >> S;
	int count = 0;
    bool isPrevFace = true;
    for (int i = S.length()-1; i >= 0; --i) {
        bool isNowFace = (S[i] == '+');
        if (isPrevFace != isNowFace) ++count;
        isPrevFace = isNowFace;
	}
	cout << count << endl;
}


int main() {
	int T;
	cin >> T;
    for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		proc();
	}
}
