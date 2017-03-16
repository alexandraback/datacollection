#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <list>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<(int)b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair <int, int> pii;
#define debug(x) cerr << #x << " = " << (x) << \
" (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template <class T> void debugall(T a, T b) { cerr << " (L" << __LINE__ << ") "; for(T i = a; i != b; i++) cerr << *i << ", "; cerr << endl; }


int main() {
    map <char, char> dict;
    dict['y'] = 'a';
    dict['e'] = 'o';
    dict['q'] = 'z';
    string in = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string out = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
    int i;
    for(i = 0; i < (int)in.length(); i++) dict[in[i]] = out[i];
    char a2z[26];
    for(i = 0; i < 26; i++) a2z[i] = 'a'+i;
    char tmp = 'a';
    while(tmp != ('z'+1)){
        if(dict.find(tmp) != dict.end()) a2z[dict[tmp]-'a'] = ' ';
        cout << tmp << " " << dict[tmp] << endl;
        tmp++;
    }
    for(i = 0 ; i < 26; i++){
        cerr << a2z[i];
    }
    return 0;
}
