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

bool check(long long l, long long x, string s){
    dij e = {'1', 1};

    dij sd = e;
    for(int i = 0; i < (int)s.size(); i++) sd = fuck(sd, {s[i], 1});
    long long z = x;

    dij a = sd, b = e;
    while(z){
        if(z&1) b = fuck(b, a);
        a = fuck(a, a);
        z /= 2;
    }

    if(!(b.first == '1' && b.second == -1)) return false;

    string ss = "";
    int len = (int)min(l*x, 11451419LL);
    for(int i = 0; i < len; i++) ss += s[i%l];

    int state = 0;
    dij d = e;
    for(int i = 0; i < (int)len; i++){
        d = fuck(d, {ss[i], 1});
        if(state == 0 && d.first == 'i' && d.second == 1) state++;
        if(state == 1 && d.first == 'k' && d.second == 1) return true;
    }
    return false;
}

int main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        long long l, x; cin >> l >> x;
        string s; cin >> s;

        bool ans = check(l, x, s);
        cout << "Case #" << tc << ": " << (ans ? "YES" : "NO") << endl;
    }
}
