#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ll long long
#define ull long long
#define inf 1000000007
#define mod 1000000007
#define DBG(x) cerr<<#x<<"="<<x<<"\n";
#define FOREACH(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define N 1000005

int a[1005],n,ans;
int cal(int t)
{
    int i,j,m=0;
    for(i=0;i<n;i++){
        if(a[i]>t){
            m+=(a[i]-1)/t;
        }
    }
    return m+t;
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,m,ca=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        ans=a[n-1];
        for(i=1;i<a[n-1];i++)ans=min(ans,cal(i));
        printf("Case #%d: %d\n",++ca,ans);
    }
    return 0;
}