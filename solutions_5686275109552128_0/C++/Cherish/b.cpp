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

struct data{
	int tot, num;
	double key;
	data(){}
	data(int tot, int num):tot(tot), num(num) {
		key = double(tot) / num;
	}
	bool operator < (const data& b) const {
		return key < b.key;
	}
};

int main()
{
	int t,cas=0;
	cin>>t;
	while(cas++<t){
		priority_queue<data>q;
		int n,x;
		scanf("%d",&n);
		rep(i,n) {
			scanf("%d",&x);
			q.push(data(x,1));
		}
		int ans=INF;
		rep(i,ans) {
			data temp = q.top(); q.pop();
			ans = min(i+(int)ceil(temp.key), ans);
			q.push(data(temp.tot, temp.num+1));
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

