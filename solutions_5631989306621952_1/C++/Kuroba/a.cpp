#include <bits/stdc++.h>
using namespace std;

int T;

string s;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas<=T; cas++){
        printf("Case #%d: ", cas);

        cin >> s;
        string t = "";
        for(int i = 0; i<s.length(); i++){
            if (i == 0) t += s[i];
            else{
                if (s[i] >= t[0]) t.insert(0, 1, s[i]);
                else t += s[i];
            }
        }
        cout << t << endl;




    }


}
