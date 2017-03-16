// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int get_finish(int ans)
{
	if (ans>-40 && ans<10)
		if (ans==-22||ans==-31||ans==-13||ans==-4)
			return -1;
		else if (ans==-29||ans==-18||ans==-7||ans==4)
			return 1;
	return 0;
}

int main()
{
	ofstream fout("d:\\out.txt");
	ifstream fin("d:\\in.txt");
	char s[4][4];
	int ss[4][4];

	int n(0);
	fin>>n;

	for(int i=0;i<n;++i)
	{
		fin.getline(s[0],4);
		for(int j=0;j<4;++j)
			for (int k=0;k<4;++k)
				fin>>s[j][k];
		bool completed = true;
		int finish = 0;
		for(int p=0;p<4;++p)
		{
			for (int q=0;q<4;++q)
				if (s[p][q]=='.')
				{
					ss[p][q] = 100;
					completed = false;
				}
				else if (s[p][q]=='T') ss[p][q] = -10;
				else if (s[p][q]=='X') ss[p][q] = 1;
				else ss[p][q] = -1;
		}
		//row
		for (int k=0;k<4;++k)
		{
			finish = get_finish(ss[k][0]+ss[k][1]+ss[k][2]+ss[k][3]);
			if (finish!=0)
				break;
		}
		//column
		if (finish==0)
		{
			for (int k=0;k<4;++k)
			{
				finish = get_finish(ss[0][k]+ss[1][k]+ss[2][k]+ss[3][k]);
				if (finish!=0)
					break;
			}
		}
		//diag
		if (finish==0)
			finish = get_finish(ss[0][0]+ss[1][1]+ss[2][2]+ss[3][3]);
		if (finish==0)
			finish = get_finish(ss[0][3]+ss[1][2]+ss[2][1]+ss[3][0]);
		//output
		if (finish==1)
			fout<<"Case #"<<i+1<<": X won"<<endl;
		else if (finish==-1)
			fout<<"Case #"<<i+1<<": O won"<<endl;
		else if (completed)
			fout<<"Case #"<<i+1<<": Draw"<<endl;
		else
			fout<<"Case #"<<i+1<<": Game has not completed"<<endl;
	}
	return 0;
}
