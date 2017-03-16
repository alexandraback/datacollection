#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <set>

using namespace std;

int TC = 1, T, J, P, S, K;
int a[444];

int main ()
{
    for (cin >> T; TC <= T; TC++) {
        int result = 0;
        vector<vector<int> > re;
        memset(a, 0, sizeof(a));
        cin >> J >> P >> S >> K;
        cout << "Case #" << TC << ": ";
        for (int j = 1; j <= J; j++) {
            for (int p = 1; p <= P; p++) {
                for (int s = 1; s <= S; s++) {
                    int tmp1 = j*100 + p*10;
                    int tmp2 = j*100 + s;
                    int tmp3 = p*10 + s;
                    if (a[tmp1] < K && a[tmp2] < K && a[tmp3] < K) {
                        a[tmp1]++;
                        a[tmp2]++;
                        a[tmp3]++;
                        result++;
                        vector<int> tmp;
                        tmp.push_back(j);
                        tmp.push_back(p);
                        tmp.push_back(s);
                        re.push_back(tmp);
                    }
                }
            }
        }
        cout << result << endl;
        for (int i = 0; i < re.size(); i++) {
            for (int j = 0; j < re[0].size(); j++) {
                cout << re[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}