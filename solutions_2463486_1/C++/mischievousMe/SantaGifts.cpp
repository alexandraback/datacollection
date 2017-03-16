#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<long long>palinsq;

void recurse(int l,long long n)
{
    if(l==0)
    {
        stringstream ss;
        ss<<n;
        string s=ss.str();
        int k=s.size();
        int fl=0;
        for(int i=0,j=k-1;i<j;i++,j--) if(s[i]!=s[j]) {fl=1; break;}
        if(fl) return;
        n*=n;
        stringstream s1;
        s1<<n;
        s=s1.str();
        k=s.size();
        fl=0;
        for(int i=0,j=k-1;i<j;i++,j--) if(s[i]!=s[j]) {fl=1; break;}
        if(fl) return;
        palinsq.pb(n);
        return;
    }
    for(int i=0;i<3;i++)
        recurse(l-1,n*10LL+i);
}

int main()
{
    //freopen("sb3.in","r",stdin);
    //freopen("sb3.out","w",stdout);
    palinsq.clear();
    int t,x=0;
    palinsq.pb(1);
    palinsq.pb(4);
    palinsq.pb(9);
    for(int l=2;l<=8;l++)
        for(int i=1;i<3;i++) recurse(l-1,i);
    int palinsz=palinsq.size();
    long long A,B;
    cin>>t;
    while(t--)
    {
        x++;
        int ans=0;
        cin>>A>>B;
        for(int i=0;i<palinsz;i++)
        {
            if(palinsq[i]>=A&&palinsq[i]<=B) ans++;
        }
        cout<<"Case #"<<x<<": "<<ans<<"\n";
    }
    return 0;
}
