#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;


int main() {
//    freopen("~/Desktop/in", "r", stdin);
//    freopen("~/Desktop/out", "w", stdout);
    ifstream cin("/Users/fengyelei/Desktop/in");
    ofstream cout("/Users/fengyelei/Desktop/out");
    int a[26];
    memset(a, -1, sizeof(a));
    a['y'-'a'] = 'a';
    a['e'-'a'] = 'o';
    a['q'-'a'] = 'z';
    a['z'-'a'] = 'q';
    string d[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
        "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    string t[3] = {"our language is impossible to understand",
        "there are twenty six factorial possibilities",
        "so it is okay if you want to just give up"};
    for (int i=0; i<3; i++) {
        for (int j=0; j<d[i].length(); j++) {
            if (d[i][j] == ' ') continue;
            a[d[i][j]-'a'] = t[i][j];
        }
    }
    int n;
    string s;
    //for (int i=0; i<26; i++) printf("%c %c\n",i+'a',a[i]);
    cin>>n;getline(cin,s);
    for (int i=1; i<=n; i++) {
        cout<<"Case #"<<i<<": ";
        getline(cin, s);
        for (int j=0 ;j<s.length(); j++) {
            if (s[j] == ' ') cout<<s[j];
            else cout<<(char)a[s[j]-'a'];
        }
        cout<<endl;
    }
}
