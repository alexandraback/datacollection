#include <cstdio>
using namespace std;

int main(){
	FILE*in=fopen("D-small-attempt2.in","r");
	FILE*out=fopen("out.txt","w");
	
	int t,x,r,c;
	
	fscanf(in,"%d ",&t);
	
	for(int i=0;i<t;i++){
		fscanf(in,"%d %d %d ",&x, &r, &c);
		bool ric =true;
		if(x==1)ric=false;
		else if((r*c)%x==0){
			if(x==2)ric=false;
			else if(x==3){
				if(r*c!=3) ric=false;
			}
			else if(x==4){
				if(r*c==12 || r*c==16)ric=false;
			}
		}
		if(ric){
			fprintf(out,"Case #%d: RICHARD\n",i+1);
		}
		else{
			fprintf(out,"Case #%d: GABRIEL\n",i+1);
		}
	}

}
