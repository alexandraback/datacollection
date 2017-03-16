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
	string a,b,c,j;
	ll e;
	sll(tc);

	for(int i=1;i<=tc;i++){
		cout<<"Case #"<<i<<": ";
		cin>>a>>b;
		ll n=sz(a);
		c=a;
		j=b;
		e=0;
		bool inc1=false,inc2=false;
		ll increment1=-5,increment2=-5;
		rep(i,0,n){
			if(e==0){
				if(a[i]=='?' and b[i]!='?'){
					c[i]=j[i];
					if(c[i]-'0'<9){
						increment1=i;
						inc1=true;
					}
					else if(inc1==true and c[i]-'0'==9){
						increment1=i;
					}
					inc2=false;
				}
				else if(a[i]!='?' and b[i]=='?'){
					j[i]=c[i];
					if(j[i]-'0'<9){
						increment2=i;
						inc2=true;
					}
					else if(inc2==true and j[i]-'0'==9){
						increment2=i;
					}
					inc1=false;
				}
				else if(a[i]=='?' and b[i]=='?'){
					inc1=true;
					inc2=true;
					c[i]=j[i]='0';
					increment1=increment2=i;
				}
				else{
					if((a[i]-'0')>(b[i]-'0')){
						ll fl=0;
						if((a[i]-b[i])>5){
							if(inc2==true and increment2==i-1){
//								trace("yyy");
								ll p=i-1;
								while(j[p]-'0'==9){
									j[p]='0';
									p--;
								}
								j[p]=j[p]+1;
								e=2;
							}
							else if(i-1>=0 and a[i-1]=='?' and c[i-1]!='0'){
								c[i-1]=c[i-1]-1;
								e=2;
							}
							else
								e=1;
						}
						else
							e=1;
					}
					else if((a[i]-'0')<(b[i]-'0')){
						if((b[i]-a[i])>5){
							if(inc1== true and increment1==i-1){
								ll p=i-1;
								while(c[p]-'0'==9){
									c[p]='0';
									p--;
								}
								c[p]=c[p]+1;
								e=1;
							}
							else if(i-1>=0 and b[i-1]=='?' and j[i-1]!='0'){
								j[i-1]=j[i-1]-1;
								e=1;
							}
							else
								e=2;
						}
						else
							e=2;
					}
					inc1=inc2=false;
				}
			}
			else if(e==1){
				if(a[i]=='?' and b[i]!='?'){
					c[i]='0';
				}
				else if(a[i]!='?' and b[i]=='?'){
					j[i]='9';
				}
				else if(a[i]=='?' and b[i]=='?'){
					c[i]='0';
					j[i]='9';
				}
				else{
				}
			}
			else{
				if(a[i]=='?' and b[i]!='?'){
					c[i]='9';
				}
				else if(a[i]!='?' and b[i]=='?'){
					j[i]='0';
				}
				else if(a[i]=='?' and b[i]=='?'){
					c[i]='9';
					j[i]='0';
				}
				else{
				}
			}
		}
		cout<<c<<" "<<j<<endl;
	}

	return 0;
}


