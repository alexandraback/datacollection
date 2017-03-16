#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

char s[1100];

int main()
{
	int t,cas=0;
	cin>>t;
	while(cas++ < t){
		int n;
		cin>>n>>s;
		int tot=s[0]-'0', ans=0;
		Rep(i,n) {
			ans = max(i-tot, ans);
			tot += s[i] - '0';
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

