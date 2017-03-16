#include <bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d", &x)
#define boost ios_base::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define f first
#define s second

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 3010;

int f[maxn], n, rmask, rsize;

int solve(int mask, int csize, vector<int> &temp)
{
	int i, l, r, ret = 0, val;
	//cout << mask << " " << rmask << " " << csize << "\n";
	//for(auto it:temp)
	//	cout << it << " ";
	//cout << "\n";
	if(mask==rmask){
		if(csize>1){
			l = csize-1;
			r = 1;
			if(f[temp[0]]!=temp[l] && f[temp[0]]!=temp[r])
				return 0;
			r = 0;
			l = csize-2;
			if(f[temp[csize-1]]!=temp[l] && f[temp[csize-1]]!=temp[r])
				return 0;
			return csize;
		}
		else
			return csize;
	}
	if(temp.empty()){
		for(i=0; i<n; i++){
			if(!(rmask&(1<<i)))
				continue;
			if(mask&(1<<i))
				continue;
			temp.pb(i+1);
			ret = max(ret, solve(mask|(1<<i), 1, temp));
			temp.pop_back();
		}
	}
	else{
		val = f[temp[csize-1]];
		if(!rmask&(1<<(val-1)))
			return 0;
		if(mask&(1<<(val-1))){
			if(temp[csize-2]!=val)
				return 0;
			for(i=0; i<n; i++){
				if(!(rmask&(1<<i)))
					continue;
				if(mask&(1<<i))
					continue;
				temp.pb(i+1);
				ret = max(ret, solve(mask|(1<<i), csize+1, temp));
				temp.pop_back();
			}
		}
		else{
			temp.pb(val);
			ret = max(ret, solve(mask|(1<<(val-1)), csize+1, temp));
			temp.pop_back();
		}
	}
	return ret;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int t, cn = 1, i, ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=1; i<=n; i++)
			scanf("%d", &f[i]);
		vector<int> temp;
		ans = 0;
		for(i=0; i<(1<<n); i++){
			rmask = i;
			temp.clear();
			rsize = __builtin_popcount(rmask);
			ans = max(ans, solve(0, 0, temp));
		}
		printf("Case #%d: %d\n", cn++, ans);
	}
	
	return 0;
}
