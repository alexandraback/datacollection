#include <iostream>
using namespace std;
int pow10 [19];
int mi = 1e9;
string string1 = "1000", string2 = "1000";
int conv (string t){
    int ans = 0;
    for (int g=0; g<t.length(); g++){
        ans+=pow10[t.length() - 1 - g] * (t[g] - '0');
    }
    return ans;
}
void solve (string x, string y, int nu = 0){
    if (nu == x.length()){
        int f = conv(x), s = conv(y);
        if (abs(f - s) < mi){
            mi = abs(f - s);
            string1 = x, string2 = y;
        }
        else if (abs(f - s) == mi){
            if (f < conv(string1)){
                string1 = x, string2 = y;
            }
            else if (f == conv(string1)){
                if (s < conv(string2)){
                    string1 = x, string2 = y;
                }
            }
        }
        return;
    }
    for (int g=0; g<10; g++){
        for (int ye=0; ye<10; ye++){
            string xx = x, yy = y;
            if (x[nu] == '?') xx[nu] = char('0' + g);
            if (y[nu] == '?') yy[nu] = char('0' + ye);
            solve (xx, yy, nu + 1);
        }
    }
}
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    pow10[0] = 1;
    for (int g=1; g<=6; g++) pow10[g] = pow10[g-1] * 10;
    int t; cin >> t;
    for (int g=0; g<t; g++){
        string1 = "1000";
        mi = 1e9; string2="1000";
        string x, y; cin >> x >> y;
        solve (x, y);
        cout << "Case #" << g + 1 << ": ";
        cout << string1 << ' ' << string2 << endl;
    }
    return 0;
}