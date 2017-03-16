#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
#define ll long long
const long long LINF = ~(((long long)0x1)<<63)/2;
const int INF=0X3F3F3F3F;
const double eps=1e-7;
string a[3]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
             "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
             "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string b[3]={"our language is impossible to understand",
             "there are twenty six factorial possibilities",
            "so it is okay if you want to just give up"};
char trans[1000];
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int i,j,k,n,cas=1;
    for(i=0;i<3;i++)
        for(j=0;j<a[i].size();j++)
            trans[a[i][j]]=b[i][j];
    trans['q']='z';
    trans['z']='q';
    cin>>n;
    string s;
    char t[100];
    gets(t);
    for(cas=1;cas<=n;cas++)
    {
        printf("Case #%d: ",cas);
        getline(cin,s);
        for(j=0;j<s.size();j++)
            cout<<trans[s[j]];
        cout<<endl;
    }
    return 0;
}
