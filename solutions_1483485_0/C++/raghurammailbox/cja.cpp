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
	map<char,char>enc;
	/*Input
	3
	ejp mysljylc kd kxveddknmc re jsicpdrysi
	rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
	de kr kd eoya kw aej tysr re ujdr lkgc jv


	Output
	Case #1: our language is impossible to understand
	Case #2: there are twenty six factorial possibilities
	Case #3: so it is okay if you want to just give up

	*/


	enc['a']='y';enc['b']='h';enc['c']='e'; enc['d']='s';enc['e']='o';
	enc['f']='c';enc['g']='v';enc['h']='x'; enc['i']='d';enc['j']='u';
	enc['k']='i';enc['l']='g';enc['m']='l'; enc['n']='b';enc['o']='k';
	enc['p']='r';enc['q']='z';enc['r']='t'; enc['s']='n';enc['t']='w';
	enc['u']='j';enc['v']='p';enc['w']='f'; enc['x']='m';enc['y']='a';
												enc['z']='q';
	ifstream infile;
	infile.open("input.in",ifstream::in);
	ofstream outfile;
	outfile.open("output.in",ofstream::out);
	int t;
	string line;
		infile>>t;
		getline(infile,line);
		for (int tt=0;tt<t;tt++)
		{
			outfile<<"Case #"<<tt+1<<": ";
			getline(infile,line);
			cout<<line;
			for (unsigned int ii=0;ii<line.length();ii++)
				{
				if (line[ii]==' ')
					{outfile<<' ';cout<<' ';}
				else
					{outfile<<enc[line[ii]];cout<<' ';}
				}
			outfile<<"\n";



		}// end of tt
		infile.close();
		outfile.close();





}



