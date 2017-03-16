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
char s[55];
int dp[5000][6];
char st[621196][55];
int main()
{
    freopen("d.txt","r",stdin);
    int i=0;
    for(int i=0;i<521196;i++)scanf("%s",&st[i]);
    //while(cin>>st[i])i++;
    //fclose(stdin);
  //  freopen("CON","r",stdin);
    //freopen("A.txt","r",stdin);
    freopen("A.txt","w",stdout);
    int T;
    scanf("%d",&T);
    rep(cas,T)
    {
        scanf("%s",&s);
        //printf("%s\n",s);
        //cin>>s;
        // cout << s << endl;
        int n = strlen(s);
        rep(i,5000)rep(j,6)dp[i][j]=1000000000;
        dp[0][5]=0;
        for(int i=0;i<n;i++)
        {
            for(int q=0;q<=5;q++)
            {
                if(dp[i][q]!=1000000000)
                for(int j=0;j<521196;j++)
                {
                    int m = strlen(st[j]);
                    int pre = i-q;
                    int flag = 0;
                    if(i+m<=n)
                    {
                        int ret = dp[i][q];
                        for(int k=i,l=0;l<m;k++,l++)
                        {
                            if(s[k]!=st[j][l] && flag==0)
                            {
                                if(k-pre < 5)
                                {
                                    ret = 1000000000;
                                    flag=1;
                                    break;
                                }
                                ret++;
                                pre = k;
                            }
                        }
                        dp[i+m][min(5,i+m-pre)] = min(dp[i+m][min(5,i+m-pre)] ,ret);
                    }
                }
            }

        }
        int ret = 1000000000;
        rep(i,6)ret = min(ret,dp[n][i]);
        printf("Case #%d: %d\n",cas+1,ret);
        //cout << dp[n] << endl;
    }
}
