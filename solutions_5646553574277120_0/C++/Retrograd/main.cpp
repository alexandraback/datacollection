#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;
typedef int var;

#define MAX 100

bool Can[MAX];
bool In[MAX];

var c, d, v;

bool check() {
    memset(Can, 0, sizeof(Can));
    for(var i=1; i<=v; i++) {
        if(In[i]) {
            for(var j=v-i; j; j--) {
                if(Can[j])
                    Can[i+j] = 1;
            }
            Can[i] = 1;
        }
    }

    for(var i=1; i<=v; i++) {
        if(!Can[i])
            return false;
    }
    return true;
}

bool good(var num, var from, var chosen) {
    if(chosen == num)
        return check();
    if(from > v)
        return false;

    if(good(num, from+1, chosen))
        return true;

    if(In[from])
        return false;

    In[from] = 1;
    bool r = good(num, from+1, chosen+1);
    In[from] = 0;

    return r;
}

int main() {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);

    var t;
    var val;
    cin>>t;

    for(var tt=1; tt<=t; tt++) {
        cin>>c>>d>>v;

        memset(In, 0, sizeof(In));

        for(var i=1; i<=d; i++) {
            cin>>val;
            In[val] = 1;
        }

        var sol;
        for(sol=0; !good(sol, 1, 0); sol++);

        printf("Case #%d: %d\n", tt, sol);
        fflush(stdout);
    }

    return 0;
}
