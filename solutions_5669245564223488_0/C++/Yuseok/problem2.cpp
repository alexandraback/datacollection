// Codejam Pratice rotate.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int t;
char data1[105][500];
int a,b;
int n,k;
int final, mins;
int tcnt;
int index[105];
int check[105];

FILE *op,*out;

int recur(int depth)
{
	int i,j;
	int ok;

	if(depth >=3)
	{
		if(data1[index[1]][strlen(data1[index[1]])-1] != data1[index[2]][0]) return 0;
	}

	if(depth == n+1) {
		ok = 0;

	//	for(i=1;i<=n;i++) {
	//		printf("%s ", data1[index[i]]);
	//	}

	//	printf("\n");

		for(i=2;i<n;i++) {
			if((data1[index[i]][strlen(data1[index[i]])-1] != data1[index[i+1]][0]) && (data1[index[i]][0] != data1[index[i-1]][strlen(data1[index[i-1]])-1])) ok = 1;
		}
		
		if((data1[index[n]][0] != data1[index[n-1]][strlen(data1[index[n-1]])-1])) ok = 1;

	//	printf("ok: %d\n", ok); 
		if(ok==0) tcnt +=1;
	}

	else {

		for(i=1;i<=n;i++) {
			if(check[i] == 0) {
				index[depth] = i;
				check[i] = 1;
				
				recur(depth+1);

				check[i] = 0;
			}			
		}
	}
}

int main()
{
	int i,j,k;
	int ok;


	ofstream outfile("output.txt");
	op = fopen("input.txt","r");

	fscanf(op,"%d",&t);

	for(i=0;i<t;i++) {

		fscanf(op,"%d",&n);

		for(j=0;j<=n;j++) { check[j] = 0; }

		for(j=1;j<=n;j++) {
			fscanf(op,"%s",&data1[j]);
		}

		tcnt = 0;

		recur(1);

		outfile << "Case #" <<  i+1 << ": " << tcnt << endl;
	}

//	getche();
	return 0;
}
