#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 1
#define vec vector<long long>
#define mod 100000
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}


void impr(vec C){
   printf("%lld",C.back());
   for(int i=C.size()-2;i>=0;i--) printf("%05lld",C[i]);
   printf("\n");
}

vec operator*(vec a,vec b){
   int m=a.size(),n=b.size();
   vec c(m+n); 
   ll s=0;
   f(i,0,m+n){
      int ini=max(0,i-n+1);
      int fin=min(i+1,m);
      f(j,ini,fin)s+=a[j]*b[i-j];
      int k=i;
      while(s){
         c[k]+=s%mod; s=s/mod;
         if(c[k]>=mod){ c[k]-=mod; c[k+1]++;}
         k++;
      }
   }
   if(c.back()==0)c.pop_back();
   return c;
}
vec modpow(vec a,int n){
	vec t = a; vec res(1,1);
	while(n){
		if( n&1 ) res = res*t;
		t = t*t;
		n>>=1;
	}
	return res;
}
vec operator+ (vec a,vec b){
   int m=a.size(),n=b.size();
   if(m<n) swap(a,b), swap(m,n);
   vec c(m+1); 
   f(i,0,m){
      ll s=a[i];
      if(i<n)s+=b[i];
      if(c[i]+s>=mod) c[i+1]++, s-=mod;
      c[i]+=s;
   }
   if(c.back()==0)c.pop_back();
   return c;
}
vec operator- (vec a,vec b){
   int m=a.size(), n=b.size();
   vec c(m);
   f(i,0,m){
      ll r=a[i];
      if(i<n) r-=b[i];
      if(c[i]+r<0) c[i+1]--, r+=mod;
      c[i]+=r;
   }

   while(c.size()>1 && c.back()==0)c.pop_back();
   //cout<<"y ahora "; impr(c);
   return c;
}
int comp(vec A,vec B){
   int m=A.size(), n=B.size();
   if(m<n) return -1;
   if(m>n) return 1;
   fd(i,m-1,0){
      if(A[i]<B[i])return -1;
      if(A[i]>B[i])return 1;
   }
   return 0;
}
bool orden(vec a, vec b) { return comp(a,b) < 0; }

vec tobig(string s) {
	vec res(1,0);
	f(i,0,s.size()) res = res*vec(1,10) + vec(1,s[i]-'0');
	return res;
}

vec ten[55];

int main(){
	vector< vec > L;
	f(i,1,4) L.pb( vec(1,i) );
	ten[0] = vec(1,1);
	f(i,1,55) ten[i] = ten[i-1]*vec(1,10);

	//comienza con 2
	f(k,0,25) L.pb( (ten[2*k+1] + ten[0]) * vec(1,2) );
	f(k,1,25) L.pb( (ten[2*k] + ten[0]) * vec(1,2) );
	f(k,1,25) L.pb( (ten[2*k] + ten[0]) * vec(1,2) + ten[k]);

	//comienza con 1
	//numero de cifras:
	//par
	f(k,0,25) {
		vec tot = ten[2*k+1] + ten[0];
		L.pb(tot);
		f(j1,1,k+1) {
			tot = tot + ten[j1] + ten[2*k+1-j1];
			L.pb(tot);
			f(j2,j1+1,k+1) {
				tot = tot + ten[j2] + ten[2*k+1-j2];
				L.pb(tot);
				f(j3,j2+1,k+1) {
					tot = tot + ten[j3] + ten[2*k+1-j3];
					L.pb(tot);
					tot = tot - ten[j3] - ten[2*k+1-j3];
				}
				tot = tot - ten[j2] - ten[2*k+1-j2];
			}
			tot = tot - ten[j1] - ten[2*k+1-j1];
		}
	}
	//impar
	int cota = 3;
	f(k,1,25) {
		vec tot = ten[2*k] + ten[0];
		f(j,0,cota) L.pb(tot + ten[k]*vec(1,j));
		f(j1,1,k) {
			tot = tot + ten[j1] + ten[2*k-j1];
			f(j,0,cota) L.pb(tot + ten[k]*vec(1,j));
			cota--;

			f(j2,j1+1,k) {
				tot = tot + ten[j2] + ten[2*k-j2];
				f(j,0,cota) L.pb(tot + ten[k]*vec(1,j));
				f(j3,j2+1,k) {
					tot = tot + ten[j3] + ten[2*k-j3];
					f(j,0,cota) L.pb(tot + ten[k]*vec(1,j));
					tot = tot - ten[j3] - ten[2*k-j3];
				}
				tot = tot - ten[j2] - ten[2*k-j2];
			}
			cota++;
			tot = tot - ten[j1] - ten[2*k-j1];
		}
	}

	sort(all(L), orden);
	f(i,0,L.size()) L[i] = L[i] * L[i];

	int tc;
	cin >> tc;
	int caso = 0;
	while (tc--) {
		string A,B;
		cin >> A >> B;
		vec a = tobig(A), b = tobig(B);
		int res = upper_bound(all(L), b, orden) - upper_bound(all(L), a-vec(1,1), orden);
		printf("Case #%d: %d\n", ++caso, res);
	}
}

