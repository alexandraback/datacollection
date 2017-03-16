#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> dij;

dij fuck(dij a, dij b){
    dij res = {'X', 1};

    char A = a.first, B = b.first;
    if(A == '1'){
        if(B == '1'){res.first = '1';}
        if(B == 'i'){res.first = 'i';}
        if(B == 'j'){res.first = 'j';}
        if(B == 'k'){res.first = 'k';}
    }
    if(A == 'i'){
        if(B == '1'){res.first = 'i';}
        if(B == 'i'){res.first = '1'; res.second = -1;}
        if(B == 'j'){res.first = 'k';}
        if(B == 'k'){res.first = 'j'; res.second = -1;}
    }
    if(A == 'j'){
        if(B == '1'){res.first = 'j';}
        if(B == 'i'){res.first = 'k'; res.second = -1;}
        if(B == 'j'){res.first = '1'; res.second = -1;}
        if(B == 'k'){res.first = 'i';}
    }
    if(A == 'k'){
        if(B == '1'){res.first = 'k';}
        if(B == 'i'){res.first = 'j';}
        if(B == 'j'){res.first = 'i'; res.second = -1;}
        if(B == 'k'){res.first = '1'; res.second = -1;}
    }

    res.second *= a.second * b.second;
    return res;
}

bool brute(int l, int x, string ss){
    string s = ""; while(x--) s += ss;

    dij e = {'1', 1};
    int state = 0;
    dij d = e;
    for(int i = 0; i < (int)s.size(); i++){
        d = fuck(d, {s[i], 1});
        if(state == 0 && d.first == 'i' && d.second == 1){state++; d = e;}
        if(state == 1 && d.first == 'j' && d.second == 1){state++; d = e;}
    }
    return state == 2 && d.first == 'k' && d.second == 1;
}

int main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int l, x; cin >> l >> x;
        string s; cin >> s;

        bool ans;
        if(l * 1LL * x <= 1145140){
            ans = brute(l, x, s);
        } else {
        }
        cout << "Case #" << tc << ": " << (ans ? "YES" : "NO") << endl;
    }
}
