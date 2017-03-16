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

int n;
int ac,aj,ans;

int calc(string a, string b)
{
    int x=0,y=0;
    if(n==3)
    {
        x = (a[0]-'0')*100 + (a[1]-'0')*10 + (a[2]-'0');
        y = (b[0]-'0')*100 + (b[1]-'0')*10 + (b[2]-'0');
    }
    if(n==2)
    {
        x = (a[0]-'0')*10 + (a[1]-'0');
        y = (b[0]-'0')*10 + (b[1]-'0');
    }
    if(n==1)
    {
        x = (a[0]-'0');
        y = (b[0]-'0');
    }
    int z = x-y;
    if(z < 0) z *= -1;
    if(z < ans)
    {
        ans = z;
        ac = x;
        aj = y;
    }
    if(z == ans)
    {
        if(x < ac)
        {
            ac = x;
            aj = y;
            
        }
        if(x==ac)
        {
            if(y < aj)
            {
                ac = x;
                aj = y;
            }
        }
    }
}

void rec(string a, string b, int i, int j)
{
    if(i==n)
    {
        if(j==n)
        {
            calc(a,b);
            return;
        }
    }
    if(i==n)
    {
        if(b[j] != '?') rec(a,b,i,j+1);
        else
        {
            for(int k=0;k<10;k++)
            {
                string temp = b;
                temp[j] = k+'0';
                rec(a,temp,i,j+1);
            }
        }
        return;
    }
    else if(a[i] != '?') rec(a,b,i+1,j);
    else if(i != n)
    {
        for(int k=0;k<10;k++)
        {
            string temp = a;
            temp[i] = k+'0';
            rec(temp,b,i+1,j);
        }
    }
}

int main()
{
    string c,j;
    int t,x;
    cin >> t;
    for(x=1;x<=t;x++)
    {
        printf("Case #%d: ",x);
        cin >> c >> j;
        n = c.size();
        ans = INT_MAX;
        rec(c,j,0,0);
        c.clear();
        j.clear();
        while(ac)
        {
            c += ac%10 + '0';
            ac /= 10;
        }
        while(aj)
        {
            j += aj%10 + '0';
            aj /= 10;
        }
        reverse(c.begin(),c.end());
        reverse(j.begin(),j.end());
        while(c.size() < n)
        {
            c.insert(c.begin(),'0');
        }
        while(j.size() < n)
        {
            j.insert(j.begin(),'0');
        }
        cout << c << " " << j << endl;
    }
    return 0;
}
