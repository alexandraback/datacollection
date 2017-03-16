#include <iostream>
#include <map>

using namespace std;

int DA[1001][1001];
int DB[1001][1001];
int cntDA[1001];
int cntDB[1001];
int cntA, cntB;
int n;
int mA[1001];
int mB[1001]; 
map<string, int> A;
map<string, int> B;

int main() {
    int T, tc;
    string aa, bb;

    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": ";

        cin >> n;
        cntA = cntB = 0;
        A.clear();
        B.clear();
        memset(DA, 0, sizeof(DA));
        memset(DB, 0, sizeof(DB));
        memset(cntDA, 0, sizeof(cntDA));
        memset(cntDB, 0, sizeof(cntDB));
        memset(mA, 0, sizeof(mA));
        memset(mB, 0, sizeof(mB));
        for (int i = 0; i < n; i++) {
            cin >> aa >> bb;
            if (A.find(aa) == A.end()) {
                cntA++;
                A[aa] = cntA;
            }
            if (B.find(bb) == B.end()) {
                cntB++;
                B[bb] = cntB;
            }
            DA[A[aa]][cntDA[A[aa]]++] = B[bb];
            DB[B[bb]][cntDB[B[bb]]++] = A[aa];
        }

        // initialize mapping
        for (int i = 1; i <= cntA; i++) {
            for (int j = 0; j < cntDA[i]; j++) {
                if (mB[DA[i][j]] == 0) {
                    mB[DA[i][j]] = i;
                    mA[i] = DA[i][j];
                    break;
                }
            }
        }
        int queue[2001];
        int head, tail;

        while (1) {
            head = tail = 0;
            for (int i = 1; i <= cntB; i++) {
                if (mB[i] == 0) {
                    queue[++tail] = i;
                }
            }
            int ind[2001];
            memset(ind, 0, sizeof(ind));
            int found = 0;
            while (head != tail && found == 0) {
                int mm = queue[++head];
                for (int i = 0; i < cntDB[mm]; i++) {
                    if (ind[DB[mm][i]] == 0) {
                        ind[DB[mm][i]] = mm;
                        if (mA[DB[mm][i]] == 0) {
                            found = DB[mm][i];
                            break;
                        } else {
                            queue[++tail] = mA[DB[mm][i]];
                        }
                    }
                }
            }
            if (found == 0) break;
            // augment
            for (int j = found; j != 0; ) {
                int next = mB[ind[j]];
                mA[j] = ind[j];
                mB[ind[j]] = j;
                j = next;
            }
        }
        int cc = 0;
        for (int i = 1; i <= cntA; i++) {
            if (mA[i] != 0) {
                cc++;
            }
        }
        cout << n - (cntA + cntB - cc) << endl;

    }
    return 0;
}
