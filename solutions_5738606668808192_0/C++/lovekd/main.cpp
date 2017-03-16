#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

LL fuck[100];
void Init() {
    memset(fuck, 0, sizeof(fuck));
    for(int i = 1;i <= 10;i ++) {
        fuck[i] = 1;
        for(int j = 1;j <= 8;j ++) {
            fuck[i] *= i;
        }
        fuck[i] ++;
    }
}

int temp[100];

void doit(int num) {
    memset(temp, 0, sizeof(temp));
    int len = 0;
    while(num) {
        temp[len] = num % 2;
        num /= 2;
        len ++;
    }
    for(int i = 5;i >= 0;i --) {
        cout << temp[i];
    }
}

int main(void) {
    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    Init();
    int casenum, N, J;
    int iCase = 0;
    cin >> casenum >> N >> J;
    while(casenum --) {
        iCase ++;
        cout << "Case #" << iCase << ":" << endl;
        for(int i = 1;i <= J;i ++) {
            cout << "1";
            doit(i);
            cout << "11";
            doit(i);
            cout << "1";
            for(int i = 2;i <= 10;i ++) {
                cout << " " << fuck[i];
            }
            cout << endl;
        }
    }

    return 0;
}
