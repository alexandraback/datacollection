#include<stdio.h>
#include<math.h>
int r,c,m;
char map[55][55];
FILE *fo;
void fill(){
	int i,j;
	for(i=0;i<r+2;i++){
		for(j=0;j<c+2;j++){
			map[i][j] = '*';
		}
	}
}
void case_1(int blank, int length){
	int i,j,tx,ty;
	for(i=0;i<length;++i){
		for(j=0;j<length;++j){
			map[i][j] = '.';
			--blank;
		}
	}
	if(blank<=0) return;
	if(r>length){
		for(i=0;i<r-length;i++){
			for(j=0;j<length;++j){
				if(blank<=0) break;
				tx= length+i, ty = j;
				map[length+i][j]='.';
				--blank;
			}
		}
	}
	if(blank<=0 && ty==0){
		map[tx][ty+1] = '.';
		map[tx-1][length-1] = '*';
		return;
	}
	if(c>length){
		for(i=0;i<c-length;i++){
			for(j=0;j<length;j++){
				if(blank<=0) break;
				tx= j, ty = length+i;
				map[j][length+i]='.';
				--blank;
			}
		}
	}
	if(tx == 0){
		map[tx+1][ty] = '.';
		for(j=0;j<r;j++){
			if(map[j][ty-1]=='*') break;
		}map[j-1][ty-1]='*';
	}
}
void print(){
	int i,j;
	map[0][0]='c';
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			fprintf(fo,"%c",map[i][j]);
		}
		fprintf(fo,"\n");
	}
}
void case_2(int blank, int length){
	int i,j,tx,ty;
	for(j=0;j<c;++j){
		for(i=0;i<r;++i){
			if(blank<=0) break;
			tx=i,ty=j;
			map[i][j] = '.';
			--blank;
		}
	}
	if(tx == 0){
		map[1][ty] = '.';
		map[r-1][ty-1]='*';
	}
}
void case_3(int blank, int length){
	int i,j,tx,ty;
	for(j=0;j<r;++j){
		for(i=0;i<c;++i){
			if(blank<=0) break;
			tx = j;ty = i;
			map[j][i] = '.';
			--blank;
		}
	}
	if(ty == 0){
		map[tx][1]='.';
		map[tx-1][c-1]='*';
	}
}
int main()
{
	FILE *fi=fopen("input.txt","r");
	fo=fopen("output.txt","w");
	int t,i,temp;

	fscanf(fi,"%d",&t);
	for(i=0;i<t;i++){
		fscanf(fi,"%d %d %d",&r,&c,&m);
		fprintf(fo,"Case #%d:\n",i+1);
		if((r>1 && c>1) && (r*c-m ==2 || r*c-m == 3 || r*c-m == 5 || r*c-m == 7 || ((r==2 || c == 2) && ((r*c-m)%2==1) && r*c-m!=1 ))){
			fprintf(fo,"Impossible\n");
			continue;
		}
		fill();
		if(r == 1 || c == 1){
			if(r == 1){
				for(int j=0;j<r*c-m;j++) map[0][j] = '.';
				print();
				continue;
			}
			if(c == 1){
				for(int j=0;j<r*c-m;j++) map[j][0] = '.';
				print();
				continue;
			}
		}
		temp = (int)sqrt((double)(r*c-m));
		if(temp <=r && temp<=c){
			case_1(r*c-m,temp);
		}
		else if(temp>r){
			case_2(r*c-m,temp);
		}
		else {
			case_3(r*c-m,temp);
		}
		print();
	}
	return 0;
}