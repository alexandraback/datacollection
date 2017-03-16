#define _USE_MATH_DEFINES

#include <vector>
#include <iostream>
#include <functional>
#include <sstream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;
    string tmp;
    cin >> tc;
    getline(cin, tmp);
    set<char> v;
    v.insert('a');
    v.insert('e');
    v.insert('o');
    v.insert('i');
    v.insert('u');

    for(int t_ = 1; t_ <= tc; t_++) {
        string s;
        int n;
        getline(cin, s, ' ');
        scanf("%d\n", &n);
        
        int k = 0; 

        for(int i = 0; i < s.size(); i++)
            for(int j = i; j < s.size(); j++) {
                int p = i;
                while(p <= j) {
                    int c = 0;
                    while(p <= j && v.find(s[p]) == v.end()) {
                        p++;
                        c++;
                    }
                    if (c >= n) {
                        k++;
                        break;
                    }
                    p++;
                }


            }

                


        cout << "Case #" << t_ << ": " << k 
            << endl;
    }

}
