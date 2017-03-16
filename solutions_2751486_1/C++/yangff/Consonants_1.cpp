#include <cstdio>
#include <cstring>
#include <cstdlib>
char str[1000010];
int less[1000010];
int block[1000010];
bool fuyin(char ch){
	return !(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') ;
}
void work(){
	int n;
	scanf("%s %d",str+0,&n);
	int ans = 0;
	int len = strlen(str);block[len] = 0;block[len-1] = 0;
	for (int i = len-1; i>=0 ;i--){
		if (fuyin(str[i]))
			block[i] = block[i+1]+(fuyin(str[i]));
		else
			block[i] = 0;
	}
	less[len] = 0x3fffffff;
	for (int i = len-1; i>=0 ;i--){
		if (block[i]>=n) less[i] = i+n-1;
		else
			less[i] = less[i+1];
	}
	for (int l = 0; l< len; l++){
		// printf("%d ",block[l]);
		if (less[l]!=0x3fffffff)
			ans += len-less[l];
	}
	printf("%d",ans);
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;scanf("%d",&T);
	for (int i = 1; i <= T; i++){
		printf("Case #%d: ",i);
		work();
		printf("\n");
	}
}