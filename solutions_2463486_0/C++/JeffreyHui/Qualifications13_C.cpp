#include <cstdio>
#include <algorithm>
using namespace std;
void f(long long val,long long s[],long long &total){
	bool YN=1;
	long long t[120],temp=val,i=0,j;
	while (temp){
		t[i]=temp%10;
		temp/=10;
		i++;
	}
	for (j=0;j<i/2;j++){
		if (t[j]!=t[i-1-j]){
			YN=0;
		}
	}
	temp=val*val;
	i=0;
	while (temp){
		t[i]=temp%10;
		temp/=10;
		i++;
	}
	for (j=0;j<i/2;j++){
		if (t[j]!=t[i-1-j]){
			YN=0;
		}
	}
	if (YN){
		s[total]=val;
		total++;
	}
	if (val<=10000000){
		f(val*10,s,total);
		f(val*10+1,s,total);
		f(val*10+2,s,total);
	}
}
int main (){
	long long T,A,B,total=1,cnt,s[1000],i,j,k;
	scanf("%I64d",&T);
	s[0]=3;
	for (i=1;i<=2;i++){
		f(i,s,total);
	}
	sort(s,s+total);
	for (i=1;i<=T;i++){
		scanf("%I64d %I64d",&A,&B);
		cnt=0;
		for (j=0;j<total;j++){
			if (s[j]*s[j]>=A && s[j]*s[j]<=B) cnt++;
		}
		printf("Case #%d: %I64d\n",i,cnt);
	}
	return 0;
}
