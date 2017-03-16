#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int testcase = 0; testcase < T; testcase++) {
                string C, J;
                cin >> C >> J;
                int N = C.size();
                int IN = 1;
                for (int i = 0; i < 2*N; i++)
                        IN *= 10;
                string sc = C, sj = J, mc, mj;
                int minabs = INT_MAX, minc = INT_MAX, minj = INT_MAX;
                for (int i = 0; i < IN; i++) {
                        int d, e = i;
                        for (int j = 0; j < N; j++) {
                                d = e % 10; e /= 10;
                                sc[j] = C[j] == '?' ? d + '0' : C[j];
                                d = e % 10; e /= 10;
                                sj[j] = J[j] == '?' ? d + '0' : J[j];
                        }
                        int nc = stoi(sc, 0, 10), nj = stoi(sj, 0, 10);
                        int a = nc > nj ? nc - nj : nj - nc;
                        if (a < minabs) {
                                minabs = a;
                                minc = nc;
                                minj = nj;
                                mc = sc;
                                mj = sj;
                        }
                        else if (a == minabs && nc < minc) {
                                minabs = a;
                                minc = nc;
                                minj = nj;
                                mc = sc;
                                mj = sj;
                        }
                        else if (a == minabs && nc == minc && nj < minj) {
                                minabs = a;
                                minc = nc;
                                minj = nj;
                                mc = sc;
                                mj = sj;
                        }
                }
                cout << "Case #" << testcase+1 << ": ";
                cout << mc << " " << mj << endl;
        }
        return 0;
}
