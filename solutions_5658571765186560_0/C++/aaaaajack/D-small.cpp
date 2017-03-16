#include<cstdio>
using namespace std;
int main(){
	int T,cs,x,r,c;
	bool g;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++){
		scanf("%d%d%d",&x,&r,&c);
		if(x<3){
			if(r*c%x) g=false;
			else g=true;
		}
		else if(x==3){
			if(r*c%x) g=false;
			else if(r<2||c<2) g=false;
			else if(r<3&&c<3) g=false;
			else g=true;
		}
		else{
			if(r*c%x) g=false;
			else if(r<3||c<3) g=false;
			else if(r<4&&c<4) g=false;
			else g=true;
		}
		if(g){
			printf("Case #%d: GABRIEL\n",cs);
		}
		else{
			printf("Case #%d: RICHARD\n",cs);
		}
	}
	return 0;
}