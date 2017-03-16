#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#define MAXN 1005
//typedef  long long i64;
using namespace std;
struct node
{
    long long num;
    int type;
}one[105],two[105];
long long dp[105][105];
long long maxx(long long a,long long  b)
{
    return a>b?a:b;
}
long long minn(long  long a,long long b)
{
    return a<b?a:b;
}
long long sumone[105][105],sumtwo[105][105];
int main()
{
    int t;
    int n,m,p,q;
    int i,j;
  //  cout<<maxx(10000000000000000.0,30000000000000000.0)<<endl;
    
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    int k;
    int ttt;
    int casenum;
    for(casenum=1;casenum<=t;casenum++)
    {
        scanf("%d%d",&n,&m);
        memset(sumone[0],0,sizeof(sumone[0]));
        memset(sumtwo[0],0,sizeof(sumtwo[0]));
        
        for(i=1;i<=n;i++)
        {
          //  scanf("%lld%d",&one[i].num,&one[i].type);
          cin>>one[i].num>>one[i].type;
            for(j=0;j<=100;j++)
                sumone[i][j]=sumone[i-1][j];
            sumone[i][one[i].type]+=one[i].num;
          //  cout<<"***"<<i<<' '<<one[i].type<<one[i].num<<"    "<<sumone[i][one[i].type]<<endl;
        }
        for(i=1;i<=m;i++)
        {
           // scanf("%lld%d",&two[i].num,&two[i].type);
           cin>>two[i].num>>two[i].type;
            for(j=0;j<=100;j++)
                sumtwo[i][j]=sumtwo[i-1][j];
            sumtwo[i][two[i].type]+=two[i].num;
           //   cout<<"***"<<i<<' '<<two[i].type<<"    "<<sumtwo[i][two[i].type]<<endl;
        
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(one[i].type==two[j].type)
                {
                    for(p=0;p<i;p++)
                        for(q=0;q<j;q++)
                        {
                            dp[i][j]=maxx(dp[i][j],dp[p][q]+minn(sumone[i][one[i].type]-sumone[p][one[i].type],sumtwo[j][one[i].type]-sumtwo[q][one[i].type]));
                   //      cout<<"&&&"<<i<<' '<<j<<' '<<dp[i][j]<<' '<<dp[p][q]<<' '<<sumone[i][one[i].type]-sumone[p][one[i].type]<<' '<<sumtwo[j][one[i].type]-sumtwo[q][one[i].type]<<endl;
						}
                }else
                {
                    dp[i][j]=maxx(dp[i][j],dp[i-1][j]);
                    dp[i][j]=maxx(dp[i][j],dp[i][j-1]);
                 //   cout<<"***"<<i<<' '<<j<<' '<<dp[i][j]<<endl;
					
                }
                
            }
        }
        printf("Case #%d: ",casenum);
        cout<<dp[n][m]<<endl;
            
    }
    
    
    return 0;
}
