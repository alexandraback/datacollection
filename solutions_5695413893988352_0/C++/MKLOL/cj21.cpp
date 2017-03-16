#include<bits/stdc++.h>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
string dig[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[4400];
int N;
long long best1[20][20][20];
long long best2[20][20][20];

int cif(char x, int a) {
    if(x == '?') return 1;
    int c = x - '0';
    if ( c == a ) return 1;
    return 0;
}
long long best,C,J;
long long Cx, Jx, bit;
string s1,s2;
string sx,sy;
string sf,sf1;
void verif() {
    //cout << Cx << " " << Jx << endl;
    if(abs(Cx - Jx) < best) {
        best = abs(Cx - Jx);
        C=Cx;
        J=Jx;
        sf=sx;
        sf1=sy;
    }
    else if(best == abs(Cx - Jx) && C > Cx) {
        C=Cx;
        J=Jx;
        sf=sx;
        sf1=sy;
    } else if(best == abs(Cx - Jx) && C == Cx && J > Jx) {
        C=Cx;
        J=Jx;
        sf=sx;
        sf1=sy;
    }
}

void backx(int k) {
    //cout << k << endl;
    if(k == s1.size()) {
        verif();
        return;
    }
    for(int d1=0;d1<=9;++d1) {
        for(int d2=0;d2<=9;++d2) {
            if(cif(s1[k],d1) && cif(s2[k],d2)) {
               // cout << "WTF";
            Cx *= 10;
            Cx += d1;
            Jx *= 10;
            Jx += d2;
            sx.push_back((char) (d1 + '0'));
            sy.push_back((char) (d2 + '0'));
            backx(k+1);
            sx.pop_back();
            sy.pop_back();
            Cx /= 10;
            Jx /= 10;
            }
        }
    }
}

int main() {
    freopen("test.in","r",stdin);
    freopen("test6.out","w",stdout);
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        cin >> s1 >> s2;
        sf="";
        sf1="";
        best = 1000000000LL * 1000000000LL + 1LL;
        backx(0);
        printf("Case #%d: ",tt);
        cout << sf << " " << sf1 << endl;

    }
}
