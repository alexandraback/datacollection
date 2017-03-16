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

map<string, int > fs, sc, tempfs, tempsc;
string s[100][2];
int main()
{
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("output.txt","w",stdout);
	int t, n, itr, ans, cnt, temp;
	bool ok;
	si(t);
	forall(tt, 1, t + 1)
	{
		si(n);
		ans = 0;
		itr = 0;
		forall(i, 0, n)
		{
			cin >> s[i][0] >> s[i][1];
			fs[s[i][0]]++;
			sc[s[i][1]]++;
		}
		for (int i = 1;i < (1 << n);i++)
		{
			tempfs = fs;
			tempsc = sc;
			ok = 1;
			for (int j = 0;j < n;j++)
			{
				if (i&(1 << j))
				{
					if (tempfs[s[j][0]] >= 2 && tempsc[s[j][1]] >= 2)
					{
						tempfs[s[j][0]]--;
						tempsc[s[j][1]]--;
					}
					else
						ok = 0;
				}
			}
			if (ok)
			{
				cnt = 0;
				temp = i;
				while (temp)
				{
					if (temp & 1)
						cnt++;
					temp >>= 1;
				}
				ans = max(ans, cnt);
			}
		}
		printf("Case #%d: %d\n",tt, ans);
		fs.clear();
		sc.clear();
		tempfs.clear();
		tempsc.clear();
	}
	return 0;
}