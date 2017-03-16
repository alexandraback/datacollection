#include <cstdio>
#include <cstdlib>
#include <cstring>
char str[1000010];
int off[1000010];
int ans = 0;
int n;
void work(int xx){
	scanf("%s %d",str+0,&n);int len = strlen(str);off[len-1]=0;off[len]=0;ans = 0;
	int f = 0;
	for (int j = 0; j< len; j++){
		for (int k = j; k < len ;k++){
			f = 0;
			for (int i = j;i<=k && f<n;i++)
				if (!(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'))
				{
					f++;
				}else f=0;
			if (f>=n) {ans++;}
		}
	}
	printf("Case #%d: %d\n",xx,ans);
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);

	int T;scanf("%d",&T);
	for (int i = 1;i<=T; i++) work(i);
}