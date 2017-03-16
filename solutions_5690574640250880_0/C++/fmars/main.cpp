#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    FILE*fin=fopen("in.txt","r");
    FILE*fout=fopen("out.txt","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++){
        fprintf(fout,"Case #%d:\n",i);
        int r,c,m;
        fscanf(fin,"%d%d%d",&r,&c,&m);
        if(r==1){
            fprintf(fout,"c");
            for(int j=0;j<r*c-m-1;j++)
                fprintf(fout,".");
			for(int j=0;j<m;j++)
				fprintf(fout,"*");
			fprintf(fout,"\n");
        }else if(c==1){
            fprintf(fout,"c\n");
            for(int j=0;j<r*c-m-1;j++)
                fprintf(fout,".\n");
			for(int j=0;j<m;j++)
				fprintf(fout,"*\n");
		}else if(r*c-m==1){
			fprintf(fout,"c");
			for(int j=0;j<c-1;j++)
				fprintf(fout,"*");
			fprintf(fout,"\n");
			for(int j=1;j<r;j++){
				for(int k=0;k<c;k++)
					fprintf(fout,"*");
				fprintf(fout,"\n");
			}
        }else if(r*c-m<4){
            fprintf(fout,"Impossible\n");
        }else{
            int rr=r,cc=c,mm=m;
            int grid[51][51]={0};
            int small,which;
			int flag=0;
            while(mm){
                small=rr<cc?rr:cc;
                which=rr<cc?0:1;
                if(mm>=small){
                    if(which==0){
                        for(int k=1;k<=rr;k++)
                            grid[k][cc]=1;
                        cc--;
                        mm-=rr;
                    }else if(which==1){
                        for(int k=1;k<=cc;k++)
                            grid[rr][k]=1;
                        rr--;
                        mm-=cc;
                    }
                }else{
                    int large=rr>=cc?rr:cc;
                    if(large-mm>=2){
						if( small==2){
							fprintf(fout,"Impossible\n");
							flag=1;
							mm=0;
							break;
						}
                        if(which==0){
                            for(int k=0;k<mm;k++)
                                grid[rr][cc-k]=1;
                        }else if(which==1){
                            for(int k=0;k<mm;k++)
                                grid[rr-k][cc]=1;
                        }
                        mm=0;
                    }else if (large!=3){
                        for(int k=0;k<mm-1;k++)
                            grid[rr][cc-k]=1;
                        grid[rr-1][cc]=1;
                        mm=0;
                    }else {
						fprintf(fout,"Impossible\n");
						flag=1;
						mm=0;
					}
                }
            }
			if(flag)
				continue;
            grid[1][1]=2;
            for(rr=1;rr<=r;rr++){
                for(cc=1;cc<=c;cc++)
                    if(grid[rr][cc]==2)
                        fprintf(fout,"c");
                    else if(grid[rr][cc]==1)
                        fprintf(fout,"*");
                    else
                        fprintf(fout,".");
                fprintf(fout,"\n");
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
