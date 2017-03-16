#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define re(i,n) for(int i=0;i<n;i++)
#define re1(i,n) for(int i=1;i<=n;i++)
#define re2(i,n) for(int i=0;i<=n;i++)
#define re3(i,n) for(int i=1;i<n;i++)
#define clr(a,n) memset(a,n,sizeof(a))
#define debug(n) cout<<#n<<"="<<n<<endl
int flag[2000005];
int num[30];
void OP(int mask){
	int i=0;
	while(mask){
		if(mask&1) cout<<num[i]<<" ";
		mask >>=1; i++;
	}
	puts("");
}
int main(){
	int t; cin >> t;
	re1(oo,t){
		clr(flag,0);
		int n; cin>>n; int mask = 1 << n;
		re(i,n) cin >>num[i];
		printf("Case #%d:\n",oo);
		re(i,mask){
			int p= i,j=0,sum=0;
			while(p){
				if(p&1) sum+=num[j];
				j++;p>>=1;
			}
			if(flag[sum]) {OP(flag[sum]); OP(i); break;}
			else flag[sum] =i;
		}
	}
}

