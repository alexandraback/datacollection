#include <bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000
using namespace std;
typedef long long ll;
typedef int char_32;
#define INF16 1000000


int b;
pair <int, int> p[50];

int ms[55][55];


void func(int n) {
    ms[1][n] = 1;
    for(int i = n; i <= b; ++i) {

        for(int j = i + 1; j <= b; ++j) {

            ms[i][j] = 1;

        }

    }

}

map <pair<int,int>,int> M1, M2, M3;

int main() {
    freopen("C-small-attempt3.in", "r", stdin);
    freopen("ancestor.out", "w", stdout);
    int t; cin >> t;


    for(int z = 0; z < t; ++ z) {
        int j, p, s, kz;
        M1.clear(), M2.clear(), M3.clear();
        cin >> j >> p >> s >> kz;
        vector <int> ansj, ansp, anss;
        for(int i = 1; i <= j; ++i) {

            for(int k = 1; k <= s; ++k) {

                for(int t = 1; t <= p; ++t) {
                    //cout << i << " " << t << " " << k << endl;
                    //cout << M1[{i, t}] << " " << M2[{i, k}]  << " " << M3[{t, k}] << endl;

                    if(M1[{i,t}] == kz - 1) {

                        if(k != s) {

                            int minn = 0, index;

                            for(int d = k; d <= s; ++d) {

                               if(M3[{t,d}] >= minn) {
                                    minn = M3[{t,d}];
                                    index = d;
                               }

                            }
                            M3[{t,index}] += 1;
                            ansj.push_back(i);
                            ansp.push_back(t);
                            anss.push_back(index);


                            k = s;
                            continue;


                        }

                    }



                    if(M1[{i, t}] < kz && M2[{i, k}] < kz && M3[{t, k}] < kz) {

                        ansj.push_back(i);
                        ansp.push_back(t);
                        anss.push_back(k);
                        M1[{i, t}] += 1;
                        M2[{i, k}] += 1;
                        M3[{t, k}] += 1;

                    }

                }

            }

        }
        cout << "Case #" << z + 1 << ": " << ansj.size() << endl;
        for(int i = 0; i < ansj.size(); ++i) {

            cout << ansj[i] << " " << ansp[i] << " " << anss[i] << endl;

        }

    }


}
