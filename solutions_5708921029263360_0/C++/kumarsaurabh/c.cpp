#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;

#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)

char* getCh[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

int JP[2000];
int PS[2000];
int JS[2000];

int main() {
    int T;
    int J, P, S, K;
    cin >> T;
    F1(c, T) {
        vector<string> ans;
        F0(i,2000) {
            JP[i]=0;
            PS[i]=0;
            JS[i]=0;
        }
        cin >> J >> P >> S >> K;
        //cout << J << " " << P << " " << S << " " << K << endl;
        F1(j, J) {
            F1(p, P) {
                F1(s, S) {
                    int jp = j*100+p;
                    int ps = p*100+s;
                    int js = j*100+s;
                    if((JP[jp]<K) && (PS[ps]<K) && (JS[js]<K)) {
                        JP[jp]++;
                        PS[ps]++;
                        JS[js]++;
                        string str("");
                        str = str + getCh[j] + " " + getCh[p] + " " + getCh[s];
                        ans.push_back(str);
                    }
                }
            }

        }
        cout << "Case #" << c << ": " << ans.size() << endl;
        F0(i,ans.size()) {
            cout << ans[i] << endl;
        }
    }


}
