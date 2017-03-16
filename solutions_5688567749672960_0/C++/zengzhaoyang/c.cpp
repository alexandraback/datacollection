#include <bits/stdc++.h>
using namespace std;
long long rev(long long a){
	int b[100];
	int k=0;
	while(a){
		b[k++]=a%10;
		a/=10;
	}
	long long ans=0;
	for(int i=0;i<k;i++){
		ans=ans*10+b[i];
	}
	return ans;
}
struct node{
	long long num;
	long long step;
	node(long long a,long long b){
		num=a;
		step=b;
	}
};
long long ans[100];
set<int> s;
long long bfs(long long a){
	queue<node> q;
	//set<int> s;
	s.clear();
	q.push(node(1,1));
	while(!q.empty()){
		node temp=q.front();
		q.pop();
		if(temp.num==a)
			return temp.step;
		if(s.find(temp.num)!=s.end())
			continue;
		s.insert(temp.num);
		long long t1=temp.num+1;
		long long t2=rev(temp.num);
		if(s.find(t1)==s.end())
			q.push(node(t1,temp.step+1));
		if(s.find(t2)==s.end())
			q.push(node(t2,temp.step+1));
	}
}
int main(){
	//bfs(100);
	/*for(long long i=1;i<=100;i++){
		printf("%lld %lld\n",i,bfs(i));
	}*/
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--){
		long long n;
		scanf("%lld",&n);
		printf("Case #%d: %lld\n",++cas,bfs(n));
	}
}