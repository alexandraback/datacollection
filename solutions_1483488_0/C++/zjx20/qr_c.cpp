#include <cstdio>
#include <set>

using namespace std;

inline int rot(int a, int mod, int mut)
{
	return (a%mod)*mut + (a/mod);
}

inline int pow(int a)
{
	int res = 1;
	while(a--) res*=10;
	return res;
}

inline int count(int x)
{
	int c = 0;
	while(x>0) x/=10,c++;
	return c;
}

int tab[11];

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("qr_c_output.txt", "w", stdout);

	for(int i=0;i<11;i++) tab[i] = pow(i);

	int t;
	scanf("%d",&t);
	int ca = 0;
	while(ca++<t)
	{
		printf("Case #%d: ", ca);
		int a,b;
		scanf("%d%d",&a,&b);

		int tot = 0;
		int dig = count(a);
		for(int i=a;i<b;i++)
		{
			set<int> ss;
			for(int j=1;j<dig;j++)
			{
				int t = rot(i, tab[j], tab[dig-j]);
				if(a<=t && t<=b && i<t)
				{
					ss.insert(t);
				}
			}
			tot += ss.size();
		}
		printf("%d\n", tot);
	}
	return 0;
}