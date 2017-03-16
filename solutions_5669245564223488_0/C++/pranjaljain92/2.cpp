#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define MAX(a,b)				((a)>(b)?(a):(b))
#define MIN(a,b)				((a)<(b)?(a):(b))
#define ABS(x)					((x)<0?-(x):(x))

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<TRI> VT;

struct node
{
    char start,end;
    int hash[26];
};

int n,countt;

int isvalid(char str[][200],struct node pre[],int ind)
{
    //printf("%s %d\n",str[ind],ind);
    int i,n;
    n=strlen(str[ind]);
    pre[ind].start=str[ind][0];
    pre[ind].end=str[ind][n-1];

    for(i=0;i<26;i++)
    pre[ind].hash[i]=0;

    for(i=0;i<n;i++)
    {
        if(pre[ind].hash[str[ind][i]-'a']==0)
        pre[ind].hash[str[ind][i]-'a']=1;
        else
        {
            if(str[ind][i]!=str[ind][i-1])
            return(0);
        }
    }
    //for(i=0;i<6;i++)
    //printf("%d ",pre[ind].hash[i]);
    //printf("\n");
    return(1);
}

int compute(char str[][200])
{
    int i,j;
    countt=0;
    struct node pre[n];

    for(i=0;i<n;i++)
    {
        if(isvalid(str,pre,i)==0)
        return(0);
    }

    int arr[n];
    for(i=0;i<n;i++)
    arr[i]=i;

    int hashh[26],flag;
    for(i=0;i<26;i++)
    hashh[i]=0;

    flag=0;j=0;
    int flag2;
    char last;
    do{
        flag=0;
        flag2=1;
        for(j=0;j<n;j++)
        {
            if(flag==0)
            {
                flag=1;
                for(i=0;i<26;i++)
                hashh[i]=pre[arr[j]].hash[i];

                last=pre[arr[j]].end;
            }
            else
            {
                for(i=0;i<26;i++)
                {
                    if(hashh[i]==1 && pre[arr[j]].hash[i]==1)
                    {
                        if(last!=pre[arr[j]].start)
                        flag2=0;
                        else
                        {
                            if(last!=(i+'a'))
                            flag2=0;
                        }
                    }
                    else if(hashh[i]==0 && pre[arr[j]].hash[i]==1)
                    hashh[i]=1;

                    if(flag2==0)
                    break;
                }
                last=pre[arr[j]].end;
            }
            if(flag2==0)
            break;
        }
        if(j==n)
        countt++;
    }while(next_permutation(arr,arr+n));
    return(countt);
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output2.txt","w",stdout);
    int i,t,x,ans;
    s(t);
    for(x=1;x<=t;x++)
    {
        s(n);
        char str[n+1][200];
        for(i=0;i<n;i++)
        scanf("%s",str[i]);

        ans=compute(str);
        printf("Case #%d: %d\n",x,ans);
    }
    return(0);
}

