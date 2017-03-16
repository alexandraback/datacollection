#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int t;
long long n;
char s[101];
bool v[1001001];

int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		scanf("%lld",&n);
		printf("Case #%d: ",tt);
		queue<pair<int,long long>> q;
		q.push({1,1});
		memset(v,0,sizeof(v));
		while(q.size()){
			pair<int,long long> p=q.front();
			q.pop();
			if (v[p.second]) continue;
			v[p.second]=1;
			if (p.second==n){
				printf("%d\n",p.first);
				break;
			}
			q.push({p.first+1,p.second+1});
			sprintf(s,"%lld",p.second);
			reverse(s,s+strlen(s));
			long long x;
			sscanf(s,"%lld",&x);
			q.push({p.first+1,x});
		}
	}
	return 0;
}
