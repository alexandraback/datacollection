#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	FILE *fin = fopen("input.txt","r"), *fout = fopen("output.txt","w");
	int T,N,s,p;
	fscanf(fin,"%d",&T);
	int valid, pseudo, tmp;
	for (int i = 0; i < T; i++){
		fscanf(fin,"%d %d %d",&N,&s,&p);
		valid = pseudo = 0;
		for (int j = 0; j < N; j++){
			fscanf(fin,"%d",&tmp);
			if (tmp/3+(tmp%3>0)>=p)
				valid++;
			else if (tmp/3+(tmp%3>0)==p-1 && tmp%3!=1 && tmp)
				pseudo++;
		}
		//cout<<i<<" "<<valid<<" "<<pseudo<<" "<<s<<endl;
		fprintf(fout,"Case #%d: %d\n",i+1,valid+min(pseudo,s));
	}
	//system("PAUSE");
	return 0;
}
