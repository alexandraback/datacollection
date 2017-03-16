#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <ctime>
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define LL long long
#define ULL unsigned long long
#define R freopen("in","r",stdin)
#define W freopen("out","w",stdout)
using namespace std;
string str[101];
int main()
{
    R;W;
    int t;cin>>t;
    int kase=0;
    while(t--)
    {
        kase++;
        printf("Case #%d: ",kase);
        int a,b,k;
        cin>>a>>b>>k;
        int ans=0;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                int temp=i&j;
                if(temp<k)ans++;
            }
        }
        cout<<ans<<endl;
        
        
    }
}
