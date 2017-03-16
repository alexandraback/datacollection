#include <iostream>
#include <fstream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>

#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define foreach(it, c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define sz(v) ((int) v.size())
#define mp(a, b) make_pair(a, b)
 
using namespace std;
 
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<char, char> pcc;

char inp[10010];
char rinp[10010];

pcc op(pcc a, pcc b)
{
	pcc ans;
	if(a.ff == b.ff) ans.ff = '+';
	else ans.ff = '-';

	if(a.ss == '1') ans.ss = b.ss;
	else if(b.ss == '1') ans.ss = a.ss;
	else if(a.ss == b.ss)
	{
		if(ans.ff == '+') ans.ff = '-';
		else ans.ff = '+';

		ans.ss = '1';
	}
	else if(a.ss == 'i' and b.ss == 'j') ans.ss = 'k';
	else if(a.ss == 'j' and b.ss == 'k') ans.ss = 'i';
	else if(a.ss == 'k' and b.ss == 'i') ans.ss = 'j';
	else
	{
		if(ans.ff == '+') ans.ff = '-';
		else ans.ff = '+';

		if(b.ss == 'i' and a.ss == 'j') ans.ss = 'k';
		else if(b.ss == 'j' and a.ss == 'k') ans.ss = 'i';
		else if(b.ss == 'k' and a.ss == 'i') ans.ss = 'j';
	}

	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);

	for(int tt = 1; tt<=t; tt++)
	{
		int l;
		lli x;
		scanf("%d%lld", &l, &x);
		scanf("%s", inp);
		strcpy(rinp, inp);
		reverse(rinp, rinp+l);

		int mi = INF, mk = INF;
		int mmi = INF, mmk = INF;

		pcc curr = mp('+', '1');
		for(int i=0; i<2*l; i++)
		{
			curr = op(curr, mp('+', inp[i%l]));
			if(curr == mp('+', 'i')) mi = min(mi, i);
			else if(curr == mp('-', 'i')) mmi = min(mmi, i);
		}

		// assert(curr == mp('-','1'));

		curr = mp('+', '1');
		for(int i=0; i<2*l; i++)
		{
			curr = op(mp('+', rinp[i%l]), curr);
			if(curr == mp('+', 'k')) mk = min(mk, i);
			else if(curr == mp('-', 'k')) mmk = min(mmk, i);
		}

		// assert(curr == mp('-','1'));

		curr = mp('+', '1');
		for(int i=0; i<l; i++) curr = op(curr, mp('+', inp[i%l]));

		if(curr.ss != '1')
		{
			mi = min(mi, mmi+2*l);
			mk = min(mk, mmk+2*l);
		}
		else
		{
			mi = min(mi, mmi +l);
			mk = min(mk, mmk +l);
		}

		if(curr.ss != '1')
		{
			if(x%4 == 0) curr = mp('+', '1');
			else if(x%4 == 2) curr = mp('-', '1');
			else if(x%4 == 3) curr.ff = curr.ff == '-'?'+':'-';
		}
		else
		{
			if(x%2 == 0) curr = mp('+', '1');
		}

		if(curr != mp('-','1')) printf("Case #%d: NO\n", tt);
		else if(mi < INF and mk < INF)
		{
			if(mi+mk < l*x) printf("Case #%d: YES\n", tt);
			else printf("Case #%d: NO\n", tt);
		}
		else printf("Case #%d: NO\n", tt);
	}

    return 0;
}