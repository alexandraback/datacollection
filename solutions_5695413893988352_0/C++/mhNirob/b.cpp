#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<sstream>
#include<utility>
#include<climits>
#include<fstream>
#include<bitset>

using namespace std;

#define lli long long int
#define max 1000005

char C[32],J[32],TC[32],TJ[32];
lli lc,ls,MIN,ans1,ans2;

lli Pow(lli p){
	lli ans=1;
	for(lli i=1;i<=p;i++){
		ans*=10;
	}
	return ans;
}

void func(lli fi,lli si,lli fn,lli sn){
	if(fi==lc && si==ls){
		if(abs(fn-sn)<MIN){
			MIN = abs(fn-sn);
			ans1 = fn;
			ans2 = sn;
		}
		else if(abs(fn-sn)==MIN && fn<ans1){
			ans1 = fn;
			ans2 = sn;
		}
		return;
	}
	lli i,j;
	if(fi<lc){
		if(C[fi]=='?'){
			for(i=0;i<10;i++){
				func(fi+1,si,fn+Pow(lc-fi-1)*i,sn);
			}
		}
		else{
			func(fi+1,si,fn+Pow(lc-fi-1)*(C[fi]-'0'),sn);
		}
		//fi++;
	}

	if(si<ls){
		if(J[si]=='?'){
			for(i=0;i<10;i++){
				func(fi,si+1,fn,sn+Pow(ls-si-1)*i);
			}
		}
		else{
			
			func(fi,si+1,fn,sn+Pow(ls-si-1)*(J[si]-'0'));
		}
		//si++;
	}
}

int main()
{
	freopen("input","r",stdin);
	freopen("output","w",stdout);

	lli n,t,i,j,k,kase,len,l1,l2,t1,t2;

	scanf("%lld",&kase);

	for(i=1;i<=kase;i++){
		scanf("%s %s",C,J);
		lc = strlen(C);
		ls = strlen(J);
		MIN = 100000;
		func(0,0,0,0);
		t1=ans1;
		t2=ans2;
		l1=l2=0;
		while(t1){
			t1/=10;
			l1++;
		}

		while(t2){
			t2/=10;
			l2++;
		}
		printf("Case #%lld: ",i);
		for(j=1;j<=lc-l1;j++){
			printf("0");
		}
		if(ans1!=0)
		printf("%lld ",ans1);
		else{
			printf(" ");
		}

		for(j=1;j<=ls-l2;j++){
			printf("0");
		}

	    if(ans2!=0)
		printf("%lld",ans2);

		printf("\n");
	}
	return 0;
}