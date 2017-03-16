
#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LL long long
#define sd(x) scanf("%d", &x)
#define sld(x) scanf("%lld", &x)
#define MOD 1000000007
#define SQ 112345
#define N 1123456
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, A, B) for (int I = A; I <= B; ++I)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>

int f[40010], l[40010];

int a[5][5];

int make(string s, int x, int y, int z){
    int val, cnt, i, j;
    val = 1;
    cnt = 0;
    for(i = 0; i < s.length(); i++){
        val = a[val][s[i] - '0'];
        if(val < 0){
            cnt = 1 - cnt;
            val *= -1;
        }
        if(val == 2 && cnt == x){
            f[i] = 1;
        }
        else f[i] = 0;
    }
    for(i = 0; i < s.length(); i++){
        val = 1;
        cnt = 0;
        for(j = i; j < s.length(); j++){
            val = a[val][s[j] - '0'];
            if(val < 0){
                cnt = 1 - cnt;
                val *= -1;
            }
        }
        if(val == 4 && cnt == z){
            l[i] = 1;
        }
        else l[i] = 0;
    }
    for(i = 0; i < s.length(); i++){
        if(f[i] == 1){
            val = 1;
            cnt = 0;
            for(j = i + 1; j < s.length(); j++){
                val = a[val][s[j] - '0'];
                if(val < 0){
                    cnt = 1 - cnt;
                    val *= -1;
                }
                if(j + 1 < s.length() && l[j + 1] == 1){
                    if(val == 3 && cnt == y){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int solve(){
    int l, x, i;
    cin>>l>>x;
    string s, t = "";
    cin>>s;
    for(i = 0; i < s.length(); i++){
        if(s[i] == 'i') s[i] = '2';
        if(s[i] == 'j') s[i] = '3';
        if(s[i] == 'k') s[i] = '4';
    }
    while(x--){
        t += s;
    }
    if(make(t, 0, 0, 0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    freopen("3sin.txt", "r", stdin);
    freopen("3sout.txt", "w", stdout);
    int t = 1, o = 1;
    a[1][1] = 1;
    a[1][2] = 2;
    a[1][3] = 3;
    a[1][4] = 4;

    a[2][1] = 2;
    a[2][2] = -1;
    a[2][3] = 4;
    a[2][4] = -3;

    a[3][1] = 3;
    a[3][2] = -4;
    a[3][3] = -1;
    a[3][4] = 2;

    a[4][1] = 4;
    a[4][2] = 3;
    a[4][3] = -2;
    a[4][4] = -1;

    cin>>t;
    while(t--){
        cout<<"Case #"<<o++<<": ";
        solve();
    }
    return 0;
}
