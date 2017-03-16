#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cctype>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<map>
#include<set>
#define pi (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
#define SZ 621196
#define INF 100000
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int sz[SZ],cnt,n,dp[5000];
char s[SZ][11],str[5000];
int main()
{
	FILE *in=fopen("C-small-attempt1.in","r");
	//FILE *in=fopen("in.txt","r",stdin);
	freopen("Cout.txt","w",stdout);
	FILE *fin=fopen("dictonary.txt","r");
	while(fscanf(fin,"%s",s[cnt])!=EOF)
	{
	    //cout<<cnt<<endl;
	    sz[cnt]=strlen(s[cnt]);
	    cnt++;
	}
	fclose(fin);
	//cout<<cnt<<endl;
	int t,T,i,j,k,er,lerr;
	fscanf(in,"%d",&T);
	//cout<<T<<endl;
	for(t=1;t<=T;t++)
	{
	    assert(t<=20);
	    fscanf(in,"%s",str);
	    n=strlen(str);
        for(i=1;i<=n;i++)
        {
            dp[i]=INF;
            rep(j,cnt)
            {
                if(sz[j]>i)
                    continue;
                er=0;
                lerr=-10;
                rep(k,sz[j])
                {
                    if(str[i-sz[j]+k]!=s[j][k])
                    {
                        if(k-lerr<5)
                            {
                                er=INF;
                                break;
                            }
                        else
                        {
                            er++;
                            lerr=k;
                        }
                    }
                }
                dp[i]=min(dp[i],dp[i-sz[j]]+er);
            }
        }
		printf("Case #%d: %d\n",t,dp[n]);
	}
	return 0;
}

