#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = 200, mod = int(1e9)  + 7;
int T;
char s[N];
int ans;
int j,n;

int main () {
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		scanf("%s\n",s+1);
		n = strlen(s+1);
		ans = 0;
		char last = s[1];
		ans = 1;
		for(int i=2;i<=n;i++){
			if(last != s[i]){
				last = s[i];
				ans++;
			}
		}
		if(s[n] == '+') ans--;
		printf("%d\n",ans);
	}

return 0;
}