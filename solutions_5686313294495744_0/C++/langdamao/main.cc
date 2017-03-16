#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

long long ans1,ans2;
int l;
char str1[100],str2[100];
void print(long long x){
	long long ret=x;
	int k=0;
	while(x){
		k++;
		x/=10;
	}
	if(k==0) k=1;
	for (int i=k;i<l;i++) printf("0");
	printf("%lld",ret);
}
bool shu(char ch){
	if(ch>='0'&&ch<='9') return true;
	return false;
}
long long findabs(long long x,long long y){
	if(x>y) return x-y;
	return y-x;
}
void get(long long x,long long y,int m){
	long long r1=x,r2=y;
	for (int i=m;i<l;i++){
		if(x>y){
			if(str1[i]=='?') r1=r1*10;
			else r1=r1*10+str1[i]-'0';
			if(str2[i]=='?') r2=r2*10+9;
			else r2=r2*10+str2[i]-'0';
		}
		else {
			if(str1[i]=='?') r1=r1*10+9;
			else r1=r1*10+str1[i]-'0';
			if(str2[i]=='?') r2=r2*10;
			else r2=r2*10+str2[i]-'0';
		}
		//cout<<i<<' '<<r1<<' '<<r2<<endl;
	}
	if(ans1==-1&&ans2==-1){
		ans1=r1;
		ans2=r2;
	}
	else if(findabs(r1,r2)<findabs(ans1,ans2)){
		ans1=r1;ans2=r2;
	}
	else if(findabs(r1,r2)==findabs(ans1,ans2)){
		if(r1<ans1) {
			ans1=r1;
			ans2=r2;
		}
		else if(r1==ans1&&r2<ans2){
			ans1=r1;
			ans2=r2;
		}
	}
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s %s",str1,str2);
		int got=-1;
		l=strlen(str1);
		ans1=-1;ans2=-1;
		long long now=0;
		for (int i=0;i<l;i++){
			if(shu(str1[i])&&shu(str2[i])&&str1[i]!=str2[i]) {
				got=i;
			}
			if(str1[i]=='?'&&str2[i]=='?'){
				get(now*10+1,now*10+0,i+1);
				get(now*10+0,now*10+1,i+1);
				now=now*10;
			}
			else {
				if(str2[i]=='?'){
					if(str1[i]!='9') get(now*10+str1[i]-'0',now*10+str1[i]-'0'+1,i+1);
					if(str1[i]!='0') get(now*10+str1[i]-'0',now*10+str1[i]-'0'-1,i+1);
					now=now*10+str1[i]-'0';
				}
				else if(str1[i]=='?'){
					if(str2[i]!='9') get(now*10+str2[i]-'0'+1,now*10+str2[i]-'0',i+1);
					if(str2[i]!='0') get(now*10+str2[i]-'0'-1,now*10+str2[i]-'0',i+1);

					now=now*10+str2[i]-'0';
				}
				else {
					get(now*10+str1[i]-'0',now*10+str2[i]-'0',i+1);
					now=now*10+str1[i]-'0';
				}
			}
			if(got!=-1) break;
		}
		if(got==-1) {
			ans1=ans2=now;
		}
		printf("Case #%d: ",ca++);
		print(ans1);
		printf(" ");
		print(ans2);
		printf("\n");
	}
	return 0;
}
