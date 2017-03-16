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
int t,k,l,s;
string key,word;
double ans;
ll counter,total,maxb;
int hk[30];
double pk[30];
void solve(string cur,int ii=0)
{
	ll temp=counter;
	if(ii==s)
	{
		fora(i,0,s-l+1)
		{
			int k=i;
			fora(j,0,l)
				if(cur[k++]!=word[j])
				{
					counter--;
					break;
				}
			counter++;
		}
		maxb=max(maxb,counter-temp);
		total++;
		return;
	}
	fora(i,0,k)
	{
		cur.pb(key[i]);
		solve(cur,ii+1);
		cur.pop_back();
	}
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("sb3.in","r",stdin);
   //freopen("outB.txt","w",stdout);
   #endif
   cin>>t;
   fora(ii,0,t)
   {
   	cin>>k>>l>>s;
   	cin>>key;
   	ms(hk,0);
   	fora(i,0,key.size())
   		hk[key[i]-'A']++;
   	fora(i,0,26)
   		pk[i]=hk[i]/(double)k;
   	cin>>word;
   	total=0;
   	counter=0;
   	maxb=0;
   	string str="";
   	solve(str,0);
   	ans=((maxb*total)-counter)/(double)total;
   	//cout<<counter<<" "<<total<<" ";
   	printf("Case #%d: %0.7f\n",ii+1,ans);
   	//cout<<"Case #"<<ii+1<<": "<<ans<<"\n";
   }
   return 0;
}