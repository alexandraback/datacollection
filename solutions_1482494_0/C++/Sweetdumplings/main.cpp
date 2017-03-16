#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1002
int n;
struct Data_t{
	int star,level,os;
}a[MAXN],b[MAXN];
bool cmp(Data_t a,Data_t b){
	if (a.star!=b.star) return a.star<b.star;
	return a.os>b.os;

}
bool clicked[MAXN];
void Main(){
	memset(clicked,0,sizeof(clicked));
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&a[i].star,&b[i].star);
		a[i].level=b[i].level=i;
		a[i].os=b[i].star;
	}
	std::sort(a+1,a+n+1,cmp);
	int at=1;
	int ans=0,finish=0,nowstar=0;
	while (finish<n){
		bool foundb=0;int couldget=0,mint=0;
		for (int i=1;i<=n;++i){
			if (b[i].star<=nowstar){
				foundb=1;
				if (clicked[b[i].level]){
					if (couldget==0) {
						mint=i;
						couldget=1;
					}
				}else {
					mint=i;
					couldget=2;
					break;
				}
			}
		}
		if (foundb){
			nowstar+=couldget;
			finish++;
			b[mint].star=10000000;
			clicked[b[mint].level]=1;
			ans++;
		}else {
			while ((clicked[a[at].level])&&(at<=n)) at++;
			if (a[at].star>nowstar){
				printf("Too Bad\n");
				return ;
			}else {
				clicked[a[at].level]=1;
				at++;
				nowstar++;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;++i){
		printf("Case #%d: ",i);
		Main();
	}
	return 0;
}
