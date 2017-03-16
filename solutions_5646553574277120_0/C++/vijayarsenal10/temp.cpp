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

int x[105];
int c,d,v;
int ans;
int z[105];

int main()
{
    int t,temp,i,j,k,n,s;
    vector<int> sum,cur;
    scan(t);
    for(int xx=1;xx<=t;xx++)
    {
        scan(c);
        scan(d);
        scan(v);
        for(i=0;i<=v;i++) x[i] = 0;
        sum.clear();
        cur.clear();
        for(i=0;i<d;i++)
        {
            scan(temp);
            cur.push_back(temp);
        }
        
        n = cur.size();
        n = (1 << n);
        int j,k;
        for(i=1;i<n;i++)
        {
            s = 0;
            for(j=0;j<cur.size();j++)
            {
                k = (1<<j);
                if(i&k) s += cur[j];
            }
            if(s <= v) sum.push_back(s);
        }
        
        for(i=1;i<=v;i++) x[i] = 0;
        for(i=0;i<sum.size();i++)
        {
            x[sum[i]] = 1;
        }
        
        ans = 0;
        
        while(1)
        {
            k = 0;
            for(i=1;i<=v;i++)
            {
                if(x[i]==0)
                {
                    k = 1;
                    break;
                }
            }
            if(k==0) break;
            int ne = i;
            ans++;
            cur.clear();
            cur = sum;
            cur.push_back(ne);
            for(i=0;i<sum.size();i++)
            {
                if(sum[i]+ne <= v) cur.push_back(sum[i]+ne);
            }
            sum = cur;
            for(i=1;i<=v;i++) x[i] = 0;
            for(i=0;i<sum.size();i++)
            {
                x[sum[i]] = 1;
            }
        }
        
        printf("Case #%d: ",xx);
        cout << ans << endl;
    }
    return 0;
}

