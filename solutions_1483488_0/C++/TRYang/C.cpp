#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 30

using namespace std;

int a[maxn],an;
int ans;
int A,B;
int get(int x){
	int ret=0;
	while (x) ++ret,x/=10;
	return ret;
}
int shift(int x,int y){
	int ret=0;
	int c[10],cn=0;
//	printf("r:%d %d\n",x,y);
	while (x){
		c[cn++]=x%10;
		x/=10;
	}
	rotate(c,c+cn-y,c+cn);
	if (c[cn-1]==0) return -1;
	for (int i=cn-1;i>=0;i--) ret=ret*10+c[i];
//	printf("%d\n",ret);
	return ret;
}
int main(){
	int tn,cp;
	for (scanf("%d",&tn),cp=1;cp<=tn;cp++){
		scanf("%d%d",&A,&B);
		ans=0;
		for (int i=A;i<=B;i++){
			int k=get(i);
			an=0;
			for (int j=1;j<k;j++){
				int x=shift(i,j);
				if (x>=A && x<=B) a[an++]=x;
			}
			sort(a,a+an);
			an=unique(a,a+an)-a;
			for (int j=0;j<an;j++)
				if (a[j]<i && a[j]>-1) ++ans;
		}
		printf("Case #%d: %d\n",cp,ans);
	}
	return 0;
}
