#include <iostream>
#include <vector>
#include <set>

using namespace std;

int arr[100];
int acnt;

int main() {
    int cases;
    cin >> cases;

    for(int c=0; c<cases; c++) {
        int A, B;
        cin >> A >> B;
        int exp10larger = 1;
        while(exp10larger <= A) exp10larger *= 10;

        int ans = 0;
        //set<int> s;
        for(int i = A; i <= B; i++) {
            acnt = 0;
            //s.clear();
            for(int dLo = 10; dLo < exp10larger; dLo *= 10) {
                int dHi = exp10larger / dLo;
                int o = (i % dLo) * dHi + i / dLo;
                if (o >= i || o < A || o > B) continue;

                //if(s.count(o)) break;
                bool good = true;
                for(int j = 0; j < acnt; j++) {
                    if (arr[j] == o) { good = false; break; }
                }
                if (!good) continue;
                arr[acnt++] = o; //s.insert(o);
                ans++;
            }
        }

        cout << "Case #" <<(c+1) << ": " << ans << endl;
    }
}
