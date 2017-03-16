#include<bits/stdc++.h>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
string dig[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
long long cnt[4400];
long long N;
long long best1[20][20][20];
long long best2[20][20][20];

long long cif(char x, long long a) {
    if(x == '?') return 1;
    long long c = x - '0';
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

void backx(long long k) {
    if(k == s1.size()) {
        verif();
        return;
    }
    if(Jx == Cx) {
        if(s1[k] == '?' && s2[k] != '?') {
            long long c = s2[k] - '0';
            Cx *= 10;
            Cx += c;
            Jx *= 10;
            Jx += c;
            sx.push_back((char) (c + '0'));
            sy.push_back((char) (c + '0'));
            backx(k+1);
            sx.pop_back();
            sy.pop_back();
            Cx /= 10;
            Jx /= 10;

            long long c1 = c-1;
            if(c1 >= 0) {
                Cx *= 10;
                Cx += c1;
                Jx *= 10;
                Jx += c;
                sx.push_back((char) (c1 + '0'));
                sy.push_back((char) (c + '0'));
                backx(k+1);
                sx.pop_back();
                sy.pop_back();
                Cx /= 10;
            Jx /= 10;
            }

            c1 = c + 1;
            if(c1 < 10) {
                Cx *= 10;
                Cx += c1;
                Jx *= 10;
                Jx += c;
                sx.push_back((char) (c1 + '0'));
                sy.push_back((char) (c + '0'));
                backx(k+1);
                sx.pop_back();
                sy.pop_back();
                Cx /= 10;
                Jx /= 10;
            }
        }
        if(s1[k] != '?' && s2[k] == '?') {
            long long c = s1[k] - '0';
            Cx *= 10;
            Cx += c;
            Jx *= 10;
            Jx += c;
            sx.push_back((char) (c + '0'));
            sy.push_back((char) (c + '0'));
            backx(k+1);
            sx.pop_back();
            sy.pop_back();
             Cx /= 10;
            Jx /= 10;

            long long c1=c-1;
            if(c1 >= 0) {
                Cx *= 10;
                Cx += c;
                Jx *= 10;
                Jx += c1;
                sx.push_back((char) (c + '0'));
                sy.push_back((char) (c1 + '0'));
                backx(k+1);
                sx.pop_back();
                sy.pop_back();
                Cx /= 10;
                Jx /= 10;
            }

            c1 = c + 1;
            if( c1 < 10) {
                Cx *= 10;
                Cx += c;
                Jx *= 10;
                Jx += c1;
                sx.push_back((char) (c + '0'));
                sy.push_back((char) (c1 + '0'));
                backx(k+1);
                sx.pop_back();
                sy.pop_back();
                Cx /= 10;
                Jx /= 10;
            }
        }
        if(s1[k] == '?' && s2[k] == '?') {
            long long c = 0;
            Cx *= 10;
            Cx += c;
            Jx *= 10;
            Jx += c;
            sx.push_back((char) (c + '0'));
            sy.push_back((char) (c + '0'));
            backx(k+1);
            sx.pop_back();
            sy.pop_back();
            Cx /= 10;
            Jx /= 10;

            long long c1 = 0;
            long long c2 = 1;
            Cx *= 10;
            Cx += c1;
            Jx *= 10;
            Jx += c2;
            sx.push_back((char) (c1 + '0'));
            sy.push_back((char) (c2 + '0'));
            backx(k+1);
            sx.pop_back();
            sy.pop_back();
             Cx /= 10;
            Jx /= 10;

            c1 = 1;
            c2 = 0;
            Cx *= 10;
            Cx += c1;
            Jx *= 10;
            Jx += c2;
            sx.push_back((char) (c1 + '0'));
            sy.push_back((char) (c2 + '0'));
            backx(k+1);
            sx.pop_back();
            sy.pop_back();
            Cx /= 10;
            Jx /= 10;
        }
        if(s1[k] != '?' && s2[k] != '?') {
            long long c1 = s1[k] - '0';
            long long c2 = s2[k] - '0';
            Cx *= 10;
            Cx += c1;
            Jx *= 10;
            Jx += c2;
            sx.push_back((char) (c1 + '0'));
            sy.push_back((char) (c2 + '0'));
            backx(k+1);
            sx.pop_back();
            sy.pop_back();
            Cx /= 10;
            Jx /= 10;
        }
    } else if(Cx > Jx) {
        long long c1 = 0;
        long long c2 = 9;
        if(s1[k] != '?') {
            c1 = s1[k] - '0';
        }
        if(s2[k] != '?') {
            c2 = s2[k] - '0';
        }
        Cx *= 10;
        Cx += c1;
        Jx *= 10;
        Jx += c2;
        sx.push_back((char) (c1 + '0'));
        sy.push_back((char) (c2 + '0'));
        backx(k+1);
        sx.pop_back();
        sy.pop_back();
        Cx /= 10;
        Jx /= 10;
    } else if(Jx > Cx) {
        long long c1 = 9;
        long long c2 = 0;
        if(s1[k] != '?') {
            c1 = s1[k] - '0';
        }
        if(s2[k] != '?') {
            c2 = s2[k] - '0';
        }
        Cx *= 10;
        Cx += c1;
        Jx *= 10;
        Jx += c2;
        sx.push_back((char) (c1 + '0'));
        sy.push_back((char) (c2 + '0'));
        backx(k+1);
        sx.pop_back();
        sy.pop_back();
        Cx /= 10;
        Jx /= 10;
    }
}

int main() {
    freopen("test.in","r",stdin);
    freopen("test10.out","w",stdout);
    long long T;
    cin >> T;
    for (long long tt=1;tt<=T;++tt) {
        cin >> s1 >> s2;
        sf="";
        sf1="";
        best = 1000000000LL * 1000000000LL + 1LL;
        backx(0);
        printf("Case #%lld: ",tt);
        cout << sf << " " << sf1 << endl;

    }
}
