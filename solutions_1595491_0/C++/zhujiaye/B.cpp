#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int test,N,S,p;

int main(){
	freopen("i.txt","r",stdin);
	scanf("%d",&test);
	int cnt=1;
	for (;test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d%d%d",&N,&S,&p);
		int tot=0,res=0;
		int a,b;
		if (p==1){
			a=1;
			b=-1;
		}
		else{
			a=3*p-4;
			b=3*p-3;
		}
		for (int i=1;i<=N;i++){
			int x;
			scanf("%d",&x);
			if (x<a) continue;
			if (x<=b) tot++;
			res++;
		}
		if (tot<S) tot=S;
		printf("%d\n",res-(tot-S));
	}
	return 0;
}
