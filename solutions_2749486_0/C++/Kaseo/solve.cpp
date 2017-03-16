#include <cstdio>


int main(){freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	
	for(int r=1; r<=T; r++){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", r);

		if(x != 0){
			if( x > 0){
				for(int i=0; i<x; i++)
					printf("WE");
			}
			else{
				for(int i=0; i<-x; i++)
					printf("EW");
			}
		}
			
		if(y !=0){
			if( y>0 ){
				for(int i=0; i<y; i++)
					printf("SN");
			}
			else{
				for(int i=0; i<-y; i++)
					printf("NS");
			}
		}
		puts("");
		
	}
}