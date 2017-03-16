#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

LL exc(LL a) {
    LL ans = 1;
    if(a == 0) return 10;
    while(a > 0) {
        a /= 10;
        ans *= 10;
    }
    return ans;
}

int visit[10];
int rem;

void doit(LL a) {
    if(a == 0) {
        if(visit[a] == 0) {
            rem --;
            visit[a] = 1;
        }
        return;
    }
    LL fuck = 10;
    while(a) {
        LL num = a % fuck;
        if(visit[num] == 0) {
            rem --;
            visit[num] = 1;
        }
        a /= fuck;
    }
}

int main() {
    //freopen("A-large.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int casenum;
    int iCase = 0;
    cin >> casenum;
    while(casenum --) {
        iCase ++;
        LL num;
        cin >> num;
        if(num == 0) {
            cout << "Case #" << iCase << ": INSOMNIA" << endl;
            continue;
        }
        memset(visit, 0, sizeof(visit));
        rem = 10;
        LL i = 1;
        while(true) {
            doit(num * i);
            if(rem == 0) {
                cout << "Case #" << iCase << ": " << num * i << endl;
                break;
            }
            i ++;
        }

    }
    return 0;
}
