#include <bits/stdc++.h>
using namespace std;
char a[100],b[100];
int base[100];
int ans1,ans2;
int abb(int x)
{
	if (x>0) return x;
	return -x;
}
void better(int a1,int a2){
	if (abb(a1-a2)<abb(ans1-ans2)) {ans1=a1;ans2=a2;return;}
	if (abb(a1-a2)==abb(ans1-ans2)&&a1<ans1) {ans1=a1;ans2=a2;return;}
	if (abb(a1-a2)==abb(ans1-ans2)&&a1==ans1&&a2<ans2) {ans1=a1;ans2=a2;return;}
}
int n;
int check(int x,int y){
	for (int i=0;i<n;i++) if (a[i]!='?'&&(x/base[n-i]%10)!=a[i]-'0') return 0;
	for (int i=0;i<n;i++) if (b[i]!='?'&&(y/base[n-i]%10)!=b[i]-'0') return 0;
	return 1;
}
int main()
{

	freopen("inb.txt","r",stdin);
	freopen("outb.txt","w",stdout);
	int T,ca=0,l,r;
	base[3]=100;
	base[2]=10;
	base[1]=1;
	scanf("%d",&T);
	while(T--){
		ans1=0;
		ans2=9;
		scanf("%s%s",a,b);
		n=strlen(a);
		for (int i=1;i<n;i++)
			ans2=ans2*10+9;
		l=0;
		r=ans2;
		for (int i=0;i<=r;i++)
			for (int j=0;j<=r;j++)
				if (check(i,j)) better(i,j);
		printf("Case #%d: ", ++ca);
		for (int i=n;i;i--)
			printf("%d", ans1/base[i]%10);
		printf(" ");
		for (int i=n;i;i--)
			printf("%d", ans2/base[i]%10);
		puts("");
		
	}
}