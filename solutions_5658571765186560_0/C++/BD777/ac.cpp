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

char yes[] = "GABRIEL";
char no[] = "RICHARD";

int main() {
    freopen("D-small-attempt1.in","r",stdin);
    freopen("D-small-attempt1.out","w",stdout);
    int T;
    cin >> T;
    for(int kase=1;kase <=T;kase++) {
        bool flag = true;
        int x,r,c;
        cin >> x >> r >> c;
        int L = (x+1)/2;
        if(L > r || L > c) flag = false;
        if(r*c%x != 0) flag = false;
        if(x>=7) flag = false;
        if(x%2==0 && L+1 > r && L+1 > c) flag = false;
        printf("Case #%d: %s\n",kase,flag ? yes : no);
    }
}
