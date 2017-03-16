#include "iostream"
#include "cstring"
#include "cstdio"
using namespace std;
int gao(int x)
{
	if(x==1||x==4||x==9||x==121||x==484) return 1;
	return 0;
}
int main(void)
{
	int T,g=0,x,y;
	freopen("C-small-attempt0.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",++g);
		int sum=0;
		for(int i=x;i<=y;i++){
			sum+=gao(i);
		}
		printf("%d\n",sum);
	}
	return 0;
}