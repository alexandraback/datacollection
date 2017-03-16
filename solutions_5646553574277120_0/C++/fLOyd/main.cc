#include <iostream>

using namespace std;

int caseCount;

int c, d, v;
int dd[10];
int values[1000];

void mark(int deep, int total) {
    if (deep == d) { values[total] = 1; } else {
    mark(deep + 1, total);
    mark(deep + 1, total + dd[deep]);
    }
}


void printv() {
    for (int i = 0; i <= v; ++i) {
        cout << i << ": " << values[i] << "+";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    cin >> caseCount;
    for (int caseNum = 1; caseNum <= caseCount; ++caseNum) {
        cin >> c >> d >> v;
        for (int i = 0; i < d; ++i) {
            cin >> dd[i];
        }
        memset(values, 0, sizeof(values));
        mark(0, 0);

        int res = 0;
        for (int i = 0; i <= v; ++i) {
            if (values[i] == 0) {
                res++;
                values[i] = res + 1;
                for (int j = 0; j <= v; ++j) {
                    if (values[j] == res) {
                        if (values[j + i] == 0) {
                            values[j + i] = res + 1;
                        }
                        values[j] = res + 1;
                    }
                }
            }
        }

        cout << "Case #" << caseNum << ": " << res << endl;
    }
    return 0;
}
