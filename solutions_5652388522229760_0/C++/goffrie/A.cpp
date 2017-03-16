#include <iostream>
#include <sstream>


using namespace std;

typedef long long l;
typedef int z;
#define int l

void tc() {
    int N;
    cin >> N;
    bool seen[10] = {false};
    int n = 0;
    int i;
    for (i = 1; N != 0; ++i) {
        ostringstream s;
        s << (N * i);
        string ss = s.str();
        for (int j = 0; j < ss.size(); ++j) {
            if (!seen[ss[j]-'0']) {
                seen[ss[j]-'0'] = true;
                ++n;
            }
        }
        if (n == 10) break;
    }
    static int cas = 1;
    cout << "Case #" << cas++ << ": ";
    if (n == 10) {
        cout << i*N << endl;
    } else {
        cout << "INSOMNIA" << endl;
    }
}
z main() {
    int T; cin >> T; while (T--) tc();
}
