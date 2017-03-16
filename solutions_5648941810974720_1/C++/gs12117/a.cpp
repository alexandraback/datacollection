#include<stdio.h>
#include<string.h>
int tcn,tc;
int n;
char s[2010];
int a[30];
int r[12];
char p[12][12]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char f[12]="ZXURWSOFGE";
int d[12]={0,6,4,3,2,7,1,5,8,9};
int main(){
	int i,j;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%s",&s);
		n=strlen(s);
		for(i=0;i<26;i++){
			a[i]=0;
		}
		for(i=0;i<n;i++){
			a[s[i]-'A']++;
		}
		for(i=0;i<10;i++){
			r[i]=0;
		}
		for(i=0;i<10;i++){
			while(a[f[i]-'A']!=0){
				for(j=0;p[d[i]][j];j++){
					a[p[d[i]][j]-'A']--;
				}
				r[d[i]]++;
			}
		}
		printf("Case #%d: ",tc);
		for(i=0;i<10;i++){
			for(j=0;j<r[i];j++){
				printf("%d",i);
			}
		}
		printf("\n");
	}
	return 0;
}