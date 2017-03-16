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
int ar[105];
int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("A.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas = 0;
    while(t--)
    {
        cas++;
        int A,N;
        scanf("%d %d",&A,&N);
        for(int i=0;i<N;i++)
            scanf("%d",&ar[i]);
        sort(ar,ar+N);
        int sum = A,cnt = 0;
        int mcnt=0;
        int flag = 0;
        int ans = 1000000000;
        for(int i=0;i<N;i++)
        {
            if(ar[i]<sum)
                sum += ar[i];
            else
            {
               // cout << "LOL";
                mcnt = N-i;
                int tmp = mcnt + cnt;
                ans = min(tmp,ans);
                tmp = 0;
                while(sum <= ar[i])
                {
                    tmp++;
                    //cout << sum << endl;
                    sum += (sum-1);
                    cnt++;
                   // cout << sum << endl;
                    if(tmp>10)
                        break;
                }
                if(tmp<=10)
                sum += ar[i];
                else
                    break;
            }
           // printf("sum=%d\n",sum);
        }
       // printf("%d %d",mcnt,cnt);
        ans = min(ans,cnt);
        printf("Case #%d: %d\n",cas,ans);
    }
return 0;
}
