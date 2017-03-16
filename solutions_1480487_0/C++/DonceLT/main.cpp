#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

using namespace std;


int n;
int s[200];

int now[200];
int toAdd[200];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            now[i] = s[i];
            sum += s[i];
        }
        sort(now, now+n);
        int left = sum;
        for (int i = 0; i < n; i++)
            toAdd[i] = 0;
        for (int i = 0; i < n && left > 0; i++) {
            int next;
            if (i == n-1)
                next = 10000000;
            else
                next = now[i+1];
            int add = min((i+1)*(next - now[i]), left);
            int each = add / (i+1);
            for (int j = 0; j <= i; j++)
                toAdd[j] += each;
            left -= add;
        }

        int toAddValue[101];
        for (int i = 0; i < n; i++)
            toAddValue[now[i]] = toAdd[i];


        //double limit = double(2*sum) / n;
        cout << "Case #" << t << ": ";
        for (int i = 0; i < n; i++) {
            //cout << setprecision(10) << toAddValue[s[i]] << ' ';
            if (i)
                cout << ' ';
            cout << setprecision(10) << double(100 * toAddValue[s[i]]) / sum;
        }
        cout << endl;
    }

    return 0;
}
