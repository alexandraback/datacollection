#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char str[15][105];
char ss[10050];
int a[15];
int p=0;
int count=0;
int n;
int flag[15];

bool can(){
	int l=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(str[a[i]]);j++){
			ss[l]=str[a[i]][j];
			l++;
		}
	}
	int f[26];
	for(int i=0;i<26;i++)f[i]=0;
	f[ss[0]-'a']=1;
	for(int i=1;i<l;i++){
		if(ss[i]!=ss[i-1]){
			if(f[ss[i]-'a']!=0)
				return false;
			else
				f[ss[i]-'a']=1;
		}
	}
	return true;
}

int main(){
	int tt;
	scanf("%d",&tt);
	for(int t=1;t<=tt;t++){
		
		count=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%s",str[i]);
	//	printf("OK\n");
		a[0]=-1;
		p=0;
		for(int i=0;i<15;i++)flag[i]=0;
		while(p>=0){
			a[p]++;
			//printf("%d %d\n",p,a[p]);
			if(a[p]>=n){
				p--;
				if(p>=0)flag[a[p]]=0;
			}
			else if(flag[a[p]]==0){
				flag[a[p]]=1;
				p++;
				if(p==n){
					if(can()){
						count++;
					}
					p--;
					flag[a[p]]=0;
				}else{
					a[p]=-1;
				}
			}
		}
		printf("Case #%d: %d\n",t,count);
	}
	return 0;
}