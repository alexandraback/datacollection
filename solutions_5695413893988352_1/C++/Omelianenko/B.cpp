#pragma comment(linker, ”/STACK:36777216“)
#include<bits/stdc++.h>

#define x first
#define y second
#define y0 hi1
#define y1 hi2
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(a) (a)*(a)
#define ld long double
#define all(a) (a).begin(), (a).end()
#define ull unsigned long long

using namespace std;

const int inf = 1000000000000000000;

string t1, t2, s1, s2, ans1, ans2;
ull dif, x, y;
int n;

ull toull(string s){
    ull x = 0;
    for(int i = 0; i < s.length(); i++){
        x = x * 10 + (s[i] - '0');
    }
    return x;
}

void go(int i, ull q, ull w, string t1, string t2){
    if(i > 0){
        t1 = t1 + char(q % 10 + '0');
        t2 = t2 + char(w % 10 + '0');
    }
    if(i == n){
        ull d;
        if(q > w)d = q - w; else d = w - q;
        if(d < dif || (d == dif && q < x) || (d == dif && q == x && w < y)){
            dif = d;
            x = q;
            y = w;
            ans1 = t1;
            ans2 = t2;
        }
        return;
    }

    int who;
    if(q == w){
        who = 0;
    } else
    if(q > w){
        who = 1;
    } else {
        who = 2;
    }

    if(who == 0){
        if(s1[i] == '?' && s2[i] == '?'){
            q = q * 10;
            w = w * 10;
            go(i + 1, q, w, t1, t2);
        } else
        if(s1[i] == '?'){
            w = w * 10 + (s2[i] - '0');

            q = q * 10 + (s2[i] - '0');
            go(i + 1, q, w, t1, t2);
            q /= 10;

            if(s2[i] - '0' > 0){
                q = q * 10 + (s2[i] - '0' - 1);
                go(i + 1, q, w, t1, t2);
                q /= 10;
            }

            if(s2[i] - '0' < 9){
                q = q * 10 + (s2[i] - '0' + 1);
                go(i + 1, q, w, t1, t2);
                q /= 10;
            }
        } else
        if(s2[i] == '?'){
            q = q * 10 + (s1[i] - '0');

            w = w * 10 + (s1[i] - '0');
            go(i + 1, q, w, t1, t2);
            w /= 10;

            if(s1[i] - '0' > 0){
                w = w * 10 + (s1[i] - '0' - 1);
                go(i + 1, q, w, t1, t2);
                w /= 10;
            }

            if(s1[i] - '0' < 9){
                w = w * 10 + (s1[i] - '0' + 1);
                go(i + 1, q, w, t1, t2);
                w /= 10;
            }
        } else {
            q = q * 10 + (s1[i] - '0');
            w = w * 10 + (s2[i] - '0');
            go(i + 1, q, w, t1, t2);

            if(q > w){
                q /= 10;
                w /= 10;
                for(int j = i - 1; j >= 0; j--){
                    q /= 10;
                    w /= 10;
                    if(s2[j] == '?' && s1[j] != '9'){
                        if(s1[j] == '?'){
                            q = q * 10;
                            w = w * 10 + 1;
                        } else {
                            q = q * 10 + (s1[j] - '0');
                            w = w * 10 + (s1[j] - '0' + 1);
                        }
                        t1 = t1.substr(0, j);
                        t2 = t2.substr(0, j);
                        go(j + 1, q, w, t1, t2);
                        break;
                    }
                }
            } else
            if(q < w){
                q /= 10;
                w /= 10;
                for(int j = i - 1; j >= 0; j--){
                    q /= 10;
                    w /= 10;
                    if(s1[j] == '?' && s2[j] != '9'){
                        if(s2[j] == '?'){
                            q = q * 10 + 1;
                            w = w * 10;
                        } else {
                            q = q * 10 + (s2[j] - '0' + 1);
                            w = w * 10 + (s2[j] - '0');
                        }
                        t1 = t1.substr(0, j);
                        t2 = t2.substr(0, j);
                        go(j + 1, q, w, t1, t2);
                        break;
                    }
                }
            }
        }
    } else
    if(who == 1){
        if(s1[i] == '?'){
            q = q * 10 + 0;
        } else {
            q = q * 10 + (s1[i] - '0');
        }
        if(s2[i] == '?'){
            w = w * 10 + 9;
        } else {
            w = w * 10 + (s2[i] - '0');
        }
        go(i + 1, q, w, t1, t2);
    } else
    if(who == 2){
        if(s1[i] == '?'){
            q = q * 10 + 9;
        } else {
            q = q * 10 + (s1[i] - '0');
        }
        if(s2[i] == '?'){
            w = w * 10 + 0;
        } else {
            w = w * 10 + (s2[i] - '0');
        }
        go(i + 1, q, w, t1, t2);
    }
}

string tostring(ull x, int ln){
    string r;
    while(x > 0){
        r = r + char(x % 10 + '0');
        x /= 10;
    }
    while(r.length() < ln){
        r = r + '0';
    }
    reverse(all(r));
    return r;
}

bool ok(int x, string s){
    string t = tostring(x, n);
    for(int i = 0; i < n; i++){
        if(s[i] == '?')continue;
        if(s[i] != t[i]){
            return false;
        }
    }
    return true;
}

string XS, YS;

void gostupid(){
    int difS = 1000;
    for(int i = 0; i < 1000; i++){
        if(ok(i, s1)){
            for(int j = 0; j < 1000; j++){
                if(ok(j, s2)){
                    if(abs(i - j) < difS){
                        difS = abs(i - j);
                        XS = tostring(i, n);
                        YS = tostring(j, n);
                    }
                }
            }
        }
    }
}

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    cin >> T;
    for(int num = 1; num <= T; num++){
        dif = inf,
        x = inf;
        y = inf;
        cout << "Case #"<< num << ": ";

        cin >> s1 >> s2;
        n = s1.length();

        string t1, t2;
        go(0, 0, 0, t1, t2);

        //cout << tostring(x, n) << " " << tostring(y, n) << "\n";
        cout << ans1 << " " << ans2 << "\n";
        //gostupid();
    }
}
