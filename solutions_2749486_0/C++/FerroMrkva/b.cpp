#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		printf("Case #%d: ",t);
		int x,y;
		scanf("%d %d",&x,&y);
		int j=1;
		for(int i=0;i!=y;++j){
			if (j&1){
				printf("N");
				i+=j;
			}
			else {
				printf("S");
				i-=j;
			}
		}
		for(int i=0;i!=x;){
			if (x>0){
				printf("WE");
				++i;
			}
			else{
				printf("EW");
				--i;
			}
		}
		puts("");
	}
	return 0;
}
