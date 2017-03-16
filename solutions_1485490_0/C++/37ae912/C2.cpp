#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long LL;

// data define

const int maxn=1000+5;

int n,m,cn;
LL a[110],b[110],ca[110];
int A[110],cA[110];
int B[110];

LL dp[110][110];
LL dp2[110][110][110];

LL sum[110][110][110];
bool vis[110];

void Init()
{
    memset(vis,0,sizeof vis);
    memset(sum,0,sizeof sum);
    
    for(int i=1;i<=n;++i){
        int type = A[i];
        if(vis[type])continue;
        
        for(int j=1;j<=m;++j){
            LL res=0;
            for(int k=j;k<=m;++k){
                if(type==B[k]) res+=b[k];
                sum[type][j][k]=res;
            }    
        }
        
        vis[type]=true;    
    }
        
}



LL solve()
{
    /*
        puts("solve:");
        for(int i=1;i<=n;++i)
            printf("%I64d %d, ",a[i],A[i]);
        puts("");
    */
    
        memset(dp,0,sizeof dp);
        memset(dp2,0,sizeof dp2);
        
        Init();
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
            
            for(int k=j;k<=m;++k){
                    
                
                    dp2[i][j][k] =  dp[i-1][j-1] + min(a[i], sum[ A[i] ][ j ][k]);
                
                    if(dp[i][k]<dp2[i][j][k]) dp[i][k]=dp2[i][j][k];
                    
                    //printf("i=%d j=%d k=%d dp2=%I64d dp=%I64d\n",i,j,k,dp2[i][j][k], dp[i][k]);
                }
                /*
                dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
                if( A[i]==B[j] ){
                    LL t = dp[i-1][j-1]+min(a[i],b[j]);
                    //printf("match: i=%d j=%d pre-dp=%I64d cur-dp=%I64d\n",i,j,dp[i-1][j-1],t);
                    if(t>dp[i][j]) dp[i][j]=t;
                }    
                */
                //cout<<"i="<<i<<", j="<<j<<", dp="<<dp[i][j]<<endl;
            }
        }
 
        return dp[n][m];
}

void Merge(int s,int t, int type)
{
    n=0;
    for(int i=1; i<s;++i){
        ++n;
        a[n]=ca[i];
        A[n]=cA[i];    
    }
    LL res=0;
    for(int i=s;i<=t;++i){
        if(cA[i]==type){
            res+=ca[i];    
        }    
    }
    ++n;
    a[n]=res;
    A[n]=type;

    for(int i=t+1; i<=cn;++i){
        ++n;
        a[n]=ca[i];
        A[n]=cA[i];    
    }
            
}


int main()
{

//	freopen("a.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);

	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
       scanf("%d%d",&n,&m);
        
        for(int i=1;i<=n;++i){
            scanf("%I64d%d",a+i,A+i);
            ca[i]=a[i];
            cA[i]=A[i];
        }
        for(int i=1;i<=m;++i)scanf("%I64d%d",b+i,B+i);
        
        cn = n;
        
        LL res=solve();
        
        for(int k=1;k<=cn;++k){
            int type = cA[k];
            for(int i=1;i<cn;++i){
                for(int j=i+1;j<=cn;++j){
                        Merge(i,j,type);
                        //printf("merge: i=%d j=%d type=%d\n",i,j,type);
                        LL t = solve();
                        if(res<t)res=t;
                }    
            }
        }
        
        //merge 1-2
        
        //merge 2-3
        //merge 1-3

		printf("Case #%d: ",case_id);
        cout<<res<<endl;
               
    }
	return 0;
}
