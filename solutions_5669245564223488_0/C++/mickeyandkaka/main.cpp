#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define clr(a,b)	(memset(a,b,sizeof(a)))
#define rep(i,a)	for(int i=0; i<(int)a.size(); i++)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;


int T, n;
string s[20];
int l[20];

int a[20];
int pre[30];

int main()
{
    freopen("D:\\B-small-attempt3.in","r",stdin);
    freopen("D:\\out.txt","w",stdout);

	ios::sync_with_stdio(false);

    cin>>T;
    int cas = 1;
    while(T--)
    {
        cin>>n;
        int sz = 0;
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            sz += s[i].size();
            a[i] = i;
        }

        int ans = 0;
        do
        {
        	string cur = "";
            for(int i=0; i<n; i++)
                cur += s[ a[i] ];

			bool fg = true;
			int num;

            clr(pre, -1);
            for(int i=0; i<sz; i++)
            {
                num = cur[i] - 'a';

                if(pre[num] == -1)
                    pre[num] = i;
                else
                {
                    if(pre[num] != i-1)
					{
						fg = false;
						break;
					}
                    pre[num] = i;
                }
            }

            if(fg)
                ans++;
        }
        while(next_permutation(a,a+n));

        printf("Case #%d: %d\n",cas++,ans);

    }

    return 0;
}
