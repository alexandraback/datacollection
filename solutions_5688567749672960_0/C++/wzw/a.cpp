#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define LL long long
#define inf (1<<30)
using namespace std;

int a[22];

int c(LL x){
	LL xx=x;
	if (x<=10) return x;
	int l=0,cnt=0;
	while (x){
		a[l]=x%10;
		if (a[l]==0) cnt++;
		l++;
		x/=10;
	}
//	cout<<l<<endl;
//	for (int i=0;i<l;i++) cout<<a[i];
	if (cnt==l-1) return c(x-1)+1;
	int flag=1,sum=a[0];
	for (int i=1;i<l;i++){
		if (flag && a[i]==1){
			flag=0;
			continue;
		}
		sum+=a[i]+1;
	}
	if (flag) sum--;
	LL n=0;
	for (int i=1;i<l;i++) n=n*10+9;
	return c(n)+sum+1;
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	cin>>T;
	for (int _=1;_<=T;_++){
		LL n;
		cin>>n;
		printf("Case #%d: %d\n",_,c(n));
	}
}
