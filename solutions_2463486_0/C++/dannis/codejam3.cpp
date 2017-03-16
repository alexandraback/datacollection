#include <stdio.h>
#define  N 105

int sqrt(int n,int flag) {
	//flag=1:lowerbound,flag=0:upperbound;
	int i=0;
	while (i*i<n)
		i++;
	if (i*i==n||!flag)
		return i;
	return --i;
}

int ispaline(int n){
	int a[N],i=0,len;
	while (n>0) {
		a[i++]=n%10;
		n/=10;
	}
	len=i;
	for (i=0;i<len-i;i++)
		if (a[i]!=a[len-1-i])
			return 0;
	return 1;
}
int main(){
	freopen("d:\\c\\C-small-attempt0.in","r",stdin);
	freopen("d:\\c\\C-small-attempt0.out","w",stdout);
	int t,x,i,a,b,num;
	scanf("%d",&t);
	for (x=1;x<=t;x++){
		scanf("%d%d",&a,&b);
		a=sqrt(a,0);
		b=sqrt(b,1);
		for (num=0,i=a;i<=b;i++)
			if (ispaline(i)&&ispaline(i*i))
				num++;
		printf("Case #%d: %d",x,num);
		if (x<t)
			printf("\n");
	}
	//while (1);
	return 0;
}

	

