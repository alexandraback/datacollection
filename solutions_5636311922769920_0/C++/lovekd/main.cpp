#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;



int main(void) {
    //freopen("D-small-attempt0.in", "r", stdin);
    //freopen("out.out", "w", stdout);

    int casenum;
    int iCase = 0;
    cin >> casenum;
    while(casenum --) {
        int K, C, S;
        iCase ++;
        cin >> K >> C >> S;
        cout << "Case #" << iCase << ":";
        if(K == S) {
            for(int i = 1;i <= K;i ++) {
                cout << " " << i ;
            }
            cout << endl;
        }
    }

    return 0;
}
