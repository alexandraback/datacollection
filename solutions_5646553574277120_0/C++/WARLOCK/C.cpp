#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <algorithm>
#include <typeinfo>

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define setBit(n,i) (n|=(1<<i))
#define clearBit(n,i) (n&=(~(1<<i)))
#define checkBit(n,i) (n&(1<<i))
#define lsBit(n) ((n)&(-n))

#define fora(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(__typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define ms(a,b) memset(a,b,sizeof(a))
#define all(a) (a).begin(),(a).end()

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long int ll;

int t,c,d,v;
int arr[40];
int dp[40];
void populate(int curSum=0,int i=0)
{
	if(curSum>=40)	return;
	dp[curSum]=1;
	if(i==d)	return;
	populate(curSum+arr[i],i+1);
	populate(curSum,i+1);
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("sc1.in","r",stdin);
   freopen("outC.txt","w",stdout);
   #endif
   
   cin>>t;
   
   fora(i,0,t)
   {
   	cin>>c>>d>>v;
   	ms(dp,0);
   	dp[0]=1;
   	fora(j,0,d)	cin>>arr[j];
   	populate();
   	int ans=0;
   	bool flag=true;
   	while(true)
   	{
   		flag=true;
   		fora(j,1,v+1)
   			if(dp[j]==0)
   			{
   				ans++;
   				arr[d++]=j;
   				flag=false;
   				break;
   			}
   		if(flag)	break;
   		ms(dp,0);
   		dp[0]=1;
   		populate();
   	}
   	cout<<"Case #"<<i+1<<": "<<ans<<"\n";
   }
   return 0;
}