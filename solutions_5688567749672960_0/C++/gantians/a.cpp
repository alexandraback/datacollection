#include <bits/stdc++.h>
using namespace std;

map<long long,long long> g;

long long n;

long long work(long long x){
	long long ans = 0;
	while (x){
		ans=ans*10+x%10;
		x/=10;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		scanf("%lld",&n);
		printf("Case #%d: ",ti);
		g.clear();
		g[1]=1;
		queue<long long> q;
		q.push(1);
		while (!q.empty()){
			long long now = q.front();
						q.pop();
			if (now==n) break;
			if (g.find(now+1)==g.end()){
				g[now+1]=g[now]+1;
				q.push(now+1);
			}
			long long re = work(now);
			if (g.find(re)==g.end()){
				g[re]=g[now]+1;
				q.push(re);
			}
		//	cout << now<<" "<<re<<endl;

		}
		printf("%lld\n",g[n]);
	}
	return 0;
}
