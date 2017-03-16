#include <iostream>
using namespace std;
int main()
{
    int T, _t;
    bool f = 0;
    cin >> T;
    int r, c, w;
    for (_t = 1; _t <= T; _t ++)
    {
        cin >> r >> c >> w;
        printf("Case #%d: ", _t);
        if (w == 1) {
            cout << c << endl;
        }
        else if (c == w) {
            cout << c << endl;
        }
        else {
            int remain = c % w;
            if (remain == 1) {
                cout << w + c / w <<endl;
            } else if (remain == 0) {
                cout << c / w + w - 1<<endl;
            } else
                cout << c / w + w<<endl;
        }
    }
    return 0;
}