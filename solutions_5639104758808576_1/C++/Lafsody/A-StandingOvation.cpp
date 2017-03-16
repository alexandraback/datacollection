#include<stdio.h>
#include<algorithm>

using namespace std;

int T,smax,co,add;
char c[2000];

int main(){
	int i,j;
	freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	for(int t = 1; t <= T;t++){
		scanf("%d",&smax);
		scanf("%s",c);
		co = 0;
		add = 0;
		for(i = 0; i <= smax; i++){
			if(co < i){
				add += i - co;
				co += i - co;
			}
			co += c[i] - '0';
		}
		printf("Case #%d: %d\n",t,add);
	}
}
