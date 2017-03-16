//
//  main.cpp
//  codeJam_QualificationRound
//
//  Created by Jereneal Kim on 13. 4. 13..
//  Copyright (c) 2013년 Jereneal Kim. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char **argv)
{
	FILE *fp,*inp;
	int T,i,x,y,xi,yi;
	
	fp=fopen(argv[1],"w");
	inp=fopen(argv[2],"r");
	
	fscanf(inp,"%d",&T);
	
	for(i=1;i<=T;i++){
		fscanf(inp,"%d %d",&x,&y);
		fprintf(fp,"Case #%d: ",i);
		//for(j=1;j<=500;j++){
			if(x>0){
				xi=0;
				while(xi!=x){
					fprintf(fp,"WE");
					xi++;
				}
			}else{
				xi=0;
				while(xi!=x){
					fprintf(fp,"EW");
					xi--;
				}
			}
			if(y>0){
				yi=0;
				while(yi!=y){
					fprintf(fp,"SN");
					yi++;
				}
			}else{
				yi=0;
				while(yi!=y){
					fprintf(fp,"NS");
					yi--;
				}
			}
			fprintf(fp,"\n");
		//}

		//printf("Case #%lld: %lld\n",i,result);
	}
	
	
	return 0;
}

