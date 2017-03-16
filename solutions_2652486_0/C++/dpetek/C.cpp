#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

//int K = 4, M = 5, R = 3, N = 3;

int R = 100,
N = 3,
M = 5,
K = 7;


int solveSmall(vector<int> v)
{
    vector<vector<int> > candidates;
    map<int, bool> map;
    int maxy = 0;
    for (int i=0;i<v.size();++i) {map[v[i]] = true;maxy = max(maxy, v[i]); }
    for (int i=2;i<=M;++i){
        for (int j=2;j<=M;++j){
            for (int k=2;k<=M;++k) {

                bool ok = true;
                for (int t=0;t<v.size();++t) {
                    if ( v[t] == 1 ) continue;
                    if ( v[t] % i != 0 && v[t] % j != 0 && v[t] % k != 0 ) ok = false;
                }

                if (ok ) {

                    if ( i * j * k == maxy ) {
                        return 100 * i + 10 * j + k;
                    }

                    vector<int> vv;
                    vv.push_back(i);
                    vv.push_back(j);
                    vv.push_back(k);
                    candidates.push_back(vv);
                }
            }
        }
    }

    if (!candidates.size()) return 333;


    for (int i=0;i<candidates.size();++i) {

        int m[1000];
        for (int j=0;j<(1<<N);++j)
        {
            int tmp = 1;
            for (int k=0;k<N;++k) {
                if ( j & (1<<k)) {
                    tmp *= candidates[i][k];
                }
            }
            m[tmp] = true;
        }

        bool ok = true;
        for (int j=0;j<v.size();++j) {
            if (!m[v[j]] ) ok = false;
        }
        if (ok ) return 100 * candidates[i][0] + 10 * candidates[i][1] + candidates[i][2];
    }

    return 333;
}


int main(void)
{
    freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    int t;
    scanf ("%d", &t);
    vector<int> results;
     for (int _test=1;_test<=t;++_test) {
        for (int i = 0;i<R;++i) {
            vector<int> v;
            int a;
            for (int j=0;j<K;++j) {
                scanf ("%d" , &a);
                v.push_back(a);
            }
            int res = solveSmall(v);
            results.push_back(res);
        }
     }

     printf ("Case #%d:\n", 1);
     for (int i=0;i<results.size();++i) printf ("%d\n", results[i]);

    return 0;
}
