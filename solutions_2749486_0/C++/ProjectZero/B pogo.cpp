#include <cstdio>
int T,x,y;
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-output0.in","w",stdout);
	
	scanf("%d",&T);
	for(int _i=1;_i<=T;_i++){
		printf("Case #%d: ",_i);
		
		scanf("%d %d",&x,&y);
		if(x < 0) for(int i=1;i<=-x;i++) printf("EW");
		else      for(int i=1;i<=x;i++) printf("WE");
		
		if(y < 0) for(int i=1;i<=-y;i++) printf("NS");
		else      for(int i=1;i<=y;i++) printf("SN");
		
		printf("\n");
	}
	return 0;
}
/*
(0,1) 	N
(0,-1)	S
(1,0)	E
(-1,0)	W

(x,y) = (EW)^x  + (NS)^y
(5,2) = EWEWEWEWEW NSNS
	  = ENNESN
*/