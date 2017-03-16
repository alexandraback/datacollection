#include<iostream>
#include<cstdio>
#include<time.h>
#include<algorithm>
#include<cstring>
using namespace std;

/*
int Mod = 1000000007;

	static void Add( int n, int *a, int *b ){ // a = a+b
		for(int i=0; i<n; i++) a[i] = (a[i]+b[i])%Mod;
	}
	static void Mul( int n, int *A, int *B, int *tmp ){ // a = a*b
		memset( tmp, 0, sizeof(int)*n*n );
		for(int i=0, *a=A, *t=tmp; i<n; i++, a+=n, t+=n){
			for(int j=0, *b=B; j<n; j++, b+=n){
				if( a[j] == 0 ) continue;
				for(int k=0; k<n; k++) t[k] = (t[k]+(long long)a[j]*b[k])%Mod;
			}
		}
		memcpy( A, tmp, sizeof(int)*n*n );
	}
	static void Power( int n, int *a, int p, int *t, int *tmp ){ // t = a^p
		if( p == 1 ) memcpy( t, a, sizeof(int)*n*n );
		else{
			Power( n, a, p>>1, t, tmp );
			Mul( n, t, t, tmp );
			if( p&1 ) Mul( n, t, a, tmp );
		}
	}

void show( int n, int *a ){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cout<<a[i*n+j]<<" "; cout<<endl;
        }cout<<endl;
}

int main(){
    const int N = 58;
    int T, n, m, v[N], a[N*N*N], s[N*N], tmp[N*N], t[N*N], res[N];
    scanf("%d",&T);
    while( T-- ){
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) scanf("%d",&v[i]);
        memset( a, 0, sizeof(a) );
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) a[i*n*n+j*n+j] = 1;
            a[i*n*n+i*n+i] = 1;
            a[i*n*n+i*n+(i+1)%n] = 1;
            a[i*n*n+i*n+(i+n-1)%n] = 1;
        }
        //show( n, a );

        memset( s, 0, sizeof(s) );
        for(int i=0; i<n; i++) s[i*n+i] = 1;
        memset( t, 0, sizeof(t) );
        for(int i=0; i<n; i++) t[i*n+i] = 1;
        if( m>=n ){
            for(int i=n-1; i>=0; i--) Mul( n, s, a+i*n*n, tmp );
            Power( n, s, m/n, t, tmp );
        }

        
        memset( s, 0, sizeof(s) );
        for(int i=0; i<n; i++) s[i*n+i] = 1;
        //show( n, s );
        for(int i=m%n-1; i>=0; i--) Mul( n, s, a+i*n*n, tmp );
        //show( n, s );
        Mul( n, s, t, tmp );

        //show( n, s );

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                long long w = 0;
                for(int k=0; k<n; k++) w = (w+(long long)s[j*n+k]*v[(i+k)%n])%Mod;
                res[(i+j)%n] = w;
                //if( j ) cout<<" ";
                //cout<<w;
            }//cout<<endl;
            for(int j=0; j<n; j++){
                if( j ) cout<<" ";
                cout<<res[j];
            }cout<<endl;
        }
    }
    return 0;
}
*/

/*
	static void GetPrim( int *prim, int &pn, int n ){
		bool *vis = new bool[n];
		memset( vis, 0, sizeof(bool)*n );
		pn = 0;
		for(int i=2; i<n; i++){
			if( !vis[i] ) prim[pn++] = i;
			for(int j=0; j<pn && prim[j]*i<n; j++){
				vis[prim[j]*i] = 1;
				if( i%prim[j] == 0 ) break;
			}
		}
		delete []vis;
	}
	static void div( int n, int *num, int pn, int *prim ){ // ?????? n?
		memset( num, 0, sizeof(int)*pn );
		for(int i=0; i<pn && prim[i]<=n; i++){
			for(int s=n; s/prim[i]; s/=prim[i]) num[i] += s/prim[i];
		}
	}
	static int Gcd( int a, int b ){
		if( a < b ) swap( a, b );
		while( b!=0 ){ swap( a, b ); b %= a; }
		return a;
	}
	// calculate gcd(a,b) and the integer x and y where gcd(a,b)=a*x+b*y
	static long long Ext_Gcd( int a, int b, long long &x, long long &y ){
		if( b == 0 ){ x = 1; y = 0; return a; }
		long long d = Ext_Gcd( b, a%b, x, y );
		long long t = x;  x = y;  y = t-a/b*y;
		return d;
	}
    
	// get the smallest positive answer x where x % m1 = a1 and x % m2 = a2
	static long long Mod_L_EQ( int a1, int m1, int a2, int m2 ){
		long long x, y, c = Gcd( m1, m2 );
		if( abs(a1-a2)%c != 0 ) return -1;
		Ext_Gcd( m2/c, m1/c, x, y );
		x = a2+m2*(x*(a1-a2)/c);
		y = m1*m2/c;
		x %= y;
		return ( x<0 ? x+y:x );
	}
    

const int N = 1000008;
    int pn=0, prim[N], num[N], n;
    
long long getNum( int num ){
    return 2*num+1;// (long long)(1+num)*(num+2)/2;
}

int main(){
    for(int i=2; i<1000000; i++){
        //if( 1000007%i==0 ) cout<<i<<endl;
    }
    GetPrim( prim, pn, N );
    //for(int i=0; i<pn; i++) cout<<prim[i]<<" "; cout<<endl;
    while( scanf("%d",&n)==1 ){
        div( n, num, pn, prim );
        
        long long s1 = 1, s2 = 1;
        for(int i=0; i<pn; i++){
            s1 = (s1*getNum(num[i]))%29;
        }
        for(int i=0; i<pn; i++){
            //cout<<s2<<" "<<num[i]<<" "<<getNum(num[i])<<endl;
            s2 = (s2*getNum(num[i]))%34483;
            //if( s2<0 ) getchar();
        }
        //cout<<s1<<" "<<s2<<endl;
        cout<<Mod_L_EQ(s1,29,s2,34483)<<endl;
    }
    return 0;
}
*/






