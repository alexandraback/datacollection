#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

struct Quat{
	char c;
	int sgn;

	Quat(char _c, int _sgn){
		c=_c;
		sgn=_sgn;
	}

	Quat operator*(Quat q){
		if(c == q.c && c != '1')
			return Quat('1',(-1)*sgn*q.sgn);
		if(c == '1' && q.c == '1')
			return Quat('1',sgn*q.sgn);
		if(c == '1')
			return Quat(q.c, sgn*q.sgn);
		if(c == 'i' && q.c == 'j')
			return Quat('k',sgn*q.sgn);
		if(c == 'j' && q.c == 'k')
			return Quat('i',sgn*q.sgn);
		if(c == 'k' && q.c == 'i')
			return Quat('j',sgn*q.sgn);
		Quat q2=q*(*this);
		q2.sgn *= -1;
		return q2;
		
		
	}
};

char s[200000];

void solve(){
	long long L,X;
	scanf("%lld%lld", &L, &X);
	scanf("%s", s);
	if(X > 12)
		X -= ((X-12)/4)*4;
	int len=strlen(s);
	rep(i,len,200000)
		s[i]=s[i-len];
	int pos=0;
	rep(c,'i','l'){
		Quat q('1',1);
		for(; pos < X*len; ++pos){
			//printf("s[%d] = %c\n", pos, s[pos]);
			q=q*Quat(s[pos],1);
			if(q.c == c && q.sgn == 1 && c != 'k'){
				++pos;
				break;
			}
		}
		if(q.c != c || q.sgn != 1){
			puts("NO");
			return;
		}

	}
	puts("YES");
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; ++t){
		printf("Case #%d: ", t);
		solve();
	}
}
