//============================================================================
// Name        : CodeJam2013.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<stack>
#include<math.h>
#include<fstream>
#include<string.h>
using namespace std;

int tot,cnt;

void eval(int Arr[][20],int N,int n,int X,int Y){
	int px=15,py=20,pytemp,pxtemp;
	if(n==N){
		tot++;
		if(Arr[X][Y]==1)cnt++;
		return;
	}

	while(true){
		if(py==0)
		{
			Arr[px][py]=1;
			eval(Arr,N,n+1,X,Y);
			Arr[px][py]=0;
			break;
		}
		if( Arr[px][py-2]==0)
			py-=2;
		else if( Arr[px][py-2] && Arr[px-1][py-1] && Arr[px+1][py-1]){
			Arr[px][py]=1;
			eval(Arr,N,n+1,X,Y);
			Arr[px][py]=0;
			break;
		}
		else if(Arr[px][py-2] && Arr[px-1][py-1]){
			while(py>0 && Arr[px+1][py-1]==0)
			{
				px++;py--;
			}
			Arr[px][py]=1;
			eval(Arr,N,n+1,X,Y);
			Arr[px][py]=0;
			break;
		}
		else if(Arr[px][py-2] && Arr[px+1][py-1]){

			while(py>0 && Arr[px-1][py-1]==0)
			{
				px--;py--;
			}
			Arr[px][py]=1;
			eval(Arr,N,n+1,X,Y);
			Arr[px][py]=0;
			break;
		}
		else if(Arr[px][py-2]){
			pxtemp=px;pytemp=py;
			while(py>0 && Arr[px+1][py-1]==0)
			{
				px++;py--;
			}
			Arr[px][py]=1;
			eval(Arr,N,n+1,X,Y);
			Arr[px][py]=0;
			px=pxtemp;py=pytemp;
			while(py>0 && Arr[px-1][py-1]==0)
			{
				px--;py--;
			}
			Arr[px][py]=1;
			eval(Arr,N,n+1,X,Y);
			Arr[px][py]=0;
			break;

		}


	}
}

int main() {

	ofstream file;
	file.open("out.txt");
	int i,j,k,T,N,X,Y;

	int Arr[30][20];
	scanf("%d",&T);

	for(i=0;i<T;i++){
		scanf("%d %d %d",&N,&X,&Y);
		tot=0;cnt=0;
		for(j=0;j<30;j++)for(k=0;k<20;k++)Arr[j][k]=0;

		if(X>-15 && X < 14 && Y <20)
		{	eval(Arr,N,0,X+15,Y);
			printf("Case #%d: %lf\n",i+1,((double)cnt)/tot);}
		else
			printf("Case #%d: 0.000000\n",i+1);
		//printf("Case #%d: %d %d\n",i+1,cnt,tot);
		//file<<"Case #"<<i+1<<": "<<eval(A,0,N,Arr,0,101)<<"\n";

	}
}
