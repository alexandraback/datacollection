#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn (25)
using namespace std;

struct Tnode{
	int x,y;
}A[1<<20];

int test,n,m,a[maxn];

bool cmp(Tnode a,Tnode b){
	return a.x<b.x;
}
void Print(int x){
	for (int i=0;i<n;i++) if (x&(1<<i)) printf("%d ",a[i]);
	puts("");
}
int main(){
	freopen("i.txt","r",stdin);
	int cnt=1;
	for (scanf("%d",&test);test--;cnt++){
		printf("Case #%d:\n",cnt);
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		m=0;
		for (int i=1;i<1<<n;i++){
			int tot=0;
			for (int j=0;j<n;j++) if (i&(1<<j)) tot+=a[j];
			m++;
			A[m].x=tot;
			A[m].y=i;
		}
		sort(A+1,A+m+1,cmp);
		for (int i=1;i<m;i++) if (A[i].x==A[i+1].x){
			Print(A[i].y);
			Print(A[i+1].y);
			break;
		}
	}
	return 0;
}
