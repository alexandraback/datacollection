#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

int n,Left,Right,test,cnt,num[30];
LL P[1005];

bool isPalind(LL x){
	LL tmp=x;
	int L=0;
	for (;tmp;tmp/=10)
		num[L++]=tmp%10;
	for (int i=0;i<L/2;i++)
		if (num[i]!=num[L-1-i]) return false;
	return true;
}
void prepare(){
	n=0;
	for (int i=0;i<=10000000;i++){
		LL tmp=(LL)i*i;
		if (!isPalind(i)) continue;
		if (!isPalind(tmp)) continue;
	//	printf("%d %I64d\n",i,tmp);
		P[++n]=tmp;
	}
}
int calc(LL range){
	int res=0;
	for (int i=1;i<=n;i++) 
		if (P[i]<=range) res++;
	return res;
}
int main(){
	freopen("i.txt","r",stdin);
	scanf("%d",&test);
	cnt=1;
	prepare();
	for (;test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d%d",&Left,&Right);
		printf("%d\n",calc(Right)-calc(Left-1));
	}
	return 0;
}
