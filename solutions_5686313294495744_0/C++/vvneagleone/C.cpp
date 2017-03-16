// Template and program by vvneagleone

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

int t, T, n, m, i, j, k;
string s1, s2;
int x[100], y[100];

int a1, a2;
int mask[100];

bool eval() {
    // Check if the subset has all values <= a1, a2
    int m1[100];
    int m2[100];
    for( k = 1; k <= a1; ++k ) m1[k] = 0;
    for( k = 1; k <= a2; ++k ) m2[k] = 0;
    for( k = 0; k < n; ++k ) {
        if( mask[k] ) {
            m1[ x[k] ] = 1;
            m2[ y[k] ] = 1;
        }
    }
    for( k = 1; k <= a1; ++k ) {
        if( m1[k] == 0 ) break;
    }
    if( k <= a1 ) return 0;
    for( k = 1; k <= a2; ++k ) {
        if( m2[k] == 0 ) break;
    }
    if( k <= a2 ) return 0;
    return 1;
}

int minct;

void gen( int i, int ct ) {
    if( i == n ) {
        if( eval() ) {
            if( ct < minct ) {
                minct = ct;
            }
        }
        return;
    }
    gen(i+1, ct);
    mask[i] = 1;
    gen(i+1, ct+1);
    mask[i] = 0;
}

int main() {
    cin >> T;
    for( t = 1; t <= T; ++t ) {
        map< string, int> fir, sec;
        cin >> n;
        minct = n;
        a1 = 0; a2 = 0;

        for( i = 0; i < n; ++i ) {
            cin >> s1 >> s2;

            auto v1 = fir.find( s1 );
            if( v1 == fir.end() ) {
                a1++;
                fir.insert( make_pair(s1,a1) );
                x[i] = a1;
            }
            else {
                x[i] = v1->second;
            }

            auto v2 = sec.find( s2 );
            if( v2 == sec.end() ) {
                a2++;
                sec.insert( make_pair(s2,a2) );
                y[i] = a2;
            }
            else {
                y[i] = v2->second;
            }
        }

        /*cout << endl << endl;
        for( i = 0; i < n; ++i ) cout << x[i] << " ";
        cout << endl;
        for( i = 0; i < n; ++i ) cout << y[i] << " ";
        cout << endl;
        */

        gen( 0, 0 );

        cout << "Case #" << t << ": " << n-minct << endl;
    }
    return 0;
}
