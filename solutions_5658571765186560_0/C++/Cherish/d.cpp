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

int main()
{
	int t,cas=0;
	cin>>t;
	while(cas++ < t){
		int x, r, c;
		cin >> x >> r >> c;
		printf("Case #%d: ", cas);
		if(x <= 6 && r*c%x == 0) {
			//if(x<=2||2<x<=4&&c>=x-1&&r>=x-1||4<x<=6&&c>=4&&r>=4)
			if(x<=4&&c>=x-1&&r>=x-1||c>=4&&r>=4)
				puts("GABRIEL");
			else puts("RICHARD");
		}
		else puts("RICHARD");
	}
	return 0;
}

