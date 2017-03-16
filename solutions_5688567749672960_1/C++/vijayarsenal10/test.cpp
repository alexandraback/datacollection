#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<math.h>
#include<map>
#include<algorithm>
#include<queue>
#include<string>
#include<climits>
#include<bitset>
#include<set>
#include<functional>

using namespace std;
typedef long long int LL;

#ifdef _WIN32
#define gx getchar
#define px putchar
#define ps putchar(' ')
#define pn putchar('\n')
#else
#define gx getchar_unlocked
#define px putchar_unlocked
#define ps putchar_unlocked(' ')
#define pn putchar_unlocked('\n')
#endif

//input
void scan(int &n)
{
    int sign = 1;
    n = 0;
    char c = gx();
    while( c < '0' || c > '9' )
    {
        if( c == '-' ) sign = -1;
        c = gx();
    }
    while( c >= '0' && c <= '9' ) n = (n<<3) + (n<<1) + c - '0', c = gx();  n = n * sign;
}
void lscan(LL &n)
{
    int sign = 1;
    n = 0;
    char c = gx();
    while( c < '0' || c > '9' )
    {
        if( c == '-' )
        sign = -1;
        c = gx();
    }
    while( c >= '0' && c <= '9' ) n = (n<<3) + (n<<1) + c - '0', c = gx();  n = n * (LL)(sign);
}
int sscan(char a[])
{
    char c = gx();
    while(c==' ' || c=='\n') c=gx();
    int i=0;
    while(c!='\n')a[i++] = c,c=gx();
    a[i]=0;
    return i;
}
int wscan(char a[])
{
    char c = gx();
    while(c==' ' || c=='\n') c=gx();
    int i=0;
    while(c!='\n' && c!=' ')a[i++] = c,c=gx();
    a[i]=0;
    return i;
}

//output
void print(int n)
{
    if(n<0)
    {
        n=-n;
        px('-');
    }
    int i=10;
    char o[10];
    do{o[--i] = (n%10) + '0'; n/=10;}while(n);
    do{px(o[i]);}while(++i<10);
}
void lprint(LL n)
{
    if(n<0LL)
    {
        n=-n;
        px('-');
    }
    int i=21;
    char o[21];
    do{o[--i] = (n%10LL) + '0'; n/=10LL;}while(n);
    do{px(o[i]);}while(++i<21);
}
void sprint(const char a[])
{
    const char *p=a;
    while(*p)px(*p++);
}


typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

const LL MOD = 1000000007LL;
const int SIZ = 1000001;

LL po(LL a, LL b, LL m)
{
	LL x=1,y=a;
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>m) x%=m;
		}
		y = (y*y);
		if(y>m) y%=m;
		b /= 2;
	}
	return x;
}

LL reverse(LL a)
{
    LL b = 0;
    while(a != 0)
    {
        b *= 10;
        b += a%10;
        a /= 10;
    }
    return b;
}

const LL siz = 1000005;
LL a[siz];
LL b[18] = {109,199,1099,1999,10999,19999,109999,199999,1099999,1999999,10999999,19999999,109999999,199999999,1099999999LL,1999999999LL,10999999999LL,19999999999LL};

string ss(LL a)
{
    string s;
    while(a != 0)
    {
        s += a%10;
        a /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
}

LL fin;
LL start = 30;
LL solve(LL n)
{
    string s = ss(n);
    int l = s.size();
    LL ans = start;
    for(int i=0;i<l-3;i++) ans += b[i];
    if(s[0] > 1)
    {
        ans++;
        ans += s[0] - 1;
    }
    for(int i=1;i<l-1;i++)
    {
        ans += 10 * s[i];
    }
    ans += s[l-1] - 1;
    if(l==4 && s[0]==1) ans++;
    return ans;
}

int main()
{
    LL t,n;
    LL i,j,k,x,y,z;
    for(i=0;i<siz;i++) a[i] = i;
    for(i=2;i<siz;i++)
    {
        a[i] = min(a[i],a[i-1] + 1);
        x = reverse(i);
        if(x < siz)a[x] = min(a[x],a[i]+1);
    }
    lscan(t);
    for(int xx=1;xx<=t;xx++)
    {
        printf("Case #%d: ",xx);
        lscan(n);
        if(n < siz)
        {
            lprint(a[n]);
            pn;
            continue;
        }
        if(n%10 == 0) fin = solve(n-1) + 1;
        else fin = solve(n);
        cout << fin << endl;
    }
    return 0;
}
