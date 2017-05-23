// code jam 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
FILE *op;
ofstream fout;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int table[4][4];
	char str[100];

	fout.open("output.txt");
	op = fopen("A-small-attempt0.in","r");

	fscanf(op,"%d",&n);

	int xwin, ywin;
	int notcomplete;

	for(int i=0;i<n;i++) {
		xwin = 0, ywin =0;
		notcomplete = 0;

		for(int j=0;j<4;j++) {
			fscanf(op,"%s",str);

			for(int k=0;k<4;k++) {
				if(str[k]=='X') {
					table[j][k] = 1;
				}
				else if(str[k]=='O') {
					table[j][k] = 2;
				}

				else if(str[k]=='T') {
					table[j][k] = 3;
				}

				else if(str[k]=='.') {
					table[j][k] = 0;
					notcomplete = 1;
				}
			}
		}

		for(int j=0;j<4;j++) {
			int xcount_width=0, ycount_width=0;
			int xcount_height=0, ycount_height=0;
			int xcount_diagonal_front=0,ycount_diagonal_front=0;
			int xcount_diagonal_end=0,ycount_diagonal_end=0;

			for(int k=0;k<4;k++) {
				if(table[j][k]==1 || table[j][k]==3) xcount_width +=1;
				if(table[j][k]==2 || table[j][k]==3) ycount_width +=1;

				if(table[k][j]==1 || table[k][j]==3) xcount_height +=1;
				if(table[k][j]==2 || table[k][j]==3) ycount_height +=1;

				if(table[k][k]==1 || table[k][k]==3) xcount_diagonal_front +=1;
				if(table[k][k]==2 || table[k][k]==3) ycount_diagonal_front +=1;

				if(table[k][3-k]==1 || table[k][3-k]==3) xcount_diagonal_end +=1;
				if(table[k][3-k]==2 || table[k][3-k]==3) ycount_diagonal_end +=1;
			}

			if(xcount_width == 4) xwin = 1;
			if(ycount_width == 4) ywin = 1;

			if(xcount_height == 4) xwin = 1;
			if(ycount_height == 4) ywin = 1;

			if(xcount_diagonal_front == 4) xwin = 1;
			if(ycount_diagonal_front == 4) ywin = 1;

			if(xcount_diagonal_end == 4) xwin = 1;
			if(ycount_diagonal_end == 4) ywin = 1;

		}

		fout << "Case #" <<i+1<<": ";
		if(xwin == 1) fout <<"X won"<<endl;
		else if(ywin == 1) fout <<"O won"<<endl;
		else if(notcomplete == 0) fout << "Draw" <<endl;
		else if(notcomplete == 1) fout <<"Game has not completed"<<endl;




		/*
		for(int j=0;j<4;j++) {
			for(int k=0;k<4;k++) {
				cout << table[j][k];
			}
			cout << endl;
     	}
		cout <<endl <<endl;*/
	}

	return 0;
}

