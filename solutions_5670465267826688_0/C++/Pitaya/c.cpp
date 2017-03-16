#include <iostream>
#include <algorithm>

using namespace std;

int table[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2, -1, 4, -3},
    {0, 3, -4, -1, 2},
    {0, 4, 3, -2, -1}
};

int mul(int a, int b) {
    return table[abs(a)][abs(b)] * (abs(a * b) / a / b);
}

int translate(char ch) {
    return ch - 'i' + 2;
}

int main() 
{
    int T, n, sum, front, rear, single, final;
    long long x;
    string str;

    cin >> T;
    for (int I = 0; I < T; ++I)
    {
        cin >> n >> x >> str;
        front = -1;
        rear = -1;
        single = translate(str[0]);
        for (int i = 1; i < n; ++i) {
            single = mul(single, translate(str[i]));            
        }
        final = 1;
        for (int i = 0; i < x % 4; ++i) {
            final = mul(final, single);
        }
        sum = translate(str[0]);
        for (int i = 1; i < 4 * n; ++i) {
            if (sum == 2) {
                front = i;
                break;
            }
            sum = mul(sum, translate(str[i % n]));
        }
        sum = translate(str[str.length() - 1]);
        for (int i = 1; i < 4 * n; ++i) {
            if (sum == 4) {
                rear = i;
                break;
            }
            sum = mul(translate(str[(4 * n - i - 1) % n]), sum);
        }
        cout << "Case #" << I + 1 << ": ";
        if (front != -1 && rear != -1 && final == -1 && (front + rear) / n < x) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}