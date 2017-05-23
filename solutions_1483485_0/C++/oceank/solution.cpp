#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void main()
{
	//open input file and build output file
	ifstream infile("A-small-attempt1.in");
	ofstream outfile("result.out");

	//build mapping between English letter and Googlerese letter
	char mapping[26];
	mapping[0]='y';mapping[1]='h';mapping[2]='e';mapping[3]='s';mapping[4]='o';mapping[5]='c';mapping[6]='v';
	mapping[7]='x';mapping[8]='d';mapping[9]='u';mapping[10]='i';mapping[11]='g';mapping[12]='l';mapping[13]='b';
	mapping[14]='k';mapping[15]='r';mapping[16]='z';mapping[17]='t';mapping[18]='n';mapping[19]='w';mapping[20]='j';
	mapping[21]='p';mapping[22]='f';mapping[23]='m';mapping[24]='a';mapping[25]='q';

	int numOftestcases=0;
	string firstline;
	getline(infile,firstline);
	numOftestcases = atoi(firstline.c_str());
	//process all test cases
	for(int i=1;i<=numOftestcases;i++)
	{
		//read one test case
		string tempcase;
		string tempresult;
		getline(infile, tempcase);
		unsigned int casesize=tempcase.size();
	    //process the case
		for(unsigned int j=0;j<casesize;j++)
		{
			if(tempcase[j]==' ')
				tempresult.push_back(' ');
			else
			{	
				char orig_Eng=mapping[tempcase[j]-97];
				tempresult.push_back(orig_Eng);
			}
		}
		//output the result
		outfile<<"Case #"<<i<<": "<<tempresult<<endl;
	}
	infile.close();
	outfile.close();
}