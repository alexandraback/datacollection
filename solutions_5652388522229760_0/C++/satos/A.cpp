#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)


int main(void){
	int qn;
	scanf("%d",&qn);
	reg(qqq,1,qn){
		printf("Case #%d: ",qqq);
		lli n;
		scanf("%lld",&n);
		if(n==0){
			puts("INSOMNIA");
			continue;
		}
		int c[10]={};
		reg(i,1,100000){
			lli p = n*i;
			while(p>0){
				c[p%10]=1; p/=10;
			}
			int s = 0;
			rep(j,10)s+=c[j];
			if(s==10){
				printf("%lld\n",n*i);
				break;
			}
		}
	}		
	return 0;
}




