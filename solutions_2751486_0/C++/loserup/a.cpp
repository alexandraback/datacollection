#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define A frist
#define B second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;

    //freopen("A_1.in","r",stdin);
    //freopen("A_1_out.txt","w",stdout);

char c[1000006];
int sum[1000006];
int len;
int ff(int i,int j)
{
    if(i==0)return sum[j] == len;

    int ret = sum[j] - sum[i-1];
    if(ret == len)return 1;
    return 0;
    //return ((sum[j]-sum[i-1]) == len);
}
int f(char s)
{
    if(s == 'a' || s == 'e' || s== 'i' || s== 'o' || s== 'u')return 0;
    return 1;
}
int main()
{
    freopen("A.in","r",stdin);
    freopen("A1_out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    rep(cas,T)
    {
        scanf("%s%d",c,&len);
        int n = strlen(c);
        rep(i,n)if(i==0)sum[0] = f(c[i]);else sum[i]=f(c[i])+sum[i-1];

        int j=-1;
        LL ret = 0;
        rep(i,n)
        {
            if(j+len-1 >= n)break;
            if(i>j)
            {
                j++;
                while(1)
                {
                    if(j+len-1>=n)break;
                    if(ff(j,j+len-1))
                        break;
                    j++;

                }
            }
            if(j+len-1 >= n)break;
            ret += (n - j - len + 1);

            //cout << ret << endl;
        }
        printf("Case #%d: %I64d\n",cas+1,ret);
    }
}











