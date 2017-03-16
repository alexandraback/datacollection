#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <cassert>

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,Be,En) for(int (i)=(Be);(i)<=(En);++(i))
#define DFOR(i,Be,En) for(int (i)=(Be);(i)>=(En);--(i))
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a,0,sizeof(a))

#define LL  long long
#define VI  vector<int>
#define PAR pair<int ,int> 

using namespace std;
void __never(int a){printf("\nOPS %d", a);}
void __die(int a){printf("%d",(a*a)/(a+a));}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();__die(0);}}


void init()
{
	// freopen("b.in","r",stdin);
	// freopen("B-small-attempt0.in","r",stdin);
	// freopen("B-small-attempt1.in","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("b.out","w",stdout);
}

void check(string before, string after)
{
    assert(SZ(before) == SZ(after));
    FA(i, after) {
        assert(after[i] == before[i] || before[i] == '?');
    }
}

LL f(std::string a, char ch) {
    FA(i, a) if (a[i] == '?') a[i] = ch;
    std::stringstream ss(a);
    LL res;
    ss >> res;
    return res;
}

std::string frm(LL a, int n) {
    std::stringstream ss;
    ss << a;
    auto result = ss.str();
    while (result.size() < n) {
        result = "0" + result;
    }
    return result;
}

void update(LL& ra, LL& rb, LL aa, LL bb)
{
    if (ra == -1) {
        ra = aa; rb = bb;
    } else if (abs(ra - rb) > abs(aa - bb)) {
        ra = aa; rb = bb;
    } else if (abs(ra - rb) == abs(aa - bb)) {
        if (aa < ra) {
            ra = aa; rb = bb;
        } else if (aa == ra && bb < rb) {
            ra = aa; rb = bb;
        }
    }
}

string sol2(std::string A, std::string B)
{
    string a = A, b = B;
    assert(SZ(a) == SZ(b));
    int n = SZ(a);
    LL ra = -1, rb = -1;
    FOR(i, 0, n - 1) {
        if (a[i] == '?' || b[i] == '?') {
            if (a[i] == '?' && b[i] == '?') {
                a[i] = '1';
                b[i] = '0';
                update(ra, rb, f(a, '0'), f(b, '9'));
                a[i] = '0';
                b[i] = '1';
                update(ra, rb, f(a, '9'), f(b, '0'));
                a[i] = '0';
                b[i] = '0';
            } else if (a[i] == '?') {
                if (b[i] > '0') {
                    a[i] = b[i] - 1;
                    update(ra, rb, f(a, '9'), f(b, '0'));
                }
                if (b[i] < '9') {
                    a[i] = b[i] + 1;
                    update(ra, rb, f(a, '0'), f(b, '9'));
                }
                a[i] = b[i];
            } else {
                if (a[i] > '0') {
                    b[i] = a[i] - 1;
                    update(ra, rb, f(a, '0'), f(b, '9'));
                }
                if (a[i] < '9') {
                    b[i] = a[i] + 1;
                    update(ra, rb, f(a, '9'), f(b, '0'));
                }
                b[i] = a[i];
            }
        } else if (a[i] != b[i]) {
            if (a[i] < b[i]) {
                update(ra, rb, f(a, '9'), f(b, '0'));
            } else {
                update(ra, rb, f(a, '0'), f(b, '9'));
            }
        }
    }
    update(ra, rb, f(a, '0'), f(b, '9'));

    return frm(ra, n) + " " + frm(rb, n);
}

std::string sol(std::string A, std::string B){
    string a = A, b = B;
    assert(SZ(a) == SZ(b));
    int n = SZ(a);
    bool ls = false; // a < b
    bool swapped = false;
    FOR(i,0,n-1) {
        if (ls) {
            if (a[i] == '?') a[i] = '9';
            if (b[i] == '?') b[i] = '0';
        } else {
            if (a[i] == '?' || b[i] == '?') {
                if (a[i] == '?' && b[i] == '?') {
                    a[i] = b[i] = '0';
                } else if (a[i] == '?') {
                    a[i] = b[i];
                } else {
                    b[i] = a[i];
                }
            } else {
                if (a[i] != b[i]) {
                    if (a[i] > b[i]) {
                        swap(a, b);
                        swapped = true;
                    }
                    ls = true;
                }
            }
        }
    }
    if (swapped) swap(a, b);
    check(A,a);
    check(B,b);
    return a + " " + b;
}

bool match(int a, string s)
{
    RFA(i, s) {
        int r = a % 10;
        a /= 10;
        if (s[i] != '?' && s[i] != r + '0') {
            return false;
        }
    }
    return true;
}

std::string stupid(string a, string b) {
    int p = 1;
    FA(i, a) {
        p *= 10;
    }
    
    int ra = -1, rb = -1;
    
    FOR(aa, 0, p - 1) {
        if (match(aa, a)) {
            FOR(bb, 0, p - 1) {
                if (match(bb, b)) {
                    if (ra == -1) {
                        ra = aa; rb = bb;
                    } else if (abs(ra - rb) > abs(aa - bb)) {
                        ra = aa; rb = bb;
                    } else if (abs(ra - rb) == abs(aa - bb)) {
                        if (aa < ra) {
                            ra = aa; rb = bb;
                        } else if (aa == ra && bb < rb) {
                            ra = aa; rb = bb;
                        }
                    }
                }
            }
        }
    }
    int n = SZ(a);
    string res;
    FOR(i,0,n-1) {
        res = string(1, rb % 10 + '0') + res;
        rb /= 10;
    }
    
    res = " " + res;
    
    FOR(i,0,n-1) {
        res = string(1, ra % 10 + '0') + res;
        ra /= 10;
    }
    
    return res;
}

int main()
{
	init();
    int T;
    cin >> T;
    std::string s1, s2;
    FOR(t,1,T) {
        cin >> s1 >> s2;
        // auto answer = stupid(s1, s2);
        // auto output = sol2(s1, s2);
        // if (answer != output) {
            // std::cout << "Case #" << t << "\n" << s1 << "\n" << s2
            // << "\noutput " << output << "\nanswer " << answer << "\n";
        // }
        
        std::cout << "Case #" << t << ": " << sol2(s1, s2) << std::endl;
    }
	return 0;
}