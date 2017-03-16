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
# define MAX_PRIME 0
# define SEGMENT_MAX 0

using namespace std;

bool compare( const ll &a, const ll &b ){
	return a < b ;
}

int main(){
	freopen("read.txt", "r", stdin);
	freopen("write.txt", "w", stdout);
	ll t;
	sf(t);
	REP(kr, t){
		printf("Case #%lld: ",kr);
		ll r, c, w;
		sf(r); sf(c); sf(w);
		ll sum = 0;
		ll x = c/w;
		sum = (r-1)*x;
		if( c % w == 0){
			sum = sum + w + (c/w - 1);
		}	
		else{
			sum = sum + w + c/w;
		}
		prn(sum);
	}
	return 0;
}