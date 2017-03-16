#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

LL daan[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,13,14,15,16,17,18,19,20,21,22,14,15,16,17,18,19,20,21,22,23,15,16,17,18,19,20,21,22,23,24,16,17,18,19,20,21,22,23,24,25,17,18,19,20,21,22,23,24,25,26,18,19,20,21,22,23,24,25,26,27,19,20,21,22,23,24,25,26,27,28,20,21,22,23,24,25,26,27,28,29};

char s[20];

int main()
{
	int t,cas=0;
	cin>>t;
	while(cas++ < t){
		LL n;
		cin>>n;
		LL ans=0;
		while(n>100){
			LL temp=1,res=0;
			while(temp<n)temp*=10;
			if(temp==n){--n;++ans;continue;}
			int tot=0;
			LL d=n;
			while(d){
				s[tot++]=d%10;
				d/=10;
			}
			temp=0;
			for(int i=tot-tot/2-1;i>=0;--i){
				temp=temp*10+s[i];
			}
			ans+=temp;
			if(!temp){--n;++ans;continue;}
			temp=0;
			for(int i=tot/2-1;i>=0;--i){
				temp=temp*10+s[tot-1-i];
			}
			if(temp>1)ans+=temp;
			temp=1;
			while(temp*10<n)temp*=10;
			n=temp;
//			temp/=10;
//			if(temp*2>n)--ans;
//			temp=1;
//			while(temp*temp<n)temp*=10;
//			if(n%temp)ans+=n%temp;
//			else {--n;++ans;continue;}
//			LL d=n;
//			d=d/temp;
//			while(d){
//				res=res*10+d%10;
//				d/=10;
//			}
//			ans+=res;
//			d=1;
//			while(d*10<n)d*=10;
//			n=d;
		}
		ans+=daan[n];
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}

