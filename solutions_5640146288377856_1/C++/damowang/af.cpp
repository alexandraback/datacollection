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
            cout << r * c << endl;
        }
        else if (c == w) {
            cout << r - 1 + c << endl;
        }
        else {
            int remain = c % w;
            int left = c / w;
            if(c % w != 0) left ++;
            left *= (r - 1);
            if (remain == 1) {
                cout << w + c / w + left<<endl;
            } else if (remain == 0) {
                cout << c / w + w - 1 + left<<endl;
            } else
                cout << c / w + w + left<<endl;
        }
    }
    return 0;
}