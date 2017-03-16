// A.cpp
//
// Problem A. Speaking in Tongues
//
#include <cassert>
#include <iostream>
#include <map>
#include <string>
using namespace std;

const string g[4]={ 
    "yeq",
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv", };
const string s[4]={
    "aoz",
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up", };

map<char, char> mp;
int cnt[2][30]; // gg, ss

int main()
{
    for(int i=0; i<4; ++i) {
        assert(s[i].size() == g[i].size());
        for(int p=0; p<int(s[i].size()); ++p) {
            char ss, gg;
            ss = s[i][p]; gg = g[i][p];
            cnt[0][gg-'a']=1; cnt[1][ss-'a']=1;
            if (mp.count(gg)) assert(mp[gg]==ss);
            else mp[gg]=ss;
        }
    }

    char c1, c2;
    for(char ch='a'; ch<='z'; ++ch) if (cnt[0][ch-'a']==0) c1=ch;
    for(char ch='a'; ch<='z'; ++ch) if (cnt[1][ch-'a']==0) c2=ch;
    mp[c1]=c2;
    assert(mp.size()==27);

//    cout << "mapping\n";
//    for(char ch='a'; ch<='z'; ++ch) {
//        cout << ch << " -> " << mp[ch] << endl;
//    }

    int T; cin >> T; cin.ignore(1024, '\n');
    for(int t=0; t<T; ++t) {
        string line; 
        getline(cin, line);
        for(int i=0; i<int(line.size()); ++i)
            line[i] = mp[line[i]];
        cout << "Case #" << (t+1) << ": ";
        cout << line << endl;
    }
}
