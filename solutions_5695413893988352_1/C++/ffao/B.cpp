#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
char c[20], j[20];
char tc[20], tj[20];
string bc, bj;
long long b;

void read() {
    scanf("%s %s", c, j);
}

long long labs(long long a) {
    if (a < 0) return -a;
    return a;
}

void check() {
    //printf("checking %s %s\n", tc,tj);
    string cc = tc, cj = tj;
    long long c, j;
    stringstream ss; ss << cc; ss >> c;
    stringstream ss2; ss2 << cj; ss2 >> j;

    //printf("c=%lld j=%lld\n", c,j);
    long long diff = labs(c-j);
    if (diff < b || (diff == b && cc < bc) || (diff == b && cc == bc && cj < bj)) {
        b = diff;
        bc = cc; bj = cj;
    }
}

void rec(int idx, long long diff, unsigned long long pot) {
    if (idx == n) {
        tc[idx]=tj[idx]=0;
        check();
        return;
    }

    if (c[idx] != '?' && j[idx] != '?') {
        tc[idx] = c[idx]; tj[idx] = j[idx];
        if (diff == 0 && c[idx] != j[idx]) {
            if (c[idx] > j[idx]) diff = 1;
            else diff = -1;
        }
        rec(idx+1,diff,pot);
        return;
    }

    if (c[idx] == '?') {
        if (j[idx] == '?') {
            if (diff > 0) {
                tc[idx]='0';
                tj[idx]='9';
                rec(idx+1,diff,pot/10);
            }
            else if (diff < 0) {
                tc[idx]='9';
                tj[idx]='0';
                rec(idx+1,diff,pot/10);
            }
            else {
                tc[idx]=tj[idx]='0';
                rec(idx+1,diff,pot/10);
                tc[idx]='1';tj[idx]='0';
                rec(idx+1,1,pot/10);
                tc[idx]='0';tj[idx]='1';
                rec(idx+1,-1,pot/10);
            }

            return;
        }

        tj[idx] = j[idx];
        if (diff > 0) {
            tc[idx] = '0';
            rec(idx+1,diff,pot/10);
        }
        else if (diff < 0) {
            tc[idx] = '9';
            rec(idx+1,diff,pot/10);
        }
        else {
            tc[idx]=tj[idx];
            rec(idx+1,0,pot/10);
            if (tj[idx]!='9') tc[idx]=tj[idx]+1;
            rec(idx+1,1,pot/10);
            if (tj[idx]!='0') tc[idx]=tj[idx]-1;
            rec(idx+1,-1,pot/10);
        }
        return;

    }

    tc[idx] = c[idx];
    if (diff > 0) {
        tj[idx] = '9';
        rec(idx+1,diff,pot/10);
    }
    else if (diff < 0) {
        tj[idx] = '0';
        rec(idx+1,diff,pot/10);
    }
    else {
        tj[idx]=tc[idx];
        rec(idx+1,diff,pot/10);
        if (tc[idx]!='9') tj[idx]=tc[idx]+1;
        rec(idx+1,-1,pot/10);
        if (tc[idx]!='0') tj[idx]=tc[idx]-1;
        rec(idx+1,1,pot/10);
    }
}

void solve() {
    b = 1000000000000000000ULL;
    n = strlen(c);

    unsigned long long pot = 1;
    REP(i,n-1) pot *= 10;
    rec(0, 0, pot);

    printf("%s %s\n", bc.c_str(), bj.c_str());
}


























int myMod = 0;
int howMany = 1;

int main(int argc, char** argv) {
    if (argc > 1) {
        stringstream ss; ss << argv[1]; ss >> myMod;
        ss.str(""); ss.clear();
        ss << argv[2]; ss >> howMany;
    }

    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        read();
        if (i % howMany == myMod) {
            printf("Case #%d: ", i+1);
            solve();
        }
    }
}