#include<stdio.h>
#include<string.h>

long long f[1010];
char num[110];

bool is_palindrome(char str[]){
	int len=strlen(str);
	for(int i=0,j=len-1;i<=j;i++,j--){
		if(num[i]!=num[j])return false;
	}
	return true;
}

int init(){
	/*for(int i=0;i<1010;i++){
		f[i]=0;
	}*/
	int sum=0;
	for(int i=1;i<=10000000;i++){
		sprintf(num,"%d",i);
		if(!is_palindrome(num))continue;
		long long x=(long long)i*(long long)i;
		sprintf(num,"%lld",x);
		if(is_palindrome(num)){
			f[sum++]=x;
		}
	}
	return sum;
}

int main(){
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-1.out","w",stdout);
	int T;
	scanf("%d",&T);
	int n=init();
	for(int Case=1;Case<=T;Case++){
		long long a,b;
		scanf("%lld%lld",&a,&b);
		int ans=0;
		for(int i=0;i<n;i++){
			if(f[i]>=a&&f[i]<=b){
				++ans;
			}
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}