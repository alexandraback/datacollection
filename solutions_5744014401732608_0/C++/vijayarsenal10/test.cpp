#include<stdio.h>
#include<iostream>
#include<vector>
#include<iomanip>
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
#include<ctime>
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
    while(c!=EOF && c!='\n' && c!=' ')a[i++] = c,c=gx();
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

int b,m,a[10][10],ans[10][10],flag;

int check()
{
	int temp[10][10],i,j,k,ct,an=0,x[10][10];
	for(i=0;i<b;i++)
	for(j=0;j<b;j++)
	temp[i][j] = a[i][j];
	for(ct=0;ct<15;ct++)
	{
		an += temp[0][b-1];
		for(i=0;i<b;i++)
		for(j=0;j<b;j++)
		x[i][j] = 0;
		
		for(i=0;i<b;i++)
		{
			for(j=0;j<b;j++)
			{
				for(k=0;k<b;k++)
				{
					x[i][j] += a[i][k]*temp[k][j];
				}
			}
		}
		
		for(i=0;i<b;i++)
		for(j=0;j<b;j++)
		temp[i][j] = x[i][j];
	}
	if(an==m) return 1;
	return 0;
}

void rec(int i, int j)
{
	if(flag) return;
	if(i==j)
	{
		a[i][j] = 0;
		++j;
		if(j >= b)
		{
			j = 0;
			i++;
		}
		rec(i,j);
		if(flag) return;
	}
	else if(i==b-1)
	{
		if(check())
		{
			int x,y;
			for(x=0;x<b;x++)
			for(y=0;y<b;y++)
			ans[x][y] = a[x][y];
			flag = 1;
		}
		return;
	}
	else
	{
		a[i][j] = 0;
		int x=i,y=j;
		++y;
		if(y >= b)
		{
			y = 0;
			++x;
		}
		rec(x,y);
		if(flag) return;
		a[i][j] = 1;
		x=i,y=j;
		++y;
		if(y >= b)
		{
			y = 0;
			++x;
		}
		rec(x,y);
		if(flag) return;
	}
}

int main()
{
	int t,xx,i,j;
	string s;
	vector<string> v;
	map< pair<int,int>, vector<string> > mp;
	map< pair<int,int>, vector<string> >::iterator it;
	for(i=2;i<=6;i++)
	{
		for(j=1;j<=20;j++)
		{
			cin >> s;
			if(s=="IMPOSSIBLE") continue;
			v.clear();
			for(t=0;t<i;t++)
			{
				cin >> s;
				v.push_back(s);
			}
			mp[make_pair(i,j)] = v;
		}
	}
	cin >> t;
	for(xx=1;xx<=t;xx++)
	{
		printf("Case #%d: ",xx);
		cin >> b >> m;
		it = mp.find( make_pair(b,m) );
		if(it==mp.end())
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		v = it->second;
		cout << "POSSIBLE" << endl;
		for(i=0;i<b;i++) cout << v[i] << endl;
		continue;
		for(i=0;i<b;i++)
		for(j=0;j<b;j++)
		a[i][j] = 0;
		flag = 0;
		rec(0,0);
		if(!flag) cout << "IMPOSSIBLE" << endl;
		else
		{
			cout << "POSSIBLE" << endl;
			for(i=0;i<b;i++)
			{
				for(j=0;j<b;j++) cout << ans[i][j] << "";
				cout << endl;
			}
		}
	}
	return 0;
}

