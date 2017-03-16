#include <cstdio>
#include <cstring>

int a[1010],b[1010];
int use[1010];
int n;
int ans;

int main(){
	int test=0;
	scanf("%d",&test);
	for (int T=1;T<=test;++T){
		scanf("%d",&n);
		for (int i=0; i<n; ++i)
			scanf("%d%d",a+i,b+i);
		int now=0;
		ans=0;
		memset(use,0,sizeof(use));
		while (1){
			int flag=0;
			for (int j=0; j<n; ++j)
				if (use[j]!=2 && b[j]<=now){
					++ans;
					now+=2-use[j];
					use[j]=2;					
					flag=1;
				}
			if (flag==0){
				int mm=-1;
				for (int i=0; i<n; ++i)
					if (use[i]==0 && a[i]<=now && ( b[i]>b[mm] || mm==-1 ))
						mm=i;
				if (mm==-1) break;
				use[mm]=1;
				++now;
				++ans;
			}
		}
		//printf("%d\n" ,now);
		printf("Case #%d: ",T);
		if (now!=2*n)
			printf("Too Bad\n");
		else
			printf("%d\n", ans);
	}
}
