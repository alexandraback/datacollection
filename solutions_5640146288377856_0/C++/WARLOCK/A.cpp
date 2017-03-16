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

int main()
{
   #ifndef ONLINE_JUDGE
   
	freopen("sa2.in","r",stdin);
   freopen("outA.txt","w",stdout);
   #endif
   int t,r,c,w;
   int ans;
   cin>>t;
   fora(i,0,t)
   {
   	cin>>r>>c>>w;
   	ans=r*(c/w)+(w-1);
      if(c%w!=0)  ans++;
   	cout<<"Case #"<<i+1<<": "<<ans<<"\n";
   }
   return 0;
}