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

vpll v;
ll arr[70][70];
int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll tccc;
	sll(tccc);
	for(int tcc=1;tcc<=tccc;tcc++){
		cout<<"Case #"<<tcc<<": ";
		v.clear();
//		trace(sz(v),"yyy");
		ll b,m;
		cin>>b>>m;
		ll one=1;
		if(m>(one<<b-2))
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		ll p=0;
		while((one<<p)<=m){
			p++;
		}
		p--;
		rep(i,1,p+2){
			rep(j,i+1,p+2){
				v.pb(mp(i,j));
			}
			v.pb(mp(i,b));
		}
		m-=(one<<p);
		v.pb(mp(b-1,b));
		ll cnt=2;
		while(m){
			if(m%2==1){
				v.pb(mp(cnt,b-1));
			}
			m>>=1;
			cnt++;
		}
		/*
		rep(i,1,b){
			v.pb(mp(i,b));
		}
		m--;
		ll cnt=2;
		ll p=1;
		ll fl=0;
		while(m){
//			trace(p,cnt);
			if(cnt>=b){
				cout<<"IMPOSSIBLE"<<endl;
				fl=1;
				break;
			}
			v.pb(mp(p,cnt));
			m--;
			p++;
			if(p==cnt){
				p=1;
				cnt++;
			}
		}
		if(fl)
			continue;*/
		set(arr,0);
		for(auto l:v){
			arr[l.F][l.S]=1;
		}
		cout<<"POSSIBLE"<<endl;
//		trace(sz(v));
		rep(i,1,b+1){
			rep(j,1,b+1){
				cout<<arr[i][j];
			}
			cout<<endl;
		}
	}

	return 0;
}


