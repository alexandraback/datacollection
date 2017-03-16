// Template and program by vvneagleone

// My own elaborate big integer class, which you won't see :D
// Might be on github soon
#include "BigInteger.hpp"

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<climits>
#include<vector>
#include<utility>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
typedef long double LD;
#define MOD 1000000007LL

#ifdef __GNUC__
    #if ( __GNUC__ >= 4 && __GNUC_MINOR__ >= 7 && __cplusplus > 201100L )
        #include<unordered_set>
        #include<unordered_map>
    #endif
#endif // __GNUC__

#ifdef __WIN32
    #define gx getchar
    #define px putchar
    #define ps putchar(' ')
    #define pn putchar('\n')
#else
    #define gx getchar_unlocked
    #define px putchar_unlocked
    #define ps putchar_unlocked(' ')
    #define pn putchar_unlocked('\n')
#endif // __WIN32

void scan(int &n){int sign=1;n=0;char c=gx();while(c<'0'||c>'9'){if(c=='-')sign=-1;c=gx();}while(c>='0'&&c<='9')n=(n<<3)+(n<<1)+c-'0',c=gx();n=n*sign;}
void lscan(LL &n){int sign=1;n=0;char c=gx();while(c<'0'||c>'9'){if(c=='-')sign=-1;c=gx();}while(c>='0'&&c<='9')n=(n<<3)+(n<<1)+c-'0',c=gx();n=n*(LL)(sign);}
int sscan(char a[]){char c=gx();while(c==' '||c=='\n')c=gx();int i=0;while(c!='\n')a[i++]=c,c=gx();a[i]=0;return i;}
int wscan(char a[]){char c=gx();while(c==' '||c=='\n')c=gx();int i=0;while(c!='\n'&&c!=' ')a[i++]=c,c=gx();a[i]=0;return i;}
void print(int n){if(n<0){n=-n;px('-');}int i=10;char o[10];do{o[--i]=(n%10)+'0';n/=10;}while(n);do{px(o[i]);}while(++i<10);}
void lprint(LL n){if(n<0LL){n=-n;px('-');}int i=21;char o[21];do{o[--i]=(n%10LL)+'0';n/=10LL;}while(n);do{px(o[i]);}while(++i<21);}
void sprint(const char*a){const char*p=a;while(*p)px(*p++);}
LL power(LL b,LL e,LL m=MOD){LL r=1;while(e){if(e&1)r=(r*b)%m;b=(b*b)%m;e>>=1;}return r;}
LL minvp(LL n, LL m=MOD){return power(n,m-2,m);}
LL minv(LL a,LL m=MOD){LL c,t,q,x,y;c=m;x=0;y=1;while(a>1){q=a/c;t=c;c=a%c;a=t;t=x;x=y-q*x;y=t;}if(y<0)y+=m;return y;}
LL mmul(LL a,LL b,LL m=MOD){LL x=0,y=a%m;while(b){if(b&1)x=(x+y)%m;y=(y<<1)%m;b>>=1;}return x%m;}
LL absll(LL x){if(x<0)return -x;return x;}

LL jamcoin[100];
LL cnt = 0;
LL n, j, t, T, i, k, l;
vector<LL> primes;
bool sieve[10000005];

void pre() {
    primes.reserve(700000);
    for( i = 0; i < 10000000; ++i ) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for( i = 2; i < 10000000; ++i ) {
        if( sieve[i] == 1 ) {
            j = i*i;
            while( j < 10000000 ) {
                sieve[j] = 0;
                j += i;
            }
        }
    }
    for( i = 0; i < 10000000; ++i ) {
        if( sieve[i] ) primes.push_back(i);
    }
}

BigInteger get_number( int b ) {
    BigInteger ret(0);
    BigInteger base(b);
    BigInteger x = 1;
    for( k = n-1; k >= 0; --k ) {
        if( jamcoin[k] ) ret += x;
        x *= base;
    }
    return ret;
}

void gen( int i ) {
    if( i >= n-1 ) {
        int base;
        BigInteger num[12];
        for( base = 2; base <= 10; ++base ) {
            num[base] = get_number( base );
            if( BI_Miller_Rabin(num[base],64) ) {
                break;
            }
        }
        if( base == 11 ) {
            vector<LL> res;
            for( base = 2; base <= 10; ++base ) {
                BigInteger nm = num[base];
                for( k = 0; k < primes.size(); ++k) {
                    if( (nm % primes[k]) == 0 ) {
                        res.push_back(primes[k]);
                        break;
                    }
                }
                if( k == primes.size() ) {
                    break;
                }
            }
            if( base > 10 ) {
                ++cnt;
                for( int i = 0; i < n; ++i ) cout << jamcoin[i];
                cout << " ";
                for( int i = 0; i < res.size(); ++i ) cout << res[i] << " ";
                cout << endl;
            }
        }
        return;
    }
    gen(i+1);
    if( cnt >= j ) return;
    jamcoin[i] = 1;
    gen(i+1);
    if( cnt >= j ) return;
    jamcoin[i] = 0;
}

int main() {
    pre();
    cin >> T;
    for( t = 1; t <= T; ++t ) {
        cin >> n >> j;
        cout << "Case #" << t << ":" << endl;
        jamcoin[0] = jamcoin[n-1] = 1;
        for( i = 1; i < n-1; ++i ) jamcoin[i] = 0;
        gen(1);
    }
    return 0;
}
