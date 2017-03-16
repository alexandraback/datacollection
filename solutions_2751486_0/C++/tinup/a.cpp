/*Author : Punit Singh */
// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>
//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
void precompute()
{

}
bool cons(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
        return false;
    return true;
}
bool check(string &a,int n)
{
    //cout<<"initial "<<a<<endl;
    int l=sz(a),cnt=0,i,j=0;
    for(i=0;i<l;i++)
    {
        if(!j&&cons(a[i]))
        {
            cnt++;
            j=1;
        }
        else if(j&&!cons(a[i]))
        {
            if(cnt>=n)
                return true;
            j=0;
            cnt=0;
        }
        else if(j&&cons(a[i]))
            cnt++;
    }
    if(cnt>=n)
    {
        return true;
    }
    return false;
}
int main()
{
    #ifdef TEST
    freopen("A-small-attempt0.in","r",stdin);
 	freopen("out.txt","w",stdout);
    #endif
    precompute();
    int t,ctr=1,n,l,ans;
    string s,x;
    cin>>t;
    while(ctr<=t)
    {
        cin>>s>>n;
        ans=0;
        l=sz(s);
        rep(i,l)
        {
            FOR(j,i+1,l+1)
            {
                x=s.substr(i,j-i);
                if(check(x,n))
                    ans++;
            }
        }
        printf("Case #%d: %d\n",ctr++,ans);
    }
    return 0;
}
