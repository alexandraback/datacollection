//
//  main.cpp
//  Codejam2013_1C
//
//  Created by Petro Boychuk on 5/12/13.
//  Copyright (c) 2013 Petro Boychuk. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Attack {
    int w,e,s,d;
    
    Attack() : w(0), e(0), s(0), d(0){};
    Attack(int w, int e, int s, int d): w(w), e(e), s(s), d(d){};
    Attack(Attack const & a): w(a.w), e(a.e), s(a.s), d(a.d){};
    
};

bool operator <(const Attack& a, const Attack& b) {
    return a.d < b.d;
}

int a[2000000];

bool check(int w, int e, int s) {
    for (int i = w; i < e; i++) {
        if(a[i + 1000000] < s) {
            return true;
        }
    }
    return false;
}

void update(int w, int e, int s) {
    for (int i = w; i < e; i++) {
        a[i + 1000000] = max(s, a[i + 1000000]);
    }
}

void solve() {

    vector<Attack> v;
    
    
    for (int i=0; i<2000000; i++) {
        a[i] = 0;
    }
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int di, ni, wi, ei, si, del_d, del_p, del_s;
        
        cin >> di >> ni >> wi >> ei >> si >> del_d >> del_p >> del_s;
        
        for (int j=0; j<ni;j++) {
            Attack a(wi, ei, si, di);
            v.push_back(a);
            wi += del_p;
            ei += del_p;
            di += del_d;
            si += del_s;
        }
        
    }
    sort(v.begin(), v.end());
    
    int res = 0;
    
    
    int l = v.size();
    
    for (int i=0; i<l; ) {
        
        int d = v[i].d;
        
        vector<Attack> vd;
        while (i < l && v[i].d == d) {
            vd.push_back(v[i]);
            i++;
        }
        
        for (int j=0; j<vd.size(); j++) {
            if(check(vd[j].w, vd[j].e, vd[j].s)) {
                res++;
//                cout << "w: " << vd[j].w << " e: "<< vd[j].e << " s: " << vd[j].s << " d: " << vd[j].d << endl;
            }
        }
        
        for (int j=0; j<vd.size(); j++) {
            update(vd[j].w, vd[j].e, vd[j].s);
        }
        
    }
    
    cout << res << endl;


}

int main(int argc, const char * argv[])
{

    freopen("inputC.txt", "r", stdin);
    freopen("outputC.txt", "w", stdout);

    int tests;
    cin >> tests;

    for (int t =0; t < tests; t++) {
        cout << "Case #" << t+1 << ": ";
        solve();
    }


    return 0;
}

