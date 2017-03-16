#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(v) v.begin(),v.end()

using namespace std;

int main()
{
	#ifdef ACMTUYO
	freopen("A-small.in","r",stdin);
	freopen("A.out","w",stdout);
	#endif
    string st1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    string st2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    string st3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string st31 = "our language is impossible to understand";
    string st32 = "there are twenty six factorial possibilities";
    string st33 = "so it is okay if you want to just give up";
    vector<char> vec(26,'?');
    forn(i,st1.size())
    {
        if(st1[i]!=' ')
            vec[st1[i]-'a'] = st31[i];
    }
    forn(i,st2.size())
    {
        if(st2[i]!=' ')
            vec[st2[i]-'a'] = st32[i];
    }
    forn(i,st3.size())
    {
        if(st3[i]!=' ')
            vec[st3[i]-'a'] = st33[i];
    }
    vec['q'-'a'] = 'z';
    vec['z'-'a'] = 'q';
    int n;
    cin >> n;
    string st;
    getline(cin,st);
    for(int caso=1;caso<=n;caso++)
    {
        getline(cin,st);
        forn(i,st.size())
        if(st[i]!=' ')
            st[i] = vec[st[i]-'a'];
        cout <<"Case #"<< caso << ": "<< st <<endl;
    }
}
