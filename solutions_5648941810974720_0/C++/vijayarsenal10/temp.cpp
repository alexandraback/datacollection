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
typedef long long int ll;
typedef unsigned long long int ull;

#ifdef _WIN32
    #define gx getchar
    #define px putchar
    #define ps putchar(' ')
    #define pn putchar('\n')
    #define DEBUG 1
#else
    #define gx getchar_unlocked
    #define px putchar_unlocked
    #define ps putchar_unlocked(' ')
    #define pn putchar_unlocked('\n')
    #define DEBUG 0
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
void lscan(ll &n)
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
    while( c >= '0' && c <= '9' ) n = (n<<3) + (n<<1) + c - '0', c = gx();  n = n * (ll)(sign);
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
void lprint(ll n)
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


ll po(ll a, ll b, ll m)
{
	ll x=1,y=a;
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1000000007LL;
const int siz = 1000005;

vector<string> s;

int main()
{
    s.push_back("ZERO");//done
    s.push_back("ONE"); //done
    s.push_back("TWO"); //done
    s.push_back("THREE"); //done
    s.push_back("FOUR"); //done
    s.push_back("FIVE"); //done
    s.push_back("SIX"); //done;
    s.push_back("SEVEN"); //done
    s.push_back("EIGHT"); //done
    s.push_back("NINE"); //done
    int xx,t,n,i,j,ans[10];
    int ct,it;
    cin >> t;
    string in;
    int a[26];
    for(xx=1;xx<=t;xx++)
    {
        printf("Case #%d: ",xx);
        cin >> in;
        for(i=0;i<26;i++) a[i] = 0;
        n = in.size();
        for(i=0;i<n;i++) a[in[i]-'A']++;
        for(i=0;i<10;i++) ans[i] = 0;
        it = 'Z' - 'A';
        while(a[it])
        {
            ans[0]++;
            a['Z' - 'A']--;
            a['E' - 'A']--;
            a['R' - 'A']--;
            a['O' - 'A']--;
        }
        it = 'X' - 'A';
        while(a[it])
        {
            ans[6]++;
            a['S' - 'A']--;
            a['I' - 'A']--;
            a['X' - 'A']--;
        }
        it = 'G' - 'A';
        while(a[it])
        {
            ans[8]++;
            a['E' - 'A']--;
            a['I' - 'A']--;
            a['G' - 'A']--;
            a['H' - 'A']--;
            a['T' - 'A']--;
        }
        it = 'H' - 'A';
        while(a[it])
        {
            ans[3]++;
            a['T' - 'A']--;
            a['H' - 'A']--;
            a['R' - 'A']--;
            a['E' - 'A']--;
            a['E' - 'A']--;
        }
        it = 'T' - 'A';
        while(a[it])
        {
            ans[2]++;
            a['T' - 'A']--;
            a['W' - 'A']--;
            a['O' - 'A']--;
        }
        it = 'U' - 'A';
        while(a[it])
        {
            ans[4]++;
            a['F' - 'A']--;
            a['O' - 'A']--;
            a['U' - 'A']--;
            a['R' - 'A']--;
        }
        it = 'O' - 'A';
        while(a[it])
        {
            ans[1]++;
            a['O' - 'A']--;
            a['N' - 'A']--;
            a['E' - 'A']--;
        }
        it = 'F' - 'A';
        while(a[it])
        {
            ans[5]++;
            a['F' - 'A']--;
            a['I' - 'A']--;
            a['V' - 'A']--;
            a['E' - 'A']--;
        }
        it = 'S' - 'A';
        while(a[it])
        {
            ans[7]++;
            a['S' - 'A']--;
            a['E' - 'A']--;
            a['V' - 'A']--;
            a['E' - 'A']--;
            a['N' - 'A']--;
        }
        it = 'E' - 'A';
        while(a[it])
        {
            ans[9]++;
            a['N' - 'A']--;
            a['I' - 'A']--;
            a['N' - 'A']--;
            a['E' - 'A']--;
        }
        for(i=0;i<10;i++)
        {
            j = ans[i];
            while(j--) cout << i;
        }
        pn;
    }
    return 0;
}
