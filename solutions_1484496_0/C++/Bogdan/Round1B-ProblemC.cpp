#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;

#define SET_SIZE (20)
#define POW_2_SET_SIZE (1024*1024)

void main_1B_C() {
    unsigned int T;
    vector<unsigned int> S;

    S.resize(SET_SIZE);
    cin >> T;
    for (unsigned int i=0;i<T;++i) {
        bool found = false;
        unsigned int aux;

        cin >> aux;
        assert(aux == 20);

        for (unsigned int j=0;j<SET_SIZE;++j) {
            cin >> S[j];
        }
        sort(S.begin(),S.end());

        map<unsigned int,unsigned int> sums;
        vector<unsigned int> v1,v2;
        v1.resize(SET_SIZE);
        v2.resize(SET_SIZE);
        unsigned int v1size, v2size;

        cout << "Case #" << (i+1) << ":" << endl;
        for (unsigned int k=1;k<=POW_2_SET_SIZE;++k) {
            unsigned int sum = 0;
            for (unsigned int j=0;j<SET_SIZE;++j) {
                if ((k >> j) & 1) {
                    sum += S[j];
                }
            }
            if (sums.find(sum) != sums.end()) {
                unsigned int k1 = sums[sum];
                v1size = 0;
                v2size = 0;
                for (unsigned int j=0;j<SET_SIZE;++j) {
                    if ((k1 >> j) & 1) v1[v1size++] =  S[j];
                }
                for (unsigned int j=0;j<SET_SIZE;++j) {
                    if ((k >> j) & 1) v2[v2size++] =  S[j];
                }
                if (v1size == v2size) {
                    for (unsigned int j=0;j<v1size;++j) {
                        if (v1[j] != v2[j]) {
                            found = true;
                            break;
                        }
                    }
                } else found = true;

                if (found) {
                    unsigned int s1=0, s2=0;
                    for (unsigned int j=0;j<v2size;++j) {
                        //s2 += v2[j];
                        cout << v2[j] << " ";
                    }
                    //cout << " ~ " << s2;
                    cout << endl;
                    for (unsigned int j=0;j<v1size;++j) {
                        cout << v1[j] << " ";
                        //s1 += v1[j];
                    }
                    //cout << " ~ " << s1;
                    cout << endl;
                    break;
                } else {
                    sum = 1;
                }
            } else {
                sums[sum] = k;
            }
        }
        if (!found) cout << "Impossible" << endl;
    }
}

