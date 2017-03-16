/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define pb push_back
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
bool vowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
char str[1000005];
int start[1000005];
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas = 0;
    long long int ans,ans1,ans2;
    while(t--)
    {
        memset(start,0,sizeof(start));
        ans = 0;
        ans1 = 0;
        ans2 = 0;
        cas++;
        int n;
        //cin >> str;
       // cin >> n;
        scanf("%s %d",str,&n);
        int len = strlen(str);
        for(int i=0;i<len;i++)
        {
            //int cnt=0;
            int flag = 0;
            int pos = 0;
            int tot;
            for(int j=i,c=1;j<len;j++,c++)
            {
               // cout << "ZZ";
                if(vowel(str[j]))
                    break;
                if(c >= n)
                {
                   // start[i] = 1;
                    pos = j;
                    tot = len - pos;
                    //cout << "YES" << pos;
                    flag = 1;
                    break;
                }
            }
            if(flag)
                for(int k=i;k>=0;k--)
                    if(!start[k])
                    {
                        ans1 += tot;
                        start[k] = 1;
                    }
          // ans += cnt;
        }
        //cout << "LOL" << ans1;
       /* for(int i=len-1;i>=0;i--)
        {
            //int cnt=0;
            int flag = 0;
            int pos;
            int tot;
            for(int j=i,c=1;j>=0;j--,c++)
            {
                if(vowel(str[j]))
                    break;
                if(c >= n)
                {
                    pos = j;
                    //cout << "ROFL" << pos;
                    tot = len - i;
                    flag = 1;
                    break;
                }
            }
            if(flag)
            for(int k=pos;k>=0;k--)
                if(!start[k])
                {
                    ans2 += tot;
                    start[k] = 1;
                }
            //if(flag)
               // ans2 += pos+1;
          // ans += cnt;
        }
*/
        //printf("%d %d\n",ans1,ans2);

        ans = ans1;
        printf("Case #%d: %lld\n",cas,ans);
    }
return 0;
}
