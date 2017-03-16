#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

string _main(){
	int N,M;
	int i,j,k;
	int a[105][105];
	bool visited[105][105];
	fin>>N>>M;
	for(i=0;i<N;i++) for(j=0;j<M;j++){
		fin>>a[i][j];
		visited[i][j]=false;
	}
	for(i=0;i<N;i++) for(j=0;j<M;j++){
		if(visited[i][j]) continue;
		//check row
		bool cutr = true;
		for(k=0;k<M;k++){
			if(a[i][k] > a[i][j]){
				//fout<<i<<j<<"r"<<endl;
				cutr = false;
				break;
			}
		}
		if(cutr){
			for(k=0;k<M;k++){
				if(a[i][k] == a[i][j]) visited[i][k]=true;
			}
		}
		//check col
		bool cutc = true;
		for(k=0;k<N;k++){
			if(a[k][j] > a[i][j]){
				//fout<<i<<j<<"c"<<endl;
				cutc = false;
				break;
			}
		}
		if(cutc){
			for(k=0;k<N;k++){
				if(a[k][j] == a[i][j]) visited[k][j]=true;
			}
		}
		//fout<<i<<j<<"\t"<<cutr<<cutc<<endl;
		if(!cutc && !cutr) return "NO";
	}
	return "YES";
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            fout<<_main();
            fout<<endl;
    }
}
