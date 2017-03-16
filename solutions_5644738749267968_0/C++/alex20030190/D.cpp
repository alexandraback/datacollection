#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int T,TI,n;
double A[1002],B[1002];
int main(){
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D1.out","w",stdout);
	scanf("%d",&T);
	for(int TI=1;TI<=T;TI++){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%lf",&A[i]);
		for(int i=0;i<n;i++) scanf("%lf",&B[i]);
		sort(A,A+n);
		sort(B,B+n);
		int s1=0,s2=0,x,y;
		x=n-1;
		for(int i=n-1;i>=0;i--){
			if(B[x]>A[i]) x--;
			else s2++;
		}
		y=0;
		for(int i=0;i<n;i++)
			if(A[i]>B[y]) s1++,y++;
		printf("Case #%d: %d %d\n",TI,s1,s2);
	}
	return 0;
}
