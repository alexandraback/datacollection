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
typedef unsigned long long ULL;
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
string CC, JJ;
int C[100], J[100];
ULL cval, jval, mindiff, minc, minj;

void update() {
    cval = jval = 0;
    for( i = 0; i < n; ++i ) {
        cval *= 10;
        cval += C[i];
        jval *= 10;
        jval += J[i];
    }
    ULL diff;
    if( cval > jval ) {
        diff = cval - jval;
    }
    else {
        diff = jval - cval;
    }

    if( diff < mindiff ) {
        mindiff = diff;
        minc = cval;
        minj = jval;
    }
    else if ( diff == mindiff ) {
        if( cval < minc ) {
            minc = cval;
            minj = jval;
        }
        else if( cval == minc && jval < minj ) {
            minj = jval;
        }
    }
}

void gen( int i, int flag ) {
    if( i == n || flag ) {
        // evaluate
        if( i == n ) {
            update();
        }
        else {
            if( flag == 1 ) {
                // C is greater
                for( j = i; j < n; ++j ) {
                    if( CC[j] == '?' ) C[j] = 0;
                    else C[j] = CC[j] - '0';

                    if( JJ[j] == '?' ) J[j] = 9;
                    else J[j] = JJ[j] - '0';
                }
            }
            else {
                // J is greater
                for( j = i; j < n; ++j ) {
                    if( CC[j] == '?' ) C[j] = 9;
                    else C[j] = CC[j] - '0';

                    if( JJ[j] == '?' ) J[j] = 0;
                    else J[j] = JJ[j] - '0';
                }
            }
            update();
        }
        return;
    }

    if( CC[i] == '?' && JJ[i] == '?' ) {
        C[i] = 0;
        J[i] = 0;
        gen(i+1, 0);

        C[i] = 1;
        J[i] = 0;
        gen(i+1, 1);

        C[i] = 0;
        J[i] = 1;
        gen(i+1, 2);
    }
    else if( CC[i] == '?' ) {
        J[i] = JJ[i] - '0';
        C[i] = J[i];
        gen(i+1,0);
        if( C[i] != 0 ) {
            --C[i];
            gen(i+1, 2);
            ++C[i];
        }
        if( C[i] != 9 ) {
            ++C[i];
            gen(i+1, 1);
            --C[i];
        }
    }
    else if( JJ[i] == '?' ) {
        C[i] = CC[i] - '0';
        J[i] = C[i];
        gen(i+1,0);
        if( J[i] != 0 ) {
            --J[i];
            gen(i+1, 1);
            ++J[i];
        }
        if( J[i] != 9 ) {
            ++J[i];
            gen(i+1, 2);
            --J[i];
        }
    }
    else {
        C[i] = CC[i] - '0';
        J[i] = JJ[i] - '0';
        if( C[i] > J[i] ) {
            gen(i+1,1);
        }
        else if ( C[i] < J[i] ) {
            gen(i+1,2);
        }
        else {
            gen(i+1,0);
        }
    }
}

int main() {
    cin >> T;
    for( t = 1; t <= T; ++t ) {
        cin >> CC >> JJ;
        n = CC.size();
        mindiff = LLONG_MAX;
        gen(0, 0);

        cout << "Case #" << t << ": " << setfill('0') << setw(n) << minc << " " << setfill('0') << setw(n) << minj << endl;
    }
    return 0;
}
