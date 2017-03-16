#include <cstdio>
#include <cmath>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn=101;
struct bigint{
	int num[maxn];
	int len;
};
bigint one;
bigint r;
bigint t;

void preprocess(){
	memset(one.num,0,sizeof(one.num));
	one.len=1;
	one.num[1]=1;
	return;
}

bool leq(bigint a,bigint b){
	if (a.len>b.len){
		return false;
	}
	if (a.len<b.len){
		return true;
	}
	for (int i=a.len;i>=1;i--){
		if (a.num[i]>b.num[i]){
			return false;
		}
		if (a.num[i]<b.num[i]){
			return true;
		}
	}
	return true;
}

bigint add(bigint a,bigint b){
	bigint ans;
	memset(ans.num,0,sizeof(ans.num));
	ans.len=max(a.len,b.len);
	for (int i=1;i<=ans.len;i++){
		ans.num[i]=a.num[i]+b.num[i];
	}
	for (int i=1;i<=ans.len;i++){
		ans.num[i+1]+=ans.num[i]/10;
		ans.num[i]%=10;
	}
	if (ans.num[ans.len+1]>0){
		ans.len++;
	}
	return ans;
}

void print(bigint a){
	for (int i=a.len;i>=1;i--){
		printf("%d",a.num[i]);
	}
	return;
}

bigint convert(char* str){
	bigint ans;
	memset(ans.num,0,sizeof(ans.num));
	ans.len=strlen(str);
	for (int i=0;i<ans.len;i++){
		ans.num[ans.len-i]=str[i]-'0';
	}
	return ans;
}

bigint square(bigint a){
	bigint ans;
	memset(ans.num,0,sizeof(ans.num));
	for (int i=1;i<=a.len;i++){
		for (int j=1;j<=a.len;j++){
			ans.num[i+j-1]+=a.num[i]*a.num[j];
		}
	}
	ans.len=a.len+a.len-1;
	for (int i=1;i<=ans.len;i++){
		ans.num[i+1]+=ans.num[i]/10;
		ans.num[i]%=10;
	}
	if (ans.num[ans.len+1]>0){
		ans.len++;
	}
	return ans;
}

bigint substract(bigint a,bigint b){
	bigint ans;
	memset(ans.num,0,sizeof(ans.num));
	for (int i=1;i<=max(a.len,b.len);i++){
		ans.num[i]=a.num[i]-b.num[i];
	}
	for (int i=1;i<=max(a.len,b.len);i++){
		if (ans.num[i]<0){
			ans.num[i]+=10;
			ans.num[i+1]--;
		}
	}
	for (int i=max(a.len,b.len);i>=1;i--){
		if (ans.num[i]==0){
			continue;
		}
		ans.len=i;
		break;
	}
	return ans;
}

void init(){
	char str[maxn];
	scanf("%s",str);
	r=convert(str);
	scanf("%s",str);
	t=convert(str);
	return;
}

void count(){
	bigint cur;
	cur.len=0;
	memset(cur.num,0,sizeof(cur.num));
	bigint ans;
	ans.len=0;
	memset(ans.num,0,sizeof(ans.num));
	bigint rad=r;
	while (true){
		bigint area1=square(rad);
		bigint rad1=add(rad,one);
		bigint area2=square(rad1);
		bigint area=substract(area2,area1);
		bigint tot=add(cur,area);
		if (!leq(tot,t)){
			print(ans);
			break;
		}
		cur=tot;
		rad=add(rad1,one);
		ans=add(ans,one);
	}
	return;
}

int main(){
	preprocess();
	int tcase;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		init();
		printf("Case #%d: ",i);
		count();
		puts("");
	}
	return 0;
}
