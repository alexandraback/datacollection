#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define sqr(x) ((x) * (x))
#define all(v) (v).begin(),(v).end()
#define sortv(v) sort(all(v))
#define num(x) ((x)-'0')
#define ch(x) ((x)+'0')
#define bit_count __builtin_popcount
#define bit_countll __builtin_popcountll
#define THIS (*this)

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
#define g getchar_unlocked
template<class T>
bool io(T &res)
{
	static char c=' ';
	while(c == ' ' || c == '\n')
	{
		c = g();
	}
	if(c == -1)
	{
		return 0;
	}
	res = num(c);
	while((c=g()) && c != ' ' && c != '\n' && c!=-1)
	{
		res = (res << 3) + (res << 1) + num(c);
	}
	return 1;
}

template<class T>
string inttostr(T x)
{
	string res="";
	while(x)
	{
		char t=ch(x%10);
		x/=10;
		res=t+res;
	}
	return res;
}

template<class T>
T strtoint(string x)
{
	T res=0;
	for(int i=0; i<x.size(); i++)
	{
		res=(res<<3)+(res<<1)+num(x[i]);
	}
	return res;
}
void open(string a)
{
	freopen((a+".in").c_str(),"r",stdin);
	freopen((a+".out").c_str(),"w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

#define INF 1000000007
#define LINF 1000000000000000007ll
#define DINF 1000000000000000007.00
#define INV (-INF)
#define LINV (-LINF)
#define DINV (-DINF)
#define EPS 1e-9
#define MOD 1000000007

#define MX 1000

int solve()
{
	int res = INF;
	int n;
	cin >> n;
	vector<int> V;
	for(int i = 0 ; i < n ; i++)
	{
		int x;
		cin >> x;
		V.pb(x);
	}
	for(int lmt = 1 ; lmt <= 1000 ; lmt++)
	{
		int tmp = lmt;
		for(int i = 0 ; i < V.size() ; i ++)
		{
			tmp += (V[i]-1) / lmt;
		}
		res = min(res , tmp);
	}
	return res;
}

int main()
{
	int t,no = 0;
	cin >> t;
	while(t--)
	{
		cout << "Case #" << ++no << ": " << solve() << endl;
	}
	return 0;
}
