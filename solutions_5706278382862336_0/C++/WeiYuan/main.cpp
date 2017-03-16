
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std; 

long long T,P,Q;

long long transfer(){
	int i,j;
	long long res;
	
	int m,n;

	res=-1;

	for(i=0;i<40;i++){
		P=P*2;
		if(P>Q){
			P=P-Q;
			if(res==-1)
				res=i+1;
		}
		else if(P==Q){
			if(res==-1)
				res=i+1;
			break;
		}
		else{
		}
	}

	if(i==40)
		res=-1;
	
	return res;
}

int main() {
	int T;
	long res;
	char str[1024];
	char ch;

	fstream fin("A-small-attempt1.in", ios::in);
	fstream fout("result.txt", ios::out);

	fin >> T;
	fin.getline(str,1024);
	

	for (int i=0;i<T;i++){
		fin >> P;
		fin >> ch;
		fin >> Q;
		fin.getline(str,1024);


		res=transfer();
//		fin >> str;
		if(res>=0)
			fout << "Case #" << i+1 << ": " << res << endl;
		else if(res<0)
			fout << "Case #" << i+1 << ": " << "impossible" << endl;
		else{}

	}



	return 0;
}
