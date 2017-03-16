#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//istream& fin = cin;
//ifstream fin ("A-sample.txt");
ifstream fin ("A-small-attempt0.in");
ofstream fout ("A-small-attempt0.out");
//ifstream fin ("A-large.in");
//ofstream fout ("A-large.out");
//ostream& fout = cout;

bool DFS(bool d[1000][1000],int n,int from,bool f[1000]){
	for(int i=0;i<n;i++){
		if(d[from][i]){
			if(f[i]){
				return true;
			}else{
				f[i]=true;
			}
			if(DFS(d,n,i,f)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int t,n;
	fin >> t;
	for(int i=1; i<=t; i++){
    fout << "Case #" << i << ": ";
	  fin >> n;
	  bool d[1000][1000]={};
	  for(int j=0; j<n; j++){
			int m;
			fin >> m;
			for(int k=0; k<m; k++){
				int to;
				fin >> to;
				d[j][to-1]=true;
			}
		}
		bool found=false;
		for(int j=0; j<n; j++){
			bool f[1000]={};
			if(DFS(d,n,j,f)){
				found=true;
				break;
			}
		}
		if(found){
			fout << "Yes" << endl;
		}else{
			fout << "No" << endl;
		}
	}
	system("pause");
}
