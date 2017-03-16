#include <cstdio>
#include <cstring>
//#define DEBUG

int arr[2000001];
int cnt[2000001];
int tenpow[]={1,10,100,1000,10000,100000,1000000,10000000};

int lexmin(int a){
	int maxpow=0;
	while(tenpow[maxpow]<a)maxpow++;
	maxpow--;
	int b=a;
	for(int i=0;i<maxpow;i++){
		b=tenpow[maxpow]*(b%10)+b/10;
		if(b<tenpow[maxpow])continue;
		if(b<a)a=b;
	}
	return a;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cases,n,a,b,i;
	for(int i=1;i<=2000000;i++)arr[i]=lexmin(i);
	scanf("%d",&cases);
	for(int casenum=1;casenum<=cases;casenum++){
		scanf("%d%d",&a,&b);
#ifdef DEBUG
		for(i=a;i<=b;i++)printf("%d %d\n",i,arr[i]);
#endif
		int ans=0;
		memset(cnt,0,sizeof(cnt));
		for(i=a;i<=b;i++){
			int t=arr[i];
			ans+=cnt[t];
			cnt[t]++;
		}
		printf("Case #%d: %d\n",casenum,ans);
	}
	return 0;
}