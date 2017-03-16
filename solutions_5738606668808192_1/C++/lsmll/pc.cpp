#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int lim=1000;
int b[51],a[611][51],now,i,j,k,n,m,p[110001],q[21];
int work(int x){
	int i,j,k,tmp;
	for (i=1;i<=lim;i++){
		for (k=0,j=n,tmp=1;j;j--,tmp=tmp*x%p[i])
		 if (b[j]) k=(k+tmp)%p[i];
		if (!k) return p[i];
	}
	return -1;
}
bool sequ(int *a,int *b){
	int i;
	for (i=1;i<=n;i++)
	 if (a[i]!=b[i]) return 0;
	return 1;
}
int main(){
	n=32;m=500;
	srand(677643971);
	for (i=2,p[0]=0;p[0]<lim;i++){
		for (j=1,k=1;j<=p[0]&&p[j]*p[j]<=i;j++)
		 if (i%p[j]==0){
		 	k=0;break;
		 }
		if (k) p[++p[0]]=i;
	}
	puts("Case #1:");
	for (now=0;now<m;){
		b[1]=b[n]=k=1;
		for (i=2;i<n;i++) b[i]=rand()%2;
		for (i=1;i<=now;i++)
		 if (sequ(a[i],b)) continue;
		for (i=2;i<=10;i++){
			q[i]=work(i);
			if (q[i]==-1){
				k=0;break;
			}
		}
		if (!k) continue;
		now++;
		for (i=1;i<=n;i++) printf("%d",a[now][i]=b[i]);
		for (i=2;i<=10;i++) printf(" %d",q[i]);
		puts("");
		fprintf(stderr,"%d\n",now);
	}
	return 0;
}
