#include <queue>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int n,x,a[105],mx;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int w,test;
	scanf("%d",&test);
	for(w=1;w<=test;w++){
		scanf("%d %d",&n,&x);
		mx=x;
		int i,now,cnt,t1,t2;
		for(i=0;i<x;i++){ scanf("%d",&a[i]); }
		sort(a,a+x);
		priority_queue<pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> > > q;
		q.push(make_pair(0,-n));
		for(;q.size();){
			cnt=q.top().first/100; 
			i=q.top().first%100;
			now=-q.top().second; 
			//printf("%d (%d) : %2d : %2d\n",cnt,i,now,a[i]);
			q.pop();
			if(i>x){ continue; }
			if(cnt>=mx){ continue; }
			if(cnt+x-i<mx){ mx=cnt+x-i; }
			if(now==1){ continue; }
			
			for(;;){
				if(cnt>=x){ break; }
				if(now>a[i]){ now+=a[i]; break; }
				now+=now-1;
				cnt++;
			}
			if(cnt>=x){ continue; }
			i++;
			if(cnt+x-i<mx){ mx=cnt+x-i; }
			q.push(make_pair(cnt * 100 + i, -now));
		}
		printf("Case #%d: %d\n",w,mx);
	}
	return 0;
}
