#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define FOR(i,n) for(int i=0;i<n;++i)

#include <unordered_set>

using namespace std;


int min(int a,int b) {
	return a<b?a:b;
}

int reverse(int x) {
	int ans=0;
	while(x) {
		ans*=10;
		ans+=x%10;
		x/=10;
	}
	return ans;
}

int main(void) {
	int pole[1000100];
	FOR(i,1000100) pole[i]=0;
	queue<int> q;
	pole[1]=1;
	q.push(1);
	while(!q.empty()) {
		int z = q.front();
		q.pop();
		int a = z+1;
		int b = reverse(z);
		if(a < 1000100 && pole[a]==0) {
			pole[a] = pole[z]+1;
			q.push(a);
		}
		if(b < 1000100 && pole[b]==0) {
			pole[b] = pole[z]+1;
			q.push(b);
		}
	}
	int t;
	scanf("%d",&t);
	FOR(k,t) {
		int n;
		scanf("%d",&n);
		printf("Case #%d: %d\n",k+1,pole[n]);
	}
}