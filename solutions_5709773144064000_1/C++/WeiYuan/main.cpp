
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>


using namespace std; 

double C;
double F;
double X;
double tt;


long transfer(){
	int i,j;

	tt=0;
	if(X<C){
		tt=X/2;
		return 0;
	}
	tt=C/2;
	for(i=1;;i++){
		if( ((X-C)/(2+(i-1)*F)) < (X/(2+i*F)) ){
			tt+=((X-C)/(2+(i-1)*F));
			break;
		}
		else{
			tt+=C/(2+i*F);
		}
	}



	return 0;
}

int main() {
	int T;
	long res;
	char str[1024];

	fstream fin("B-large.in", ios::in);
	fstream fout("result.txt", ios::out);

	fin >> T;
	fin.getline(str,1024);

	for (int i=0;i<T;i++){
		fin >> C;
		fin >> F;
		fin >> X;
		fin.getline(str,1024);
		res=transfer();


		fout.setf(ios::fixed);
		fout.precision(7);
		fout << "Case #" << i+1 << ": " << tt << endl;

	}



	return 0;
}
