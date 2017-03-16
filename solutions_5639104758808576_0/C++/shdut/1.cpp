#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
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
#define N 1000005

char s[1005];
int main()
{
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,n,m,ca=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,s);
        m=0;int ans=0;
        for(i=0;i<=n;i++){
            j=s[i]-'0';
            if(m<i)ans+=i-m,m=i;
            m+=j;
        }
        printf("Case #%d: %d\n",++ca,ans);
    }
    return 0;
}