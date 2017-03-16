#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<utility>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ll long long
#define MAX_SIZE 200005
#define MOD 1000000007
#define S(x) scanf("%d",&x)
#define SL(x) cin>>x
#define SC(x) scanf("%c",&x)
#define SS(x) scanf("%s",x)
#define SZ(x) x.size()
#define IT iterator
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>
#define VVI vector< VI >
#define VVL vector< VL >
#define VVP vector< PI >
#define READ() freopen("/Users/home/Desktop/input.txt","r",stdin)
#define WRITE() freopen("/Users/home/Desktop/output.txt","w",stdout)
#define dump() SC(dump_char)
int dump_char;

int main()
{
    READ();
    WRITE();
    ll i,j,k,temp,prev,n,ans,cnt,t;
    string str;
    cin>>t;
    
    for(k=1;k<=t;k++)
    {
        cin>>str>>n;
        for(i=0;i<SZ(str);i++)
        {
            if(str[i]=='a' || str[i]=='i' || str[i]=='e' || str[i]=='o' || str[i]=='u')
            {
                str[i]='v';
            }
            else
            {
                str[i]='c';
            }
        }
        ans=cnt=temp=0;
        prev=-1;
        
        for(i=0;i<SZ(str);i++)
        {
            if(str[i]=='c')
            {
                cnt++;
                ans+=temp;
                if(cnt==n)
                {
                    //ans++;
                    cnt=(n-1);
                    j=i-(n-1);
                    ans+=(j-prev);
                    temp+=(j-prev);
                    prev=j;
                }
            }
            else
            {
                cnt=0;
                ans+=temp;
            }
        }
        printf("Case #%lld: %lld\n",k,ans);
    }
}