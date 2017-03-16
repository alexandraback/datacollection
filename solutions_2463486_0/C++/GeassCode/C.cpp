#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
int f[20];
int getnb(int x)
{
	int y=0;
	while(x){
		y=y*10+x%10;
		x/=10;
	}
	return y;
}
int getlen(int x)
{
	int tmp=0;
	while(x){
		tmp++;
		x/=10;
	}
	return tmp;
}
int check(LL x)
{
	LL now=0;
	LL y=x;
	while(x){
		now=now*10+x%10;
		x/=10;
	}
	if(now==y)return 1;
	return 0;
}
LL cal(LL n)
{
	int len=getlen((int)sqrt(n*1.0));
	int i,j,kk;
	LL res=0;
	for(i=2;i<=len;i+=2){
		for(j=f[i/2-1];j<f[i/2];j++){
			LL k=j*f[i/2]+getnb(j);
			if(k*k<=n&&check(k*k)){
			//	cout<<n<<" "<<k<<endl;
				res++;
			}
		}
	}
	for(i=1;i<=len;i+=2){
		if(i==1){
			for(j=1;j<10;j++){
				if(j*j<=n&&check(j*j)){
				//	cout<<n<<" "<<j<<endl;
					res++;
				}
			}
			continue;
		}
		for(j=f[(i-1)/2-1];j<f[(i-1)/2];j++){
			for(kk=0;kk<10;kk++){
				LL k=j*f[(i-1)/2+1]+kk*f[(i-1)/2]+getnb(j);
				if(k*k<=n&&check(k*k)){
				//	cout<<n<<" "<<k<<endl;
					res++;
				}
			}
		}
	}
	return res;
}
LL Cal(LL n)
{
	int i;
	int cnt=0;
	for(i=1;i*i<=n;i++){
		if(check(i)&&check(i*i))cnt++;
	}
	return cnt;
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int i,j,k;
	int t,cas;
	LL L,R;
	f[0]=1;
	for(i=1;i<20;i++){
		f[i]=f[i-1]*10;
	}
/*	for(i=98;i<=111;i++){
		printf("%d %d\n",i,getnb(i));
	}*/
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		cin>>L>>R;
	//	cout<<cal(L-1)<<" "<<cal(R)<<endl;
	//	cout<<Cal(L-1)<<" "<<Cal(R)<<endl;
		printf("Case #%d: ",cas);
		cout<<cal(R)-cal(L-1)<<endl;
		//cout<<Cal(R)-Cal(L-1)<<endl;
	}
	return 0;
}
