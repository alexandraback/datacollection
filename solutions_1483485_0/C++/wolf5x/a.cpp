#line 2 "GuessCard.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <assert.h>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).end()) i=(c).end(); i!=(c).begin(); --i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int mp[26];

void init()
{
    memset(mp, -1, sizeof(mp));
    string f = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    f += "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    f += "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string t = "our language is impossible to understand";
    t += "there are twenty six factorial possibilities";
    t += "so it is okay if you want to just give up";
    REP(i, f.length()){
        if(f[i] == ' ') continue;
        if(mp[f[i]-'a'] >= 0)
            assert(mp[f[i]-'a'] == t[i]-'a');
        else 
            mp[f[i]-'a'] = t[i]-'a';
    }
    mp['q'-'a'] = 'z'-'a';
    mp['z'-'a'] = 'q'-'a';
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin); freopen("a.out","w",stdout);
    init();
    int T;
    string f, t;
    cin >> T;
    getline(cin, f);
    FOR(CAS,1,T){
        getline(cin, f);
        t = f;
        REP(i,f.length()) 
            if(f[i] != ' ')
                t[i] = mp[f[i]-'a'] + 'a';
        cout << "Case #" << CAS << ": " <<  t << "\n";
    }
    return 0;
}
