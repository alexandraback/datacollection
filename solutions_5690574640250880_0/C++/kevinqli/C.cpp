#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("C.in");
ofstream fout("C.out");

int T;

int main(){
	fin>>T;
	for(int z=1;z<=T;z++){
	
	int R,C,M;
	
	fin>>R>>C>>M;
	
	fout<<"Case #"<<z<<":"<<endl;
	
	int a=R*C-M;
	
	if(R==1){
		fout<<'c';
		for(int i=2;i<=a;i++)fout<<'.';
		for(int i=1;i<=M;i++)fout<<'*';
		fout<<endl;
		continue;
	}
	
	if(C==1){
		fout<<'c'<<endl;
		for(int i=2;i<=a;i++)fout<<'.'<<endl;
		for(int i=1;i<=M;i++)fout<<'*'<<endl;
		continue;
	}
	
	if(R==2){
		if(a==1){
			fout<<'c';
			for(int i=2;i<=C;i++)fout<<'*';
			fout<<endl;
			for(int i=1;i<=C;i++)fout<<'*';
			fout<<endl;
			continue;
		}
		if(a%2==1||a==2){
			fout<<"Impossible"<<endl;
			continue;
		}
		fout<<'c';
		for(int i=2;i<=a/2;i++)fout<<'.';
		for(int i=1;i<=M/2;i++)fout<<'*';
		fout<<endl;
		for(int i=1;i<=C-M/2;i++)fout<<'.';
		for(int i=1;i<=M/2;i++)fout<<'*';
		fout<<endl;
		continue;
	}
	
	if(C==2){
		if(a==1){
			fout<<'c'<<'*'<<endl;
			for(int i=2;i<=R;i++)fout<<'*'<<'*'<<endl;
			continue;
		}
		if(a%2==1||a==2){
			fout<<"Impossible"<<endl;
			continue;
		}
		fout<<'c'<<'.'<<endl;
		for(int i=2;i<=a/2;i++)fout<<'.'<<'.'<<endl;
		for(int i=1;i<=M/2;i++)fout<<'*'<<'*'<<endl;
		continue;
	}
	
	if(a==2||a==3||a==5||a==7){
	fout<<"Impossible"<<endl;
		continue;
	}
	if(a==1){
		fout<<'c';
		for(int i=2;i<=C;i++)fout<<'*';
		fout<<endl;
		for(int i=2;i<=R;i++){
			for(int j=1;j<=C;j++)fout<<'*';
			fout<<endl;
		}
		continue;
	}
	if(a>2*C+1){
		if(a%C==1){
			fout<<'c';
			for(int i=2;i<=C;i++)fout<<'.';
			fout<<endl;
			for(int i=2;i<=a/C-1;i++){
				for(int j=1;j<=C;j++)fout<<'.';
				fout<<endl;
			}
			for(int i=1;i<=C-1;i++)fout<<'.';
			fout<<'*'<<endl<<'.'<<'.';
			for(int i=3;i<=C;i++)fout<<'*';
			fout<<endl;
			for(int i=a/C+2;i<=R;i++){
				for(int j=1;j<=C;j++)fout<<'*';
				fout<<endl;
			}
			continue;
		}
		fout<<'c';
		for(int i=2;i<=C;i++)fout<<'.';
		fout<<endl;
		for(int i=2;i<=a/C;i++){
			for(int j=1;j<=C;j++)fout<<'.';
			fout<<endl;
		}
		if(a%C!=0){
			for(int i=1;i<=a-a/C*C;i++)fout<<'.';
			for(int i=a-a/C*C+1;i<=C;i++)fout<<'*';
			fout<<endl;
			for(int i=a/C+2;i<=R;i++){
				for(int j=1;j<=C;j++)fout<<'*';
				fout<<endl;
			}
		}
		else{
			for(int i=a/C+1;i<=R;i++){
				for(int j=1;j<=C;j++)fout<<'*';
				fout<<endl;
			}
		}
		continue;
	}
	
	if(a%3==1){
		fout<<'c';
		for(int i=2;i<=a/3+1;i++)fout<<'.';
		for(int i=a/3+2;i<=C;i++)fout<<'*';
		fout<<endl;
		for(int i=1;i<=a/3+1;i++)fout<<'.';
		for(int i=a/3+2;i<=C;i++)fout<<'*';
		fout<<endl;
		for(int i=1;i<=a/3-1;i++)fout<<'.';
		for(int i=a/3;i<=C;i++)fout<<'*';
		fout<<endl;
		for(int i=4;i<=R;i++){
			for(int j=1;j<=C;j++)fout<<'*';
			fout<<endl;
		}
		continue;
	}
	
	fout<<'c';
	for(int i=2;i<=(a+1)/3;i++)fout<<'.';
	for(int i=(a+1)/3+1;i<=C;i++)fout<<'*';
	fout<<endl;
	for(int i=1;i<=(a+1)/3;i++)fout<<'.';
	for(int i=(a+1)/3+1;i<=C;i++)fout<<'*';
	fout<<endl;
	for(int i=1;i<=a/3;i++)fout<<'.';
	for(int i=a/3+1;i<=C;i++)fout<<'*';
	fout<<endl;
	for(int i=4;i<=R;i++){
		for(int j=1;j<=C;j++)fout<<'*';
		fout<<endl;
	}
	continue;
	
	
	}
	return 0;
}
