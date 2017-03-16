#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iomanip>
#include<unordered_map>

using namespace std;
typedef int64_t var;

var k, l, s;
char sir[500];
char Keys[500];
char Target[500];

var fact(var n) {
    if(n == 0)
        return 1;
    return n * fact(n-1);
}

var cnt = 0;
var maxcnt = -1;
var sols = 0;

void checkword() {
    sols++;
    char *p = strstr(sir, Target);
    var cnt2 = 0;
    while(p != NULL) {
        cnt ++;
        cnt2++;
        p = strstr(p+1, Target);
    }
    maxcnt = max(maxcnt, cnt2);
}

void gen(var pas) {
    if(pas > s) {
        checkword();
        return;
    }
    for(var i=1; i<=k; i++) {
        sir[pas-1] = Keys[i-1];
        gen(pas+1);
    }
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);

    var t;
    cin>>t;

    cout<<fixed<<setprecision(9);

    for(var tt=1; tt<=t; tt++) {
        cin>>k>>l>>s;
        cin>>Keys;
        cin>>Target;

        cnt = 0;
        maxcnt = -1;
        sols = 0;

        gen(1);
        double rez = maxcnt - 1.0*cnt / sols;
        cout<<"Case #"<<tt<<": "<<rez<<endl;
        cout.flush();
    }


    return 0;
}
