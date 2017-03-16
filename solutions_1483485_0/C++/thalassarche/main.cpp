#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstdlib>

using namespace std;

int n;
string code="qejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string translation="zour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
char translateTo[26];

int main()
{
    for (int i=0;i<code.size();i++) if (code[i]!=' ') translateTo[code[i]-'a']=translation[i];
    char unusedCode, unusedTranslation;
    for (char c='a';c<='z';c++) {
        if (code.find(c)==string::npos) unusedCode=c;
        if (translation.find(c)==string::npos) unusedTranslation=c;
    }
    translateTo[unusedCode-'a']=unusedTranslation;

    cin >> n;
    string t;
    getline(cin,t);
    for (int i=0;i<n;i++) {
        getline(cin,t);
        cout << "Case #" << i+1 << ": ";
        for (int j=0;j<t.size();j++) {
            if (t[j]==' ') cout << ' ';
            else cout << translateTo[t[j]-'a'];
        }
        cout << endl;
    }
    return 0;
}
