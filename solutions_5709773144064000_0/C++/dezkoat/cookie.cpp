#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int TC;
    cin >> TC;

    cout << fixed << setprecision(7);
    for (int i = 1; i <= TC; i++) {
        double C, F, X;
        double rate = 2.0;
        double pt, qt, at, bt;
        cin >> C >> F >> X;
        
        at = 0.0;
        bt = X / rate;
        for (;;) {
            pt = at + C / rate;
            rate += F;

            qt = X / rate;

            if (at + bt < pt + qt)
                break;

            at = pt;
            bt = qt;
        }

        cout << "Case #" << i << ": " << at+bt << endl;
    }

    return 0;
}
