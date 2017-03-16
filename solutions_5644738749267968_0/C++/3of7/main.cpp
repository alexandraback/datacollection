#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int doit(list<double>& naomi, list<double>& ken, int D, int N) {
    if(D>0) {
        naomi.pop_front();
        ken.pop_back();
    }
    int ret = N - ken.size();
    list<double>::iterator it1 = naomi.begin();
    list<double>::iterator it2 = ken.begin();
    if(D < 0) {
        while(it1 != naomi.end()) {
            while(it2 != ken.end() && (*it2) < (*it1)) {
                it2++;
            }
            if(it2 != ken.end() && (*it2) > (*it1)) {
                ret++;
                if(it2 != ken.end()) ++it2;
            }
            ++it1;
        }
    } else {
        while(it1 != naomi.end()) {
            if((*it1) < (*it2)) {
                ret++;
            }
            ++it1;
            ++it2;
        }
    }

    return N - ret;
}

int main() {
    freopen("D-small-attempt1.in", "r", stdin);
    freopen("D-small.out", "w", stdout);
    int T, N;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        vector< double > naomi(N);
        vector< double > ken(N);
        for(int n = 0; n < N; n++) {
            cin >> naomi[n];
        }
        for(int n = 0; n < N; n++) {
            cin >> ken[n];
        }
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        /*{
            for(int i = 0; i < N; i++) {
                cout << naomi[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < N; i++) {
                cout << ken[i] << " ";
            }
            cout << endl;
        }*/
        list< double > ls[2];
        for(int n = 0; n < N; n++) {
            ls[0].push_back(naomi[n]);
            ls[1].push_back(ken[n]);
        }
        int ans2 = doit(ls[0], ls[1], -1, N);
        int ans1 = 0;
        for(int n = 0; n <= N; n++) {
            ans1 = max(ans1, doit(ls[0], ls[1], n, N));
        }
//        cout.setf(ios::fixed, ios::floatfield);
//        cout.precision(3);
//        cout << ans1 <<"::"<<ans2<<endl;
        cout << "Case #" << t << ": " << ans1 << " " << ans2 << endl;
    }
}