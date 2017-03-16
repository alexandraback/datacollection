#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#define pb push_back
#define sz(v) (int(v.size()))
#define mp make_pair

vector <vector <int> > masks;
vector <int> name;
vector <vector <int> > prods;
int total;

void gen_masks() {
    int maxM = 64;//4**3
    vector <int> cur(3);
    vector <int> curp;
    for (int m0 = 0; m0 < maxM; ++m0) {
        int m = m0;
        cur[0] = m % 4 + 2; m/= 4;
        cur[1] = m % 4 + 2; m/= 4;
        cur[2] = m % 4 + 2; m/= 4;
        masks.push_back(cur);
        name.push_back(100 * cur[0] + 10 * cur[1] + cur[2]);

        curp.clear();
        curp.push_back(1);
        curp.push_back(cur[0]);
        curp.push_back(cur[1]);
        curp.push_back(cur[2]);
        curp.push_back(cur[0] * cur[1]);
        curp.push_back(cur[0] * cur[2]);
        curp.push_back(cur[1] * cur[2]);
        curp.push_back(cur[0] * cur[1] * cur[2]);
        sort(curp.begin(), curp.end());
        prods.push_back(curp);
    }
    total = name.size();
    /*
    for (int i = 0; i < name.size(); ++i) {
        cout << name[i] << ": ";
        for (int j = 0; j < 8; ++j) {
            cout << prods[i][j] << " ";
        }
        cout << endl;
    }
    */
    
}

int main()
{
    srand(239);
    int TEST = 0;
    cin >> TEST;
    gen_masks();
    int R, N, M, K;
    cin >> R >> N >> M >> K;
    for (int test = 1; test <= TEST; ++test) {
        //---code here---
        cout << "Case #" << test <<":\n";
        for (int r = 0; r < R; ++r) {
            //cout << "-------------------------------\n";
            vector <int> good;
            vector <int> curp(K);
            for (int i = 0; i < K; ++i) {
                cin >> curp[i];
            }
            for (int n = 0; n < total; ++n) {
                bool is_good = true;
                for (int i = 0; i < K; ++i) {
                    if (find(prods[n].begin(), prods[n].end(), curp[i]) == prods[n].end()) {
                        is_good = false;
                        //cout << curp[i] << ":(\n";
                        break;
                    }
                }
                if (is_good) {
                    //cout << name[n] << " :)\n";
                    good.push_back(name[n]);
                }
                //cout << is_good << endl;
            }
            cout << good[rand() % good.size()] << endl;
        }

    }
    return 0;
}