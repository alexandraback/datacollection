#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<sstream>
#include<bitset>
#include<deque>
#include<utility>
#include<cstdlib>
#include<iomanip>
#include<cctype>
#include<climits>
#include<iostream>
using namespace std;
#define ll             long long
#define ull            unsigned long long
string tostr(long long x) { stringstream ss; ss << x; return ss.str(); }
long long toint(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

int main()
{
freopen("A-small-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int test;
cin>>test;
for(int tt=1;tt<=test;tt++)
{
    string s,ss;
    int l,n,i,j,k,c=0;
    cin>>s>>l;
    n=s.size();
    int co=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n-i;j++)
        {
            co=0;
            for(k=j;k<j+i;k++)
            {

                if(co==l)
                break;
                if(s[k]!='a'&&s[k]!='e'&&s[k]!='i'&&s[k]!='o'&&s[k]!='u'&&s[k]!='A'&&s[k]!='E'&&s[k]!='I'&&s[k]!='O'&&s[k]!='U')
                {
                    co++;
                }
                else
                co=0;
                ss.push_back(s[k]);
            }
            if(co==l)
            c++;
            //cout<<ss<<endl;
            ss.clear();
        }
    }
    cout<<"Case #"<<tt<<": "<<c<<endl;
}
return 0;
}
