//by Tanmay Chaudhari
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//#pragma comment(linker, "/STACK:66777216")
#include <bits/stdc++.h>
using namespace std;

#define si(a)				scanf("%d",&a)
#define sl(a)				scanf("%lld",&a)
#define pi(a)				printf("%d\n",a)
#define pl(a)				printf("%lld\n",a)

typedef long long			ll;
typedef vector<int>			vi;
typedef pair<int, int>		ii;
typedef vector<vi>			vvi;
typedef vector<ii>			vii;

#define fast_io				ios_base::sync_with_stdio(false);cin.tie(NULL)
#define SET(a,b)			memset(a,b,sizeof(a))	
#define forall(i,a,b)		for(int i=a; i<b; i++)
#define forrev(i,a,b)		for(int i=a; i>=b; i--)
#define forr(it,container)  for(auto it=container.begin(); it!=container.end(); it++)
#define w(t)				int t;si(t);while(t--)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1 << " | ";__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int cnt[10];
string digits[12] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
map<char, int > mp;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	si(t);
	forall(tt, 1, t + 1)
	{
		string s;
		cin >> s;
		forall(i, 0, s.size())
		{
			mp[s[i]]++;
		}
		while (mp['Z'] != 0)//zero
		{
			cnt[0]++;
			for (int i = 0;i < digits[0].size();i++)
				mp[digits[0][i]]--;
		}
		while (mp['U'] != 0)//four
		{
			cnt[4]++;
			for (int i = 0;i < digits[4].size();i++)
				mp[digits[4][i]]--;
		}
		while (mp['F'] != 0)//five
		{
			cnt[5]++;
			for (int i = 0;i < digits[5].size();i++)
				mp[digits[5][i]]--;
		}
		while (mp['X'] != 0)//six
		{
			cnt[6]++;
			for (int i = 0;i < digits[6].size();i++)
				mp[digits[6][i]]--;
		}
		while (mp['S'] != 0)//seven
		{
			cnt[7]++;
			for (int i = 0;i < digits[7].size();i++)
				mp[digits[7][i]]--;
		}
		while (mp['G'] != 0)//eight
		{
			cnt[8]++;
			for (int i = 0;i < digits[8].size();i++)
				mp[digits[8][i]]--;
		}
		while (mp['W'] != 0)//two
		{
			cnt[2]++;
			for (int i = 0;i < digits[2].size();i++)
				mp[digits[2][i]]--;
		}
		while (mp['T'] != 0)//three
		{
			cnt[3]++;
			for (int i = 0;i < digits[3].size();i++)
				mp[digits[3][i]]--;
		}
		while (mp['O'] != 0)//one
		{
			cnt[1]++;
			for (int i = 0;i < digits[1].size();i++)
				mp[digits[1][i]]--;
		}
		while (mp['N'] != 0)//nine
		{
			cnt[9]++;
			for (int i = 0;i < digits[9].size();i++)
				mp[digits[9][i]]--;
		}
		printf("Case #%d: ", tt);
		for (int i = 0;i < 10;i++)
			while (cnt[i]--)
				printf("%d", i);
		puts("");
		SET(cnt, 0);
		mp.clear();
	}
	return 0;
}