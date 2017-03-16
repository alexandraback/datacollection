#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cout << "Case #" << c << ": ";
        
        int n, cnt, nb, nf, kb, kf;
        cin >> n;
        double tmp;
        vector<double> naomi(n), ken(n);
        for (int i = 0; i < n; i++)
            cin >> naomi[i];
        for (int i = 0; i < n; i++)
            cin >> ken[i];

        sort(naomi.begin(), naomi.end(), greater<double>());
        sort(ken.begin(), ken.end());

        cnt = 0;
        nf = kf = 0;
        nb = kb = n-1;
        for (int i = 0; i < n; i++) {
            if (naomi[nb] < ken[kf]) {
                nb--;
                kb--;
            }
            else {
                nb--;
                kf++;
                cnt++;
            }
        }
        cout << cnt << " ";

        cnt = 0;
        nf = kf = 0;
        nb = kb = n-1;
        for (int i = 0; i < n; i++) {
            if (naomi[nf] > ken[kb]) {
                nf++;
                cnt++;
            }
            else {
                nf++;
                kb--;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
