#include<bits/stdc++.h>
#include<string>
using namespace std;
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
#define traverse(container, it) \
  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define         mp(x, y) make_pair(x, y)
#define         REV(s, e) reverse(s, e)
#define         CPY(d, s) memcpy(d, s, sizeof(s))
#define         READ(f) freopen(f, "r", stdin)
#define         WRITE(f) freopen(f, "w", stdout)
#define         ALL(c) c.begin(), c.end()
#define         SIZE(c) (int)c.size()
#define         pb(x) push_back(x)
//#define       map<char,int>::iterator it;
#define         ff first
#define         ss second
#define         ll long long
#define         ld long double
#define         pii pair< int, int >
#define         psi pair< string, int >
#define         p(n) printf("%d\n",n)
#define         p64(n) printf("%lld\n",n)
#define         s(n) scanf("%d",&n)
#define         s64(n) scanf("%I64d",&n)
#define         rep(i,a,b) for(i=a;i<b;i++)
#define         MOD (1000000007LL)

/////////////////////////////////////////////////

ll dp[1234567];
ll n;




ll reverse(ll n)
{
   ll b,c=0;
 
   while(n>0)
   {
   	c=c*10+n%10;
       n/=10;
   }
 
   return c;
}



void solve(){
	int i =0 ;
	//memset(dp , 0 ,sizeof(dp));
	dp[0] = 0;
	rep(i,1,11){
		dp[i] = dp[i-1]+1;

	}

	


	for(int i=11;i<=1000000;i++)
   {
   		ll x=reverse(i);
   		if(x!=i && dp[x]!=-1 && i%10!=0)
   		{
			dp[i]=min(dp[i-1]+1,dp[x]+1);
   		}
   		else{
   			dp[i]=dp[i-1]+1;
   		}
   }

	 // rep(i,1,1000){
	 // 		cout<<" i = "<<i<<" "<<dp[i]<<endl;
	 // 	}

}

ll steps_func(ll l){
	if(l==0)	return 0;
	if(l==1)	return 0;
	if(l==2)	return 10;

	ll ans = 10;
	ans += (l-2)*9;
	int i;
	rep(i,1,l-2){
		ans = ans +pow(10,i);
	}
	return ans;

}

ll dig_func(ll temp,ll len,ll M){
	return temp-M*(pow(10,len-1));
}

ll solve2(){
	ll len = log10(n)+1;
	ll steps = steps_func(len);
	ll M = n/pow(10,len-1);

	ll dig = dig_func(n,len,M); 

	if(n<=10){
		return n;
	}
	else if(M==1)	{
		return steps+dig;
	}
	else {
		return steps+M+dig;
	}

}



int main(){
	std::ios::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	memset(dp , -1,sizeof(dp));
	int t;
	cin>>t;
	int k = 1;
	//recur(1);
	solve();
	
	while(t--){
		cin>>n;
		if(n<=1000000){
			cout<<"Case #"<<k++<<":"<<" "<<dp[n]<<endl;;
		}
		else
			cout<<"Case #"<<k++<<":"<<" "<<solve2()<<endl;; 




	}

return 0;
}