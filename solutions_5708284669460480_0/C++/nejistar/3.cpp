# include <bits/stdc++.h>
# define ll long long
# define par pair < ll, ll >
# define first fs
# define second se
# define mp make_pair
# define pb push_back
# define rep(i, n) for( ll (i) = 0; (i) < (n); (i)++)
# define REP(i, n) for( ll (i) = 1; (i) <= (n); (i)++)
# define wl(i) while((i)--)
# define vec vector < ll >
# define ma map < ll, ll >
# define sf(i) scanf("%lld",&(i))
# define pr(i) printf("%lld ",(i))
# define prn(i) printf("%lld\n",(i))
# define cpr(i) cout<<(i)<<" "
# define cprn(i) cout<<(i)<<endl
# define csf(i) cin>>(i)
# define srt(v) sort( v.begin(), v.end() )
# define srtc(v, x) sort( v.begin(), v.end(), x)
# define srtr(v) sort( v.begin(), v.end(), greater< ll >())
# define mod 1000000007
# define maxi_PRIME 0
# define SEGMENT_maxi 0

using namespace std;

bool compare( const ll &a, const ll &b ){
	return a < b ;
}

ll c, total, maxi;
string ar;
char sr[100];
void recurse( ll s, string target, ll cr){
	if( cr == 0 ){
		ll tm = 0;
		for( ll i = 0; i < s; i++ ){
			ll j;
			for( j = 0; (j < target.size() && (i + j ) < s); j++){
				if(sr[ i + j ] != target[j] )
					break;
			}
			if( j == target.size()){
				c++;
				tm++;
			}
		}
		if(tm > maxi)
			maxi = tm;
		total++;
		return;
	}
	for( ll i = 0; i < ar.size(); i++ ){
		sr[s] = ar[i];
		recurse(s + 1, target, cr - 1);
	}
	return;
}
int main(){
	freopen("read.txt", "r", stdin);
	freopen("write.txt", "w", stdout);
	ll t;
	sf(t);
	REP(kr, t){
		printf("Case #%lld: ",kr);
		c = 0; total = 0;
		ll k, l, s; maxi = 0;
		sf(k); sf(l); sf(s);
		string s2;
		cin>>ar>>s2;
		recurse( 0, s2, s);
		printf("%lf\n", (maxi - c/(total + 0.0)));
	}
	return 0;
}