#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#include <functional>
#include <ctime>

using namespace std;

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define make_triple(x,y,z) make_pair((x), make_pair((y),(z)))
#define fr first
#define sc second
#define ts second.first
#define td second.second

typedef long long ll;
typedef unsigned long long ull; 
typedef double ld;

const long double eps = 1e-9;
const int inf = LONG_MAX;
const ll inf64 = LLONG_MAX;
const long double pi = 3.1415926535897932384626433832795;
const long long MOD = 1000000007;


#define N 1000

char buf[N];
char a[N][N];
ll fact[N];
bool c[N];


int main()
{
	int t;
	scanf("%d", &t);
	freopen("output1","w",stdout);
	
	fact[0] = 1;
	for (int i = 1; i<N; i++)
		fact[i] = (fact[i-1] * i)%MOD;
        for (int g = 0; g<t; g++)
        {
        	ll ans = 1;
        	int n;
        	scanf("%d\n", &n);
        	int kn = 0;
        	for (int h = 0; h<N; h++)
        		fill(a[h], a[h]+N, 0);
        	for (int h = 0; h<n; h++)
        		scanf("%s ", a[kn++]);
        	fill(c, c+N, false);
		for (int i = 'a'; i<='z'; i++)
		{
			int alone = 0;
			int start = 0, end = 0;
			int stl, endf, alonep;
			int kk = 0;
			for (int h = 0; h<kn; h++)
			if (!c[h] && a[h][0] != 0)
			{
				bool s = false, k = false, all = false, g = false;
				int nn = strlen(a[h]);
				int bb = 0;
				int j = 0;
				for (int jj = 0; jj<nn; jj++)
					if (a[h][jj] == i)
						g = true, bb++;
				while (j < nn && a[h][j] == i)
					s = true, j++, bb--;
				if (j == nn)
					all = true;
				j = nn-1;
				while (j >= 0 && a[h][j] == i)
					k = true, j--, bb--;
				if (g)
					c[h] = true;
				if (all) {
					kk++;
					continue;
				}
				if (!s && !k && g) {
					alone++, alonep = h;
				}
				if (s && k && !all) {
	//				cout << "first";
					goto label;
				}
				if ((s || k) && bb > 0) {
	//				cout << "second";
					goto label;
				}
				if (s)
					start++, stl=h;
				if (k)
					end++, endf=h;
			}
			if (alone && (kk || start || end || alone > 1)){
	//			cout << "third" << (char)i << alone << endl;
				goto label;
			}
			if (start > 1 || end > 1) {
	//			cout << "four";
				goto label;
			}
			ans = (ans * fact[kk])%MOD;	
			int len = 0;
			a[kn][0] = 0;
			if (alone) 
			{
				for (int h = 0; h<strlen(a[alonep]); h++)
					a[kn][len++] = a[alonep][h];	
				goto label1;
			}
			if (end)
				for (int h = 0; h<strlen(a[endf]); h++)
					a[kn][len++] = a[endf][h];
			else
				if (kk > 0)
					a[kn][len++] = i;
			
			if (start)
				for (int h = 0; h<strlen(a[stl]); h++)
					a[kn][len++] = a[stl][h];
			else 
				if (kk > 0)
					a[kn][len++] = i;
label1:
			kn++;
			if (len == 0)
				kn--;
		}
		{
			int ccount = 0;
			for (int i = 0; i<kn; i++)
				if (!c[i])
					ccount++;	
			ans = (ans * fact[ccount])%MOD;	
		}	
		printf("Case #%d: %d\n", g+1, ans);
		continue;
label:
		printf("Case #%d: 0\n", g+1);
        }
	return 0;	
}