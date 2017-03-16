#include<stdio.h>
#include<string.h>
char s[1000001];
int r[1000001];
int t[1000001];
inline bool check(char x){
	return x=='a'||x=='e'||x=='i'||x=='o'||x=='u';
}
int main(){
	int i,j,k;
	int T,TN,n,m;
	long long ans;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		ans=0;
		scanf("%s%d",s,&m);
		n=strlen(s);
		for(i=0;i<n;i++){
			if(check(s[i])){
				r[i]=0;
				//continue;
			} else 
			r[i]=(i?r[i-1]:0)+1;
			if(r[i]>=m){
				t[i]=i-m+1;
			} else {
				t[i]=(i==0?99999999:t[i-1]);
			}
		//printf("%d, ",t[i]);
			if(t[i]!=99999999){
				ans+=t[i]+1;
			}
			//printf("%I64d ",ans);
		}
		
		printf("Case #%d: %I64d\n",T,ans);
	}
}
