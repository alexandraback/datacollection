#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include <cstdlib>
#include<climits>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

#define IOR(x) freopen(x,"r",stdin);
#define IOW(x) freopen(x,"w",stdout);
#define DEBUG if(1)

#define i64 long long
#define u64 unsigned long long
#define eps 1e-10

#define REPI(i,a,b) for(i=a;i<=b;++i)
#define REPD(i,a,b) for(i=a;i>=b;--i)

#define pb(p) push_back(p)
#define ms(p,v) memset(p,v,sizeof(p))
#define pii pair< int, int >
#define mp(a,b) make_pair(a,b)
#define clr(a) a.clear();
#define ff first
#define sd second

int main()
{
    DEBUG IOR("i.txt");
    DEBUG IOW("o.txt");
    int t,l,n,cases=0,ans,i,j,s;
    string a,temp;
    while(cin>>t){
    while(t--)
    {
        ans=0;
        j=-1;
        cin>>a>>n;
        l=a.length();
        s=-1;
        REPI(i,0,l-1)
        {
            if((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))
            j=-1;
            else
            {
                if(j==-1)
                j=i;
            }
            if((j!=-1)&&((i-j+1)==n))
            {
                if(s==-1)
                ans+=((j+1)*(l-i));
                else
                ans+=((j-s)*(l-i));
                s=j++;
            }
        }
        printf("Case #%d: %d\n",++cases,ans);
    }}
    return 0;
}
   
