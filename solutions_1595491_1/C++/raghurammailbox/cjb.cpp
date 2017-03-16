#include <stdio.h>
#include <iostream>
#include<fstream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>


using namespace std;



int main(int argc, char *argv[])
{

	ifstream infile;
	infile.open("input.in",ifstream::in);
	ofstream outfile;
	outfile.open("output.in",ofstream::out);
	int t;
	infile>>t;

	for (int tt=0;tt<t;tt++){
		int N,S,p;
		int gs_wos=0;
		int gs_withS=0;

		infile>>N>>S>>p;
		for (int nn=0;nn<N;nn++)
		{
		int temp;
		infile>>temp;
		switch (temp%3)
				{
				case 0:
					if(temp/3>=p)
						gs_wos++;
					if(((temp/3)+1>=p)&((temp/3)<p)&(temp!=0))
						gs_withS++;
					break;
				case 1:
					if((temp/3+1)>=p)
					gs_wos++;
					break;
				case 2:
					if(((temp/3)+1)>=p)
					gs_wos++;
					if(((temp/3)+2>=p)&(((temp/3)+1)<p))
					gs_withS++;
					break;
				}
		}
		int gs;
		gs=gs_wos+min(gs_withS,S);

		outfile<<"Case #"<<tt+1<<": "<<gs<<"\n";

	}
	//end of t

	infile.close();
	outfile.close();

}
