#include <set>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

#define MAXN 1005
#define MAXD 30
#define MOD 1000000007

typedef long long ll;
ll T, n;

string s;

void flip(int x){
    for (int i = 0; i < x; i++){
        if (s[i] == '+')
            s[i] = '-';
        else
            s[i] = '+';
    }
}

int main(){
    cin >> T;
    for (int cse = 1; cse <= T; cse++){
        cout << "Case #" << cse << ": ";
        cin >> s;
        ll res = 0;
        for (int r = s.size()-1; r >= 0; r--){
            while (r >= 0 && s[r] == '+')
                r--;
            if (r < 0)
                break;
            if (s[0] == '+'){
                res++;
                int i;
                for (i = 0; i <= r; i++){
                    if (s[i] == '+'){
                        s[i] = '-';
                    }
                    else
                        break;
                }
                while (s[i] == '-' && i <= r){
                    i++;
                }
            }
            res++;
            flip(r);
        }
        cout << res << endl;

    }


    return 0;
}


