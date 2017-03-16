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

ll A[2000],bff[2000],B[2000],C[2000];

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll tcc,n,u,fl,ans=-1e9;
	sll(tcc);

	for(int tc=1;tc<=tcc;tc++){
		ans=-1e9;
		cout<<"Case #"<<tc<<": ";
		cin>>n;
		rep(i,0,n){
			sll(bff[i]);
			bff[i]--;
		}
		for(int i=1;i<(1<<n);i++){
			u=0;
			rep(j,0,n){
				if(i&(1<<j)){
					A[u++]=j;
				}
			}
			rep(j,0,u){
				B[j]=j;
			}
			do{
				fl=0;
				rep(j,0,u){
					C[j]=A[B[j]];
//					cout<<C[j]<<" ";
				}
//				cout<<endl;
				rep(j,0,u){
					if(bff[C[j]]==C[(j-1+u)%u] or bff[C[j]]==C[(j+1)%u]){
					
					}
					else{
						fl=1;
					}
				}
				if(!fl)
					ans=max(ans,u);
			}while(next_permutation(B,B+u));
		}
		cout<<ans<<endl;
	}

	return 0;
}


