//Shubham Vijayvargiya

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define sz(a) (int)(a.size())
#define set(a,b) memset(a,b,sizeof(a))
#define let(x,a) __typeof(a) x(a)
#define rep(i, begin, end) for (ll i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(v) (v).begin(),(v).end()
#define sll(x) { scanf("%lld",&x); }
#define si(x) { scanf("%d",&x); }
#define slf(x) { scanf("%lf",&x); }
#define pll(x) { printf("%lld\n",x); }
#define pi(x) { printf("%d\n",x); }
#define tcases() long long testcases; cin>>testcases ; while(testcases--)

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " = " << arg1<<" | ";__f(comma+1, args...);
}

#else
#define trace(...)
#endif

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<long long,long long> pll;
typedef vector<long long> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;

const ll mod=1000000007;
//-----------------------------------------------------------------------------------------------------------------------------------------------//


int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll tc;
	string s;
	sll(tc);
	for(int i=1;i<=tc;i++){
		cout<<"Case #"<<i<<": ";
		cin>>s;
		ll n=sz(s);
		ll z=0,o=0,g=0,t=0,v=0,e=0,f=0,u=0,x=0,w=0;
		rep(i,0,n){
			if(s[i]=='Z')
				z++;
			if(s[i]=='O')
				o++;
			if(s[i]=='T')
				t++;
			if(s[i]=='E')
				e++;
			if(s[i]=='V')
				v++;
			if(s[i]=='F')
				f++;
			if(s[i]=='G')
				g++;
			if(s[i]=='U')
				u++;
			if(s[i]=='X')
				x++;
			if(s[i]=='W')
				w++;
		}
		rep(i,0,z)
			cout<<0;
		f=f-u;
		v=v-f;
		t=t-g-w;
		o=o-z-w-u;
		e=e-z-o-t-t-f-v-v-g;
		rep(i,0,o)
			cout<<1;
		rep(i,0,w)
			cout<<2;
		rep(i,0,t)
			cout<<3;
		rep(i,0,u)
			cout<<4;
		rep(i,0,f)
			cout<<5;
		rep(i,0,x)
			cout<<6;
		rep(i,0,v)
			cout<<7;
		rep(i,0,g)
			cout<<8;
		rep(i,0,e)
			cout<<9;
		cout<<endl;
	}

	return 0;
}


