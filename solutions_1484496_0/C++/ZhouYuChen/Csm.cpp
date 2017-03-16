#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int x[32],n,s;
void out(int xx){
	for(int i=0;i<n;++i)if(xx>>i&1)printf("%d ",x[i]);
	puts("");
}
void solve(){
	map<int,int> sum;
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",x+i);
	for(int k=0;k<1<<n;++k){
		for(int i=s=0;i<n;++i)s+=((k>>i&1)?x[i]:0);
		if(sum.count(s)){
			out(k&~sum[s]);
			out(~k&sum[s]);
			return ;
		}else sum.insert(make_pair(s,k));
	}
}
int main(){
	int T,ti;
	for(scanf("%d",&T),ti=1;ti<=T;++ti){
		printf("Case #%d:\n",ti);
		solve();
	}
}