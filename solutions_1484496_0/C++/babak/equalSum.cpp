/// In The Name Of God

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>


using namespace std;

#define REP(i,n) for((i)=0;(i)<(n);(i)++)
typedef long long ll;

const int maxn=(1<<20)+20;

struct node{
	int sum,ind;
}a[maxn];
int num[32];

bool func(node n,node p){
	return n.sum<p.sum || (n.sum==p.sum && n.ind<p.ind);
}

int main(){
	ios::sync_with_stdio(false);
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n,t,tsc,i,mask,sum,j;
	cin>>tsc;
	REP(t,tsc){
		cin>>n;
		REP(i,n)
			cin>>num[i];
		for(mask=1;mask<(1<<n);mask++){
			a[mask].ind=mask;
			a[mask].sum=0;
			REP(i,n)if((1<<i)& mask)
				a[mask].sum+=num[i];
		}
		sort(a,a+(1<<n),func);
		int ans1=-1,ans2=-1;
		bool flag=false;
		REP(i,(1<<n)){
			j=1;
			while(a[j+i].sum==a[i].sum){
				if((a[i+j].ind)^(a[i].ind)==0){
					ans1=a[i].ind;
					ans2=a[i+j].ind;
					flag=true;
					break;
				}
			}
			if(flag)break;
		}
		cout<<"Case #"<<t+1<<":"<<endl;
		if(!flag)
			cout<<"Impossible"<<endl;
		else{
			REP(i,n)if((1<<i)&ans1)
				cout<<num[i]<<" ";
			cout<<endl;
			REP(i,n)if((1<<i)&ans2)
				cout<<num[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}