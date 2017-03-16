/*
 * a.cpp
 *
 *  Created on: 28-Apr-2013
 *      Author: lavan
 */
#include <stdio.h>
#include <iostream>
#include <fstream>
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
#include <limits>
#define _USE_MATH_DEFINES

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
		long int X,Y;
		infile>>X>>Y;
		outfile<<"Case #"<<tt+1<<": ";
		if(X!=0){
			if(X>0)
				while(X>0)
				{
					outfile<<"WE";
					X--;
				}
			else
				while(X<0)
				{
				outfile<<"EW";
				X++;
				}
		}
		if(Y!=0){
					if(Y>0)
						while(Y>0)
						{
							outfile<<"SN";
							Y--;
						}
					else
						while(Y<0)
						{
						outfile<<"NS";
						Y++;
						}
				}


		outfile<<"\n";
	}
	//end of t

	infile.close();
	outfile.close();

}







