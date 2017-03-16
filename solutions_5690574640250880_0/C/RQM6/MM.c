#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define ROW 1
#define COL 0

int makegrid(int R,int C,int fsp);
int makeg(int R,int C, int fsp);
FILE *fi,*fo;
char grid[51][51];

int main(){
	int i,j,T,t,R,C,M;
	fi=fopen("C-small-practice.in","r");
	fo=fopen("C-small-practice.out","w");
	fscanf(fi,"%d",&t);
	
	for(T=1;T<=t;T++){
		fscanf(fi,"%d %d %d",&R,&C,&M);
		fprintf(fo,"Case #%d:\n",T);
		
		memset (grid, '\0', sizeof(grid));
		grid[0][0]='c';

		if(M==R*C-2||M==R*C-3||M==R*C-5||M==R*C-7){
			if(R!=1&&C!=1)
				fprintf(fo,"Impossible\n");
			else if(R==1||C==1){
				makeg(R,C,R*C-M);
				for(i=0;i<R;i++){
					for(j=0;j<C;j++)
						fprintf(fo,"%c",grid[i][j]);
					fprintf(fo,"\n");
				}}
			else{
				makegrid(R,C,R*C-M);
				for(i=0;i<R;i++){
					for(j=0;j<C;j++)
						fprintf(fo,"%c",grid[i][j]);
					fprintf(fo,"\n");

				}}}
		else if(R==2&&M%2==1&&M!=R*C-1)
				fprintf(fo,"Impossible\n");
		else if(C==2&&M%2==1&&M!=R*C-1)
				fprintf(fo,"Impossible\n");
		else if(M==0)
			for(i=0;i<R;i++){
				for(j=0;j<C;j++)
					if(i==0&&j==0)
						fprintf(fo,"c");
					else
						fprintf(fo,".");
				fprintf(fo,"\n");
			}
		else{
			printf("%d: ",T);
			makegrid(R,C,R*C-M);
			for(i=0;i<R;i++){
				for(j=0;j<C;j++)
					fprintf(fo,"%c",grid[i][j]);
				fprintf(fo,"\n");
			}
		}

	}
	fclose(fi);
	fclose(fo);
	return 0;
}

int makegrid(int R,int C,int fsp)
{
	int buff,size[2],count=0,i,j;
	size[0]=(int) sqrt(fsp);
	size[1]=(R>C?C:R);
	
	if(size[0]>size[1])
		size[COL]=fsp/size[1];
	else
		size[ROW]=(int) sqrt(fsp);
	if(R>C){
		buff=size[1];
		size[ROW]=size[0];
		size[COL]=buff;
	}

	for(i=0;i<size[ROW];i++)
		for(j=0;j<size[COL];j++)
			grid[i][j]='.';
	grid[0][0]='c';
	
	buff=fsp%(size[ROW]*size[COL]);
	if(buff+size[ROW]*size[COL]!=fsp){
		if(size[ROW]!=R&&size[COL]!=C){
			for(i=0;i<size[ROW];i++)
				grid[i][size[COL]]='.';
			for(i=0;i<size[COL];i++)
				grid[size[ROW]][i]='.';
		}
		else if(size[ROW]==R){
			buff=fsp/(size[ROW]*size[COL]);
			for(i=0;i<size[ROW];i++)
				for(j=size[COL];j<buff*size[COL];j++)
					grid[i][j]='.';
		}
		else {
			buff=fsp/(size[ROW]*size[COL]);
			for(i=0;i<size[COL];i++)
				for(j=size[ROW];j<buff*size[ROW];j++)
					grid[j][i]='.';
		}
	}
	printf("%d %d\n",size[ROW],size[COL]);
	if(size[ROW]<=size[COL])
		for(i=0;i<size[ROW];i++)
			if(count!=buff&&size[COL]!=C){
				grid[i][size[COL]]='.';
				if(buff==1){
					grid[1][size[COL]]='.';
					grid[size[ROW]-1][size[COL]-1]='*';
				}
				count++;
			}
				
	if(size[ROW]>=size[COL])
		for(i=0;i<size[COL];i++)
			if(count!=buff&&size[ROW]!=R){
				grid[size[ROW]][i]='.';
				if(buff==1){
					grid[size[ROW]][1]='.';
					grid[size[ROW]-1][size[COL]-1]='*';
				}
				count++;
			}			
	
	if(buff==(size[ROW]+1)&&size[ROW]==size[COL]){
		if(size[ROW]!=R&&size[COL]!=C){
			grid[size[ROW]-1][size[COL]]='*';
			grid[size[ROW]][1]='.';
			count=buff;
		}
		else if(size[ROW]==R){
			grid[0][size[COL]+1]='.';
			grid[size[ROW]-1][size[COL]]='*';
			grid[1][size[COL]+1]='.';
			count=buff;
		}
		else{
			grid[size[ROW]+1][0]='.';
			grid[size[ROW]][size[COL]-1]='*';
			grid[size[ROW]+1][1]='.';
			count=buff;
		}
	}
	
	if(count!=buff){
		if(size[ROW]<=size[COL])
			for(i=0;i<size[ROW];i++)
				if(count!=buff&&size[COL]!=C){
					grid[i][size[COL]+1]='.';
					count++;
				}
				
		if(size[ROW]>=size[COL])
			for(i=0;i<size[COL];i++)
				if(count!=buff&&size[ROW]!=R){
					grid[size[ROW]+1][i]='.';
					count++;
				}
	}
		
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			if(grid[i][j]=='\0')
				grid[i][j]='*';
	return 0;
}

int makeg(int R,int C, int fsp)
{	int i;
	if(R==1){
		for(i=1;i<fsp;i++)
			grid[0][i]='.';
		for(i=fsp;i<C;i++)
			grid[0][i]='*';
	}
	if(C==1){
		for(i=1;i<fsp;i++)
			grid[i][0]='.';
		for(i=fsp;i<R;i++)
			grid[i][0]='*';
	}
	return 0;
}