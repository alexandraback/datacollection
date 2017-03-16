#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<locale>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(a) (int((a).size()))
typedef istringstream iss; typedef ostringstream oss; typedef long long lli;
const double TOLL=1e-9;

string inp="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv z q";
string out="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up q z";

bool fo[26], fi[26];

int main()
{
    map<char,char> mp;
    for(int i=0;i<sz(out);i++)
    {
        mp[inp[i]]=out[i];
    }
    /*
    map<char,char>::iterator it=mp.begin();
    while(it!=mp.end())
    {
        cout<<it->first<<' '<<it->second<<endl;
        it++;
    }

    for(int i=0;i<26;i++) if(!fo[i])
    {
        char left=('a'+i),right;
        int j;
        for(j=0;j<26;j++) if(!fi[j]) break;
        right=('a'+j);
        cerr<<left<<' '<<right<<endl;
        mp[left]=right;
        //cerr<<i<<' '<<j<<endl;
    }
    //cout<<mp.size()<<endl;
    */
    int t; cin>>t; int cn=0; string line; getline(cin,line);
    while(t--)
    {
        getline(cin,line);
        printf("Case #%d: ",++cn); //cerr<<line.size();
        for(int i=0;i<sz(line);i++) cout<<mp[line[i]];
        cout<<endl;
    }
}