int Mod = 1000000007;

// A^B % C  = A^( B%Phi(C) + Phi(C) ) % C   while B>=Phi(C)
static int powmod( int x, int n ){ // x^n % Mod
	long long s = 1, t = x;
	for(; n!=0; n>>=1){
		if( n%2 ) s = (s*t)%Mod;
		t = (t*t)%Mod;
	}
	return s;
}
// ?x????????? x^(p-2) % p
static int inv( int x ){ return powmod( x, Mod-2 ); }
// calculate C(n,k)%Mod while Mod is prime
static int C( int n, int k ){
	long long s = 1;
    if( k > n-k ) k = n-k;
	for(int i=0; i<k; i++){ s = (s*(n-i))%Mod; s = (s*inv(i+1))%Mod; }
	return s;
}

int main(){
    int T, n, K, one[1008], res[1008], num[1008]; char s[1008];
    //int q[2][2008], qn, v[2][2008];
    scanf("%d",&T);
    while( T-- ){
        scanf("%d%d",&n,&K);
        int total = 0;
        for(int i=0; i<=K; i++) total = (total+C(n,i))%Mod;
        //cout<<total<<endl;
        scanf("%s",s);

        for(int i=1; i<=(n>>1); i++){
            res[i] = 0;
            int loop = n/i, k = K, gap = 0;
            if( loop*i!=n ) continue;
            for(int j=0; j<i; j++){
                one[j] = 0;
                for(int r=0; r<loop; r++) if( s[r*i+j]=='1' ) one[j]++;
                one[j] = min( one[j], loop-one[j] );
                k -= one[j];
                gap += loop-2*one[j];
            }
            if( k<0 ) continue;
            k = min( k, gap );
            
            memset( num, 0, sizeof(int)*(k+1) );
            num[0] = 1;
            for(int j=0, up=0; j<i; j++){
                up += loop-2*one[j];
                for(int r=min(k,up), w=loop-2*one[j]; r>=w; r--){
                    num[r] = (num[r]+num[r-w])%Mod;
                }
            }
            for(int j=0; j<=k; j++) res[i] = (res[i]+num[j])%Mod;
            
            /*
            qn = 1; q[0][0] = 1; v[0][0] = 0;
            for(int j=0; j<i; j++){
                for(int r=0; r<qn; r++){ q[1][r] = q[0][r]; v[1][r] = v[0][r]; }
                for(int r=qn-1; r>=0; r--){
                    if( v[0][r]+loop-2*one[j] <= k ){
                        q[1][qn] = q[0][r];
                        v[1][qn] = v[0][r]+loop-2*one[j];
                        qn++;
                    }
                }
                if( qn>k ){
                    for(int r=0; r<=k; r++){ q[0][r] = 0; v[0][r] = r; }
                    for(int r=0; r<qn; r++) q[0][v[1][r]] += q[1][r];
                    qn = k+1;
                }else{
                    for(int r=0; r<qn; r++){ q[0][r] = q[1][r]; v[0][r] = v[1][r]; }
                }
            }
            for(int j=0; j<qn; j++) res[i] = (res[i]+q[0][j])%Mod;
            */
            for(int j=1; j<=i/2; j++){
                if( i%j!=0 ) continue;
                res[i] = (res[i]-res[j]+Mod)%Mod;
            }
            total = (total-res[i]+Mod)%Mod;
        }
        printf("%d\n",total);
    }
    return 0;
}

