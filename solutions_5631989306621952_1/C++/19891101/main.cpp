
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <string>
#include <map>
#include <assert.h>
#include <time.h>
#include <list>
#include <deque>


#include <fstream>
#include <sstream>

#include <iomanip>


#define FFF freopen("test","r",stdin)
using namespace std;

const int N=1005;
const int mod=1000000007;


char s[N];
int f[N][26];

int n;

int h[N];

int main()
{

    freopen("A-large.in","r",stdin);;
    freopen("ans","w",stdout);
    int T;
    scanf("%d",&T);
    int num=0;
    while(T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=0;i<26;i++) f[0][i]=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<26;j++) f[i][j]=f[i-1][j];
            f[i][s[i]-'A']=i;
        }
        memset(h,0,sizeof(h));
        printf("Case #%d: ",++num);
        for(int i=n;i>=1;i--)
        {
            int Max=s[i]-'A';
            if(i>1)
            {
                for(int j=25;j>=0;j--) if(f[i-1][j]!=-1)
                {
                    Max=max(Max,j); break;
                }
            }
            if(Max==s[i]-'A')
            {
                putchar(s[i]);
                h[i]=1;
            }
        }
        for(int i=1;i<=n;i++) if(!h[i]) putchar(s[i]);
        puts("");
    }
}
