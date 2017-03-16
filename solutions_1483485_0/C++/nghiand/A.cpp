#include <iostream>
#include <cstdio>

using namespace std;

const char c[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 
                    'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

string s;
int t;

int main(){
    //freopen("A-small-attempt0.in", "rt", stdin);
//    freopen("A-small-attempt0.out", "wt", stdout);
    cin >> t;
    getline(cin, s);
    for (int i = 1; i <= t; i++){
        getline(cin, s);
        cout << "Case #" << i << ": ";
        for (int j = 0; j < s.length(); j++)
            if (s[j] == ' ') cout << ' ';
            else cout << c[s[j] - 97];
        cout << endl;
    }
    
    return 0;
}
