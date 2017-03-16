#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int compare (const void * a, const void * b)
{
	double diff = (*(double*)a-*(double*)b);
	if(diff<0) return -1;
	if(diff==0) return 0;
	return 1;
}

int warnormal(double * naomi, double * ken, int n){
	int nb,ne,kb,ke;
	nb=0;
	kb=0;
	ne=n-1;
	ke=n-1;
	int i;
	int tag;
	for(i=0; i<n; i++){
		tag = 1;
		while(true){
			if(kb==n){
				tag =0;
				break;
			}
			if(naomi[i]>ken[kb]){
				kb++;
			}
			else{
				break;
			}
		}
		if(kb==n)break;
		kb++;
	}
	return n-i;
}

int wardeceit(double * naomi, double * ken, int n){
	int nb,ne,kb,ke;
	nb=0;
	kb=0;
	ne=n-1;
	ke=n-1;
	int i;
	int cnt=0;
	for(i=0; i<n; i++){
		if(naomi[nb]>ken[kb]){
			cnt++;
			nb++;
			kb++;
		}
		else{
			nb++;
			ke--;
		}
	}
	return cnt;
}

int main()
{
	int cases;
	int n;
	int i,j;
	double* ken;
	double* naomi;
	ifstream fin;
	ofstream fout;
	fin.open("D-small-attempt1.in");
	fout.open("D-small-attempt1.out");
	fin >> cases;
	ken = (double *)malloc(sizeof(double)*1000);
	naomi = (double *)malloc(sizeof(double)*1000);
	for(i=1; i<=cases; i++){
		fin >> n;
		for(j=0; j<n; j++){
			fin >> naomi[j];
		}
		for(j=0; j<n; j++){
			fin >> ken[j];
		}
		qsort(naomi,n,sizeof(double),compare);
		qsort(ken,n,sizeof(double),compare);
		fout << "Case #" << i << ": " << wardeceit(naomi,ken,n) << " " << warnormal(naomi,ken,n) << endl;
	}
	fin.close();
	fout.close();
	free(ken);
	free(naomi);
	return 0;
}