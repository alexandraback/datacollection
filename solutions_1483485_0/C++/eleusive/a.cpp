#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string mappingsa[]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"yeqz"};

string mappingsb[]={"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up",
"aozq"};

int mapping[26];

string solve() {
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++) if(s[i]!=' ')
        s[i]=mapping[s[i]-'a']+'a';
    return s;
}

int main() {
    for(int i=0;i<26;i++) mapping[i]=i;
    for(int i=0;i<4;i++)
        for(int j=0;j<mappingsa[i].size();j++) {
            char a=mappingsa[i][j];
            char b=mappingsb[i][j];
            mapping[a-'a']=b-'a';
        }
    int cases;
    cin>>cases;
    string s;
    getline(cin,s);
    for(int cnum=1;cnum<=cases;cnum++) {
        cout<<"Case #"<<cnum<<": "<<solve()<<endl;
    }
}
