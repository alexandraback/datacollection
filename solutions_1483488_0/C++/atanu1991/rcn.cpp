#include<iostream>
#include<stdio.h>
using namespace std;
bool isRecycle(int n,int m,int nod){
	if(nod==2){
		int newnum=10*(n%10)+n/10;
		if(newnum==m) return true;
		return false;
	}
	if(nod==3){
		int newnum1=100*(n%10)+(n/10);
		int newnum2=10*(n%100)+n/100;
		if(newnum1==m||newnum2==m) return true;
		return false;
	}
}
int main(){
int T;
cin>>T;
int tc;
for(tc=1;tc<=T;tc++){
	int a,b,nod=0;
	cin>>a>>b;
	int ans=0;
	if(a<=9||a>=1000)
		printf("Case #%d: 0\n",tc);
	else
	{
		int i,j;
		if(a<=99) nod=2;
		else nod =3;
		for(i=a;i<=b;i++){
			for(j=i+1;j<=b;j++){
				if(isRecycle(i,j,nod))
					ans++;
			}	
		}
		printf("Case #%d: %d\n",tc,ans);
	}
}
return 0;
}
