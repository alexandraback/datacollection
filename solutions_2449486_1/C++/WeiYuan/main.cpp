
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>


using namespace std; 

int N,M;
long Cary[100][100];




long transfer(){
	int i;
	long res=0;
	int flag=0;

	for(int j=0;j<N;j++){
		for(int k=0;k<M;k++){
			flag=0;

			for(i=0;i<N;i++){
				if(Cary[i][k]>Cary[j][k]){
					flag=1;
					break;
				}
			}
			if(i==N)
				continue;

			for(i=0;i<M;i++){
				if(Cary[j][i]>Cary[j][k]){
					if(flag==1){
						return 1;
					}
				}
			}
		}
	}

	return res;
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
		memset(str,0,1024);

		fin>>N;
		fin>>M;
		fin.getline(str,1024);

		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				fin>>Cary[j][k];
			}
			fin.getline(str,1024);
		}

		res=transfer();

		if(res==0)
			fout << "Case #" << i+1 << ": " << "YES" << endl;
		else
			fout << "Case #" << i+1 << ": " << "NO" << endl;
	}



	return 0;
}
