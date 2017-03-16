#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 200000
typedef long long int LL;
#define VI vector<LL >
VI ans;
LL pal[MAX];
int palin(LL n){
	LL rem,x=0,n1=n;
	while(n>0){
		rem=n%10;
		x=x*10+rem;
		n=n/10;
	}
	if(n1==x)
		return 1;
	else
		return 0;
}

int main(){
LL l=0,i;
	for(i=1;i<=9;i++)
		pal[l++]=i;
	for(i=10;i<=10000000;i++)
		if(palin(i)){
			pal[l++]=i;
			i+=1;
		}

for(i=0;i<l;i++)pal[i]=pal[i]*pal[i];
LL s=0;
for(i=0;i<l;i++)if(palin(pal[i]))ans.push_back(pal[i]);
LL t,d=0;
scanf("%lld",&t);
	while(d++<t){
		printf("Case #%lld: ",d);
		LL a,b;
		scanf("%lld %lld",&a,&b);
		vector<LL>::iterator low,up;
		LL li,u;
		low =lower_bound(ans.begin(),ans.end(),a);li= low - ans.begin();
		up = upper_bound(ans.begin(),ans.end(),b);u= up - ans.begin();
		printf("%lld\n",u-li);
	}	
return 0;
}
