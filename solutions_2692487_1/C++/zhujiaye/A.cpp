#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn (105)
using namespace std;

int N,test,cnt,A,a[maxn];

int main(){
	freopen("i.txt","r",stdin);
	
	scanf("%d",&test);
	for (cnt=1;test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d%d",&A,&N);
		for (int i=0;i<N;i++) scanf("%d",&a[i]);
		sort(a,a+N);
		int res=-1;
		for (int lim=N;lim>=0;lim--){
			int tot=0,tmp=A;
			bool ok=true;
			for (int i=0;i<lim;i++){
				if (tmp>a[i]){
					tmp+=a[i];
					continue;
				}
				for (;tmp<=a[i] && tmp-1>0;tmp+=tmp-1,tot++);
				if (tmp>a[i])
					tmp+=a[i];
				else 
					ok=false;
			}
			if (ok && (res==-1 || res>tot+N-lim)) res=tot+N-lim;
		}
		printf("%d\n",res);
	}
	return 0;
}
