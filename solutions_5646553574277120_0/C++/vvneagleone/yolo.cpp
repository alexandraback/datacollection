// Program and program template by vvneagleone

#include<cstdio>
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
LL minv(LL a,LL m=MOD){LL c,t,q,x,y;c=m;x=0;y=1;while(a>1){q=a/c;t=c;c=a%c;a=t;t=x;x=y-q*x;y=t;}if(y<0)y+=m;return y;}
LL mmul(LL a,LL b,LL m=MOD){LL x=0,y=a%m;while(b){if(b&1)x=(x+y)%m;y=(y<<1)%m;b>>=1;}return x%m;}
LL absll(LL x){if(x<0)return -x;return x;}

int mark[400];
vector<int> coins;
int c, d, v;

void add( int x ) {
    for( int j = v; j >= 1; --j ) {
        if( j - x >= 0 && mark[ j - x ] == 1 ) mark[j] = 1;
    }
}

void ffill() {
    int i, j, k;
    for( i = 1; i <= v; ++i ) mark[i] = 0;
    mark[0] = 1;
    k = coins.size();
    for( i = 0; i < k; ++i ) {
        for( j = v; j >= 1; --j ) {
            if( j - coins[i] >= 0 && mark[ j - coins[i] ] == 1 ) mark[j] = 1;
        }
    }
}

int main() {
    int t, T, i, j, k, ct;
    LL ans;
    cin >> T;
    for( t = 1; t <= T; ++t ) {
        coins.clear();
        ct = 0;
        cin >> c >> d >> v;
        for( i = 0; i < d; ++i ) {
            cin >> k;
            coins.push_back(k);
        }
        ffill();
        //cout << "Initial " << endl;
        //for( int j = 0; j <= v; ++j ) cout << mark[j] << " ";
        //cout << endl << endl;
        for( i = 0; i <= v; ++i ) {
            if( mark[i] == 0 ) {
                //cout << "Mark of " << i << " is zero - adding " << endl;
                ++ct;
                add(i);
                //for( int j = 0; j <= v; ++j ) cout << mark[j] << " ";
                //cout << endl;
            }
        }
        cout << "Case #" << t << ": " << ct << endl;
    }
    return 0;
}
