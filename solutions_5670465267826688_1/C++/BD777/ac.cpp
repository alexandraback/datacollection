#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

#define bug puts("here");
#define lson o<<1
#define rson o<<1|1

using namespace std;

typedef long long ll;

const int maxn = 10086;

char yes[] = "YES";
char no[] = "NO";

bool neg[][4] = {{0,0,0,0},
                {0,1,0,1},
                {0,1,1,0},
                {0,0,1,1}};

int go[][4] = {{0,1,2,3},
                {1,0,3,2},
                {2,3,0,1},
                {3,2,1,0}};

bool ne;
int z;

void mul(bool neg1, int x, char y) {
    ne = neg1^neg[x][y-'i'+1];
    z = go[x][y-'i'+1];
}

bool gao(string &s) {
    //cout << s << ' ' << s.size() << endl;
    if(s.size() < 3) return false;
    ne = neg[s[0]-'i'+1][s[1]-'i'+1];
    z = go[s[0]-'i'+1][s[1]-'i'+1];
    int cnt = 0;
    if(s[0] == 'i') cnt = 1;
    if(!ne && z == 1) cnt = 1;
    if(!ne && cnt == 1 && z == 3) cnt = 2;
    //cout << ne << ' ' << z << endl;
    for(int i=2;i<s.size();i++) {
        mul(ne,z,s[i]);
        //cout << ne << ' ' << z << endl;
        if(ne) continue;
        if(cnt == 0 && z == 1) cnt = 1;
        if(cnt == 1 && z == 3) cnt = 2;
    }
    if(cnt == 2 && ne && z == 0) return true;
    return false;
}

int main() {
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T;
    cin >> T;
    for(int kase=1;kase <=T;kase++) {
        ll l,x;
        cin >> l >> x;
        string s;
        cin >> s;
        string t = s;
        bool flag = false;
        for(int i=1;i<=min(x,30ll);i++, s = s+t) {
            if((x-i)%4 != 0) continue;
            if(gao(s)) {
                flag = true;
                break;
            }
        }
        printf("Case #%d: %s\n",kase,flag ? yes : no);
    }
}
