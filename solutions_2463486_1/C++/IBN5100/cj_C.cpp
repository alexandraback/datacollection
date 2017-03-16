#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef unsigned long long ll;
ll limit=10000000;
ll num[1000];
int sum=0;
int tmp[100];
int top;
bool judge(ll x){
	top=0;
	while(x){
		tmp[top++]=x%10;
		x/=10;
	}
	for(int i=0,j=top-1;i<top;i++,j--){
		if(tmp[i]!=tmp[j])return false;
	}
	return true;
}
int main(){
	num[sum++]=1;
	for(ll i=2;i<=limit;i++){
		if(judge(i)&&judge(i*i)){
			num[sum++]=i*i;
			//printf("%lld\n",num[sum-1]);
		}
	}
	int T,ct=1;
	//freopen("C-large-1.in","r",stdin);
	//freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		printf("Case #%d: ",ct++);
		ll l,r;
		scanf("%lld%lld",&l,&r);
		int l_num=0,r_num=0;
		while(num[l_num]<l)l_num++;
		while(num[r_num]>0&&num[r_num]<=r)r_num++;
		printf("%d\n",r_num-l_num);
	}
}
