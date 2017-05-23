#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const unsigned long long int min(unsigned long long int a, unsigned long long int b) {
    if (a > b)
        return b;
    else
        return a;
}

const unsigned long long int get_max(unsigned long long int a, unsigned long long int b) {
    if (a < b)
        return b;
    else
        return a;
}

int n, m;
unsigned long long int num_a[120], list_a[120];
unsigned long long int num_b[120], list_b[120];
    unsigned long long int map[120][120];
    unsigned long long int rest[120][120];
 

const unsigned long long int get_value(int a, int b)
{
    if (a < 0) 
        return 0;
    if (b < 0)
        return 0;
    return map[a][b];
}

unsigned long long int compute() {
   unsigned long long int max = 0;

    int i, j, k;

    memset(rest, 0, sizeof(rest));
    memset(map, 0, sizeof(map));

    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) {
            map[i][j] = 0;
            rest[i][j] = 0;
            unsigned long long int the_max = 0;
            for (k = 0; k <= i; ++k) {
                unsigned long long int value = 0;
                unsigned long long int used = 0;
                unsigned long long int tmp_rest = 0;
                unsigned long long int available = 0;

                if (list_b[j] == list_a[i])
                    available = num_a[i];

                if (k != i && list_b[j] == list_a[k])
                    available += rest[k][j];
                used = min(available, num_b[j]);
                if (get_value(k, j) + used > get_value(k, j - 1)) {
                    value = get_value(k, j) + used;
                    tmp_rest = available - used;
                }
                else {
                    value = get_value(k, j - 1);
                    tmp_rest = available;
                }

//                cout << i << " " << j << " " << k << " " << available << " " <<  value << " " << num_a[i] << " " << num_b[j] << num_a[k] << endl;
                if (value > the_max) {
                    the_max = value;
                    rest[i][j] = tmp_rest;
                }
                if (value > max)
                    max = value;
            }
            map[i][j] = the_max;
        }
    /*
  for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << map[i][j] << "(" << rest[i][j] << ") ";
        cout << endl;
    }
    */
    return max;
}

int main() {
    int num_cases;
    int turn;
    unsigned long long int ans;
    cin >> num_cases;

    for (turn = 1; turn <= num_cases; ++turn) {
        cin >> n;
        cin >> m;

        for (int i = 0; i < n; ++i) {
           cin >> num_a[i];
           cin >> list_a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> num_b[i];
            cin >> list_b[i];
        }
        ans = compute();
        cout << "Case #" << turn << ": " << ans << endl;
    }
    return 0;
}
