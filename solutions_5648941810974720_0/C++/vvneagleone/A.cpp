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
int ct[26],op[10];
string s;

int main() {
    cin >> T;
    for( t = 1; t <= T; ++t ) {
        cin >> s;
        for( i = 0; i < 26; ++i ) ct[i] = 0;
        for( i = 0; i < 10; ++i ) op[i] = 0;
        for( i = 0; i < s.size(); ++i ) {
            ++ct[s[i]-'A'];
        }
        while( ct['Z'-'A'] ) {
            --ct['Z'-'A'];
            --ct['E'-'A'];
            --ct['R'-'A'];
            --ct['O'-'A'];
            ++op[0];
        }
        while( ct['W'-'A'] ) {
            --ct['T'-'A'];
            --ct['W'-'A'];
            --ct['O'-'A'];
            ++op[2];
        }
        while( ct['U'-'A'] ) {
            --ct['F'-'A'];
            --ct['O'-'A'];
            --ct['U'-'A'];
            --ct['R'-'A'];
            ++op[4];
        }
        while( ct['X'-'A'] ) {
            --ct['S'-'A'];
            --ct['I'-'A'];
            --ct['X'-'A'];
            ++op[6];
        }
        while( ct['G'-'A'] ) {
            --ct['E'-'A'];
            --ct['I'-'A'];
            --ct['G'-'A'];
            --ct['H'-'A'];
            --ct['T'-'A'];
            ++op[8];
        }
        while( ct['R'-'A'] ) {
            --ct['T'-'A'];
            --ct['H'-'A'];
            --ct['R'-'A'];
            --ct['E'-'A'];
            --ct['E'-'A'];
            ++op[3];
        }
        while( ct['O'-'A'] ) {
            --ct['O'-'A'];
            --ct['N'-'A'];
            --ct['E'-'A'];
            ++op[1];
        }
        while( ct['F'-'A'] ) {
            --ct['F'-'A'];
            --ct['I'-'A'];
            --ct['V'-'A'];
            --ct['E'-'A'];
            ++op[5];
        }
        while( ct['V'-'A'] ) {
            --ct['S'-'A'];
            --ct['E'-'A'];
            --ct['V'-'A'];
            --ct['E'-'A'];
            --ct['N'-'A'];
            ++op[7];
        }
        while( ct['N'-'A'] ) {
            --ct['N'-'A'];
            --ct['I'-'A'];
            --ct['N'-'A'];
            --ct['E'-'A'];
            ++op[9];
        }
        cout << "Case #" << t << ": ";
        for( i = 0; i < 10; ++i ) {
            while( op[i]-- ) cout << i;
        }
        cout << endl;
    }
    return 0;
}
