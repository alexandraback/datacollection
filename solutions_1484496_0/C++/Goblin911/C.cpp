#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int a[30],f[2000100],n;
bool v[30];

void init(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	memset(f,0,sizeof(f));
}

void solve(){
	for (int t=1;t<1001000;t++){
		int j=t,i=1,sum=0;
		while (j>0){
			if (j&1) sum+=a[i];
			i++;j>>=1;
		}
		if (f[sum]) {
			//cout<<sum<<endl;
			for (i=1,j=f[sum];j;j>>=1,i++) if (j&1) printf("%d ",a[i]);printf("\n");
			for (i=1,j=t;j;j>>=1,i++) if (j&1) printf("%d ",a[i]);printf("\n");
			return;
		} else f[sum]=t;
	}
	printf("Impossible\n");
}

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int t,T;cin>>T;
	for (t=1;t<=T;t++){
		init();
		printf("Case #%d:\n",t);
		solve();
	}
}