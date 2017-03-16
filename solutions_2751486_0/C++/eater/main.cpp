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

using namespace std;

int a[1000010];

void solve() {
    string s;
    int n;
    
    cin >> s >> n;
    int l = s.length();
    for (int i=0; i<l; i++) {
        a[i] = 0;
    }
    for (int i=0; i<l; i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u') {
            a[i+1] = a[i];
        } else {
            a[i+1] = a[i] +1;
        }
    }
//    cout << s << endl;
//    for (int i=0; i<=l; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
    
    long long res = 0;
    
    int last = -1;
    
    for (int i=0; i <= l-n; i++) {
        if(a[i+n] - a[i] == n) {
            
//            for (int j=0; j<n; j++) {
//                cout << s[i+j];
//            }
//            cout << endl;
            
            if(l > 0){
            
                res += (i - last) * (l- n - i + 1);
            } else {
                res += (i) * (l- n - i + 1);
            }
            
            last = i;
        }
    }
    
    cout << res << endl;
    
}

int main(int argc, const char * argv[])
{

    freopen("inputA.txt", "r", stdin);
    freopen("outputA.txt", "w", stdout);
    
    int tests;
    cin >> tests;
    
    for (int t =0; t < tests; t++) {
        cout << "Case #" << t+1 << ": ";
        solve();
    }
    
    
    return 0;
}

