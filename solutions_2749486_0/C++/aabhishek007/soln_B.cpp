#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <math.h>

#define OUTPUT_CASE "Case #%d: "
#define SIZE 1000001 //1000001

#define E 0
#define W 1
#define N 2
#define S 3

using namespace std;

typedef long long ll;

inline int is_constant(char c){
	if(c == 'a' || c == 'e' || c == 'i' ||  c == 'o' || c == 'u')
		return 0;
	return 1;
}

int find_next_cindex(int str_index, int pos[SIZE], int cindex, int lastcindex){
	int i = -1;
	for(i=lastcindex;i<cindex;i++){
		if(str_index<=pos[i])
			return i;
	}
	return -1;
}

inline char direction(int x, int y, int dir){
	char retChar;
	if(dir==E){
		retChar = x<0? 'W':'E';
	}
	else if(dir==W){
			retChar = x<0? 'E':'W';
		}
	else if(dir==N){
			retChar = y<0? 'S':'N';
		}
	else //if(dir==S)
		{
			retChar = y<0? 'N':'S';
		}
}

void read_and_solve(int case_no, FILE *fp, FILE *fout){

	int i,j;
	//char output[2][4] = {"YES", "NO"};

	//char str[SIZE];
	//int pos[200000] = {0};
	//int *pos = (int *) malloc(SIZE*sizeof(int));


	char move[SIZE] = {0};
	int x,y;
	int cindex = 0;
	int lastcindex = 0;
	long long count = 0;
	int n = 0;
	//long long temp;
	//long long total_gain = 0;

	fscanf(fp,"%d %d",&x, &y);

	int absx = abs(x);
	int absy = abs(y);


	int min = 0;
	int min_dir = 0;
	if(absx<=absy){
		min = absx;
		min_dir = 0;
	}
	else{
		min = absy;
		min_dir = 1;
	}

	int steps = 1;
	int sum = 0;
	while(sum<=min){
		sum+=steps;
		steps++;
		move[cindex++] = min_dir==0?E:N;
	}
	steps--;
	sum = sum-steps;
	cindex--;

	int left = min - sum;
	if(left>0){
		int root = sqrt((double)left);
		for(i = 0; i < root; i++){
			steps++;
			move[cindex++] = min_dir==0?W:S;
		}

		for(i = 0; i < root; i++){
			steps++;
			move[cindex++] = min_dir==0?E:N;
		}

		left = left - (root * root);

		for(i=0;i<left;i++){
			steps+=2;
			move[cindex++] = min_dir==0?W:S;
			move[cindex++] = min_dir==0?E:N;
		}

	}

	// one direction done

	// do the same for other dir

	min = min_dir == 0? absy:absx;
	min_dir = min_dir == 0? 1: 0;
	sum = 0;
		while(sum<=min){

			sum+=steps;
			steps++;
			move[cindex++] = min_dir==0?E:N;
		}
		steps--;
		sum = sum-steps;

		cindex--;

		left = min - sum;
		if(left>0){
			int root = sqrt((double)left);
			for(i = 0; i < root; i++){
				steps++;
				move[cindex++] = min_dir==0?W:S;
			}

			for(i = 0; i < root; i++){
				steps++;
				move[cindex++] = min_dir==0?E:N;
			}

			left = left - (root * root);

			for(i=0;i<left;i++){
				steps+=2;
				move[cindex++] = min_dir==0?W:S;
				move[cindex++] = min_dir==0?E:N;
			}

		}

		// We have reached the target point
		fprintf(fout,OUTPUT_CASE,case_no);
		for(i=0;i<cindex;i++){
			fprintf(fout,"%c",direction(x,y,move[i]));
		}
		fprintf(fout,"\n");


	//printf("%s %d\n",str,n);

	//int len = strlen(str);


	/*if(!pos)
		return;

	for(i=0;i<= len-n;i++){
		for(j=i;j<i+n;j++){
			int iscontant = is_constant(str[j]);
			if(!iscontant)
				break;
		}

		if(j == i+n){
			pos[cindex++] = i;
		}
	}

	//printf("cindex %d\n",cindex);


	for(i=0;i<len;i++){
		lastcindex = find_next_cindex(i,pos,cindex, lastcindex);
		if(lastcindex == -1){
			continue;
		}

		//printf("cindex found at %d, val  pos[lastcindex][%d] for i[%d]\n",lastcindex, pos[lastcindex],i);
		long long temp_count = pos[lastcindex]+n;
		temp_count = len - temp_count+1;
		//printf("temp_count[%lld]\n",temp_count);
		count+=temp_count;

	}*/

	/*vector<long long> values;
	values.reserve(no_act);

	for(i=0;i<no_act;i++){
		fscanf(fp,"%lld",&temp);
		values.push_back(temp);
	}

	total_gain = 0;
	if(regain >= energy){
		// spend all energy
		for(vector<long long>::iterator itr = values.begin(); itr!=values.end(); ++itr){
			total_gain += (ll)*itr;
		}
		total_gain *= (ll)energy;
		fprintf(fout,OUTPUT_CASE,case_no,total_gain);
		return;
	}

	 */

	//free(pos);

	//fprintf(fout,OUTPUT_CASE,case_no,count);
	//fprintf(fout,OUTPUT_CASE,case_no,output[YES]);
	return;

}

int main(){
	int no_test;
	FILE *fp;
	FILE *fout;
	int i;

	//A-small-practice.in
	fp = fopen("B-small-attempt1.in","r");
	fout = fopen("output_B_small.txt","w");

	//printf("after file open fp:%d, fout:%d\n",fp,fout);

	if(fp == NULL || fout == NULL)
		return 1;



	fscanf(fp,"%d",&no_test);

	for(i=1;i<=no_test;i++){
		read_and_solve(i,fp, fout);
		fflush(fout);
	}

	fclose(fp);
	fclose(fout);
	return 0;

}
