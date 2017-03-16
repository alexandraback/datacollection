#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sd(t);
    int i;
    vi arr(26,0);
    arr[0]=arr['e'-'a']=arr['i'-'a']=arr['o'-'a']=arr['u'-'a']=1;
    FOR(i,0,t)
    {
        string str;
        cin>>str;sd(n);
        int j,k,l=sz(str);
        int ans=0;
        FOR(j,0,l)
        {
            FOR(k,1,l-j+1)
            {
                string temp=str.substr(j,k);
                int m=0,cnt=0;
                while (m<sz(temp))
                {
                    if (arr[temp[m]-'a']==0)
                    {
                        cnt++;
                    }
                    else cnt=0;
                    if (cnt>=n) break;
                    m++;
                }
                if (m<sz(temp))
                {
                    ans++;
//                    cout<<temp<<endl;
                }
            }
        }
        printf("Case #%d: ",i+1);
        p(ans);
    }
}
