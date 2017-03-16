#include <stdio.h>
#include <string.h>
#include <vector>

#define OUTPUT_CASE "Case #%d: %lld\n"
#define SIZE 1001 //1000001

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

void read_and_solve(int case_no, FILE *fp, FILE *fout){

	int i,j;
	//char output[2][4] = {"YES", "NO"};

	char str[SIZE];
	int pos[SIZE] = {0};
	int cindex = 0;
	int lastcindex = 0;
	long long count = 0;
	int n = 0;
	//long long temp;
	//long long total_gain = 0;

	fscanf(fp,"%s %d",&str[0], &n);

	//printf("%s %d\n",str,n);

	int len = strlen(str);

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

	}

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

	fprintf(fout,OUTPUT_CASE,case_no,count);
	//fprintf(fout,OUTPUT_CASE,case_no,output[YES]);
	return;

}

int main(){
	int no_test;
	FILE *fp;
	FILE *fout;
	int i;

	//A-small-practice.in
	fp = fopen("A-small-attempt0.in","r");
	fout = fopen("output_A_small.txt","w");

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
