#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    string s;
    cin >> T;
    for(int i=1;i<=T;++i){
        cin >> s;
        int ret = 0;
        s.push_back('+');
        for(int j=0;j<(int)s.size()-1;++j) ret+=(s[j]!=s[j+1]);
        cout << "Case #" << i << ": " << ret << "\n";
    }
    return 0;
}





