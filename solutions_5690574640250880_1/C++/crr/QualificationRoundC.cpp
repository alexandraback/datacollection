//============================================================================
// Name        : QualificationRoundC.cpp
// Author      : crr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int R,C,M;
int ndot;
char matrix[50][50];
ofstream fout("C-small-practice.out");

void case0()
{
	bool isFirst = true;
	for(int i=0;i<R;i++){
		isFirst?isFirst = false:fout<<endl;
		for(int j=0;j<C;j++){
			if(i==0&& j==0)
				fout<<"c";
			else
				fout<<".";
		}
	}

}
void case1()
{
	if(R==1){
		fout << "c";
		for(int i=1;i<ndot;i++)
			fout<<".";
		for(int i=ndot;i<C;i++)
			fout<<"*";
	}
	if(C==1){
		fout<<"c";
		for(int i=1;i<ndot;i++)
			fout<<endl<<".";
		for(int i=ndot;i<R;i++)
			fout<<endl<<"*";
	}

}
void case2()
{
	if(ndot==1){
		bool isFirst = true;
		for(int i=0;i<R;i++){
			isFirst?isFirst = false:fout<<endl;

			for(int j=0;j<C;j++)
				if(i==0 && j==0)
					fout<<"c";
				else
					fout<<"*";
		}
	}
	else if(ndot==2 || ndot%2==1)
		fout<<"Impossible";
	else if(ndot%2==0){
		if(R==2){
			fout<<"c";
			for(int i=1;i<ndot/2;i++)
				fout<<".";
			for(int i=ndot/2;i<C;i++)
				fout<<"*";
			fout<<endl;
			fout<<".";
			for(int i=1;i<ndot/2;i++)
				fout<<".";
			for(int i=ndot/2;i<C;i++)
				fout<<"*";
		}
		if(C==2){
			for(int i=0;i<R;i++)
			{
				if(i==0)
					fout <<"c.";
				else if(i<ndot/2)
					fout<<endl<<"..";
				else
					fout<<endl<<"**";
			}
		}
	}
}
void case3()
{
	if(ndot==2||ndot==3||ndot==5||ndot==7)
		fout<<"Impossible";
	else if(ndot==1){
		bool isFirst = true;
		for(int i=0;i<R;i++){
			isFirst?isFirst=false:fout<<endl;
			for(int j=0;j<C;j++)
				if(i==0 && j==0)
					fout<<"c";
				else
					fout<<"*";
		}
	}else if(ndot==4){
		bool isFirst = true;
		for(int i=0;i<R;i++){
			isFirst?isFirst=false:fout<<endl;
			for(int j=0;j<C;j++)
				if(i==0 && j==0)
					fout<<"c";
				else if(i<2 && j<2)
					fout<<".";
				else
					fout<<"*";
		}

	}else if(ndot==6){
		bool isFirst = true;
		for(int i=0;i<R;i++){
			isFirst?isFirst=false:fout<<endl;
			for(int j=0;j<C;j++)
				if(i==0 && j==0)
					fout<<"c";
				else if(i<2 && j<3)
					fout<<".";
				else
					fout<<"*";
		}

	}else if(ndot==8){
		bool isFirst = true;
		for(int i=0;i<R;i++){
			isFirst?isFirst=false:fout<<endl;
			for(int j=0;j<C;j++)
				if(i==0 && j==0)
					fout<<"c";
				else if(i==2 && j==2)
					fout<<"*";
				else if(i<3 && j<3)
					fout<<".";
				else
					fout<<"*";
		}
	}else{
		matrix[0][0]='.';matrix[0][1]='.';matrix[0][2]='.';
		matrix[1][0]='.';matrix[1][1]='.';matrix[1][2]='.';
		matrix[2][0]='.';matrix[2][1]='.';	//matrix[2][2]='.';
		ndot -= 8;

		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(ndot>0){
					if(matrix[i][j]!='.'){
						if(i==0){
							if(ndot>=2){
								matrix[i][j]='.';
								matrix[i+1][j]='.';
								ndot -= 2;
							}else{
								matrix[2][2] = '.';
								ndot -= 1;
							}
						}else if(j==0){
							if(ndot>=2){
								matrix[i][j]='.';
								matrix[i][j+1]='.';
								ndot -= 2;
							}else{
								matrix[i][j]='.';
								matrix[i][j+1]='.';
								matrix[i-1][C-1]='*';
								ndot -= 1;
							}
						}else{
							matrix[i][j] = '.';
							ndot -= 1;
						}
					}
				}
			}
		}
		matrix[0][0] = 'c';
		bool isFirst = true;
		for(int i=0;i<R;i++){
			isFirst?isFirst=false:fout<<endl;
			for(int j=0;j<C;j++){
				fout<<matrix[i][j];
			}
		}
	}
}
int main() {
	int nCase;
	ifstream fin("C-large.in");
	fin >> nCase;
	cout << nCase << endl;
	bool isFirstCase = true;
	for(int iCase=0;iCase<nCase;iCase++)
	{
		if(isFirstCase)
			isFirstCase = false;
		else
			fout<<endl;
		fout<<"Case #"<<iCase+1<<": "<<endl;
		cout<<"Case #"<<iCase+1<<": "<<endl;

		fin>>R>>C>>M;
		cout<<R<<","<<C<<","<<M<<endl;

		//cout << sizeof(matrix);
		memset(matrix,'*',sizeof(matrix));
		ndot = R*C-M;

		if(M==0)
			case0();
		else if(R==1 || C==1)
			case1();
		else if(R==2 || C==2)
			case2();
		else
			case3();

		cout << "============================================" << endl;
	}

	return 0;
}
