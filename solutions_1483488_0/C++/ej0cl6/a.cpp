#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 10010
using namespace std;
char ch[MAX];
int a,b;
int ANS;
void ini(){
	for(int i=0;i<MAX;i++)
		ch[i]=0;
	ANS=0;
}
int mul(int s){
	int ans=1;
	while((s/10)!=0){
		s/=10;
		ans*=10;
	}
	return ans;
}
int main(){
	int T;
	int ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		ini();
		for(int i=a;i<=b;i++){
			if(ch[i])
				continue;
			//printf("- %d\n",i);
			ch[i]=1;
			int m=mul(i);
			int tmpi=(i%10)*m+i/10;
			int ans=1;
			while(tmpi!=i){
				//printf("%d\n",tmpi);
				if(a<=tmpi && tmpi<=b && !ch[tmpi]){
					ch[tmpi]=1;
					ans++;
				}
				tmpi=(tmpi%10)*m+tmpi/10;
			}
			//printf("- %d %d\n",i,ans);
			ANS+=ans*(ans-1)/2;
		}
		printf("Case #%d: %d\n",ca++,ANS);
	}
	return 0;
}
