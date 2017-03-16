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
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define pii pair<int, int>
using namespace std;
const int N = int(1e4);
int n,T,ans,cnt,cur;
char s[N];      

int main () {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d\n",&n);
		scanf("%s",s);
		ans = 0,cnt = 0;
		for(int i=0;i<=n;i++) if(s[i] != '0'){
			cur = s[i] - '0';
			if(cnt >= i) {
				cnt += cur;
				continue;
			}
			ans += (i - cnt);
			cnt += cur + i - cnt;
		}
		printf("Case #%d: %d\n",t,ans);     
	}
return 0;      
}