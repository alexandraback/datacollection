#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<deque>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<bitset>
#include<stack>
#include<queue>
#include<sstream>

#define MODM 1000000007
#define MAXM 2147483647
#define MAXML 9223372036854775807LL
#define Pi 3.14159265358979323846264338327950288419716939937510582
#define EPS 1e-10

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define L(x) x.length()
#define B(x) x.begin()
#define E(x) x.end()
#define F(x) x.front()
#define SZ(x) x.size()
#define CLR(x) x.clear()
#define SORT(x) sort(x.begin(),x.end())
#define REV(x) reverse(x.begin(),x.end())
#define FOR(i,x,y) for(int i=x;i<y;i++)
#define S(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define SD(x) scanf("%lf",&x)
#define SC(x) scanf("%1s",&x)
#define SS(x) scanf("%s",x)
#define DUM() scanf("%c",&dum)
#define READ(x) freopen(x,"r",stdin)
#define WRITE(x) freopen(x,"w",stdout)
#define FILL(x,y) memset(x,y,sizeof(x))
#define IT iterator
#define CASE printf("Case #%d: ",Case++)

using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
typedef long double ld;
typedef pair<int,int> P;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef vector< P > VP;
typedef vector< VP > VVP;
typedef vector<string> VS;
typedef vector< VS> VVS;
typedef map<int,int> MAP;

lli gcd(lli a,lli b){if(a==0)return(b);else return(gcd(b%a,a));}
lli fastpow(lli a,lli n,lli temp){if(n==0) return(1);if(n==1)return((a*temp)%MODM); if(n&1)temp=(temp*a)%MODM;return(fastpow((a*a)%MODM,n/2,temp));}
char dum;
int Case=1;

bool pos(string s){
	int c[26]={0};
	c[s[0]-'a']=1;
	for(int i=1;i<L(s);i++){
		if(s[i]!=s[i-1]){
			c[s[i]-'a']++;
			if(c[s[i]-'a']>1)return 0;
		}
	}
	return 1;
}
string transforms(string s){
	string ans = "";
	ans = ans+s[0];
	for(int i=1;i<L(s);i++){
		if(s[i]!=s[i-1])
			ans=ans+s[i];
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	READ("read.txt");
	WRITE("output.txt");
	#endif
	int t;
	cin>>t;
	while(t--){
		CASE;
		int n;cin>>n;
		VS v;
		VVI ind;
		string s;
		bool notpos=false;
		for(int i=0;i<n;i++){
			cin>>s;
			if(pos(s)){
				s = transforms(s);
				v.pb(s);
			}
			else
				notpos=true;
		}
		if(notpos){
			printf("0\n");
			continue;
		}
		
		
		VI x;
		for(int i=0;i<n;i++){
			x.pb(i);
		}
		
		
		lli ans=0;
		int freq[26];
		do{
			FILL(freq,0);
			string check="";
			for(int i=0;i<n;i++){
				check+=v[x[i]];
			}
			if(pos(check)) ans++;
		}while(next_permutation(B(x),E(x)));
		printf("%lld\n",ans%MODM);
	}
	return 0;
}

