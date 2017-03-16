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

using namespace std;

const int inf = 2000000000;

int b[26], a[10];

bool can(string s, int p = 0){
    int n = s.length();
    if(p == 1){
        for(int i = 0; i < n; i++){
            b[s[i] - 'A']--;
        }
        return true;
    }

    int c[26];
    memset(c, 0, sizeof(c));
    for(int i = 0; i < n; i++){
        c[s[i] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(c[i] > b[i])return false;
    }
    return true;
}

void dec(int x, string s){
    while(can(s)){
        a[x]++;
        can(s, 1);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for(int num = 1; num <= T; num++){
        cout << "Case #" << num <<": ";

        string s;
        cin >> s;
        int n = s.length();
        for(int i = 0; i < n; i++){
            b[s[i] - 'A']++;
        }

        dec(0, "ZERO");
        dec(2, "TWO");
        dec(4, "FOUR");
        dec(6, "SIX");
        dec(8, "EIGHT");
        dec(3, "THREE");
        dec(7, "SEVEN");
        dec(5, "FIVE");
        dec(1, "ONE");
        dec(9, "NINE");

        string ans;
        for(int i = 0; i < 10; i++){
            while(a[i] > 0){
                a[i]--;
                ans += char(i + '0');
            }
        }
        cout << ans << "\n";
    }
}
