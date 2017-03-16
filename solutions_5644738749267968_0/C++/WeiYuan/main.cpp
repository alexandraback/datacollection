
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>


using namespace std; 

int N;
double ary1[1024];
double ary2[1024];
int decwar;
int norwar;


//small to large, double
int compareD(const void *arg1, const void *arg2) {
	if(( *(double *)arg1 > *(double *)arg2 ))
		return 1;
	else if(( *(double *)arg1 < *(double *)arg2 ))
		return -1;
	else
		return 0;
}
//qsort((void *)dary, count, sizeof(double), compareD);



long transfer(){
	int i,j;
	long res;
	double tmp1[1024];
	double tmp2[1024];
	int count;
	
	res=0;
	decwar=0;
	norwar=0;

	count=N;

	qsort((void *)ary1, count, sizeof(double), compareD);
	qsort((void *)ary2, count, sizeof(double), compareD);

	int bign,smalln;
	bign=count-1;smalln=0;

	for(i=0;i<count;i++){
		tmp1[i]=ary1[i];
		tmp2[i]=ary2[i];
	}


	for(i=0;i<count;i++){
		if(tmp1[i]>tmp2[smalln]){
			decwar++;
			smalln++;
		}
		else if(tmp1[i]<tmp2[smalln]){
//			bign--;
		}
		else{
			decwar=-1;
			return 0;
		}
	}

	for(i=0;i<count;i++){
		tmp1[i]=ary1[i];
		tmp2[i]=ary2[i];
	}

	for(i=count-1;i>=0;i--){
		if(tmp1[i]>tmp2[bign]){
			norwar++;
//			smalln--;
		}
		else if(tmp1[i]<tmp2[bign]){
			bign--;
		}
		else{
			norwar=-1;
			return 0;
		}
	}

	
	return res;
}

int main() {
	int T;
	long res;
	char str[1024];

	fstream fin("D-small-attempt0.in", ios::in);
	fstream fout("result.txt", ios::out);

	fin >> T;
	fin.getline(str,1024);

	for (int i=0;i<T;i++){
		fin >> N;
		fin.getline(str,1024);

		for(int j=0;j<N;j++){
			fin>>ary1[j];
		}
		fin.getline(str,1024);

		for(int j=0;j<N;j++){
			fin>>ary2[j];
		}
		fin.getline(str,1024);

		res=transfer();
//		fin >> str;
		fout << "Case #" << i+1 << ": " << decwar << " " << norwar << endl;

	}



	return 0;
}
