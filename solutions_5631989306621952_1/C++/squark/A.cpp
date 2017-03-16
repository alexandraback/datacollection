#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

char s[3000];
char t[3000];

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		printf("Case #%d:", i0);
		int n;
		int i, j, k;
		int l, r;
		l = r = 1500;
		scanf("%s", t);
		n = strlen(t);
		for(i = 0; i < n; i++){
			if(t[i] >= s[l]){
				s[--l] = t[i];
			}
			else{
				s[r++] = t[i];
			}
		}
		s[r] = '\0';
		printf(" %s\n", s+l);
	}
	return 0;
}
