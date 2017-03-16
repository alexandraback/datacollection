#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>



using namespace std;

unsigned int check(int A,int numMotes, vector<int> otherMotes)
{
	unsigned int lestOperator = 0;
	int curA = A;
	vector<int> sortedMotes = otherMotes;
	sort(sortedMotes.begin(),sortedMotes.end());

	unsigned int cZero = 0;
	vector<unsigned int> CAccu, D, cost;
	CAccu.push_back(0);

	for(unsigned int i=1;i<=numMotes;i++)
	{
		if(curA>sortedMotes[i-1])
			curA += sortedMotes[i-1];
		else{
			D.push_back(numMotes-i+1);
			unsigned int Ci= 0 ;
			while(curA<=sortedMotes[i-1])
			{
				curA += curA-1;
				Ci++;
			}
			curA += sortedMotes[i-1];
			CAccu.push_back(CAccu.back()+Ci);
		}
	}

	cost = CAccu;
	for(unsigned int k=0;k<D.size();k++)
		cost[k] += D[k];

	sort(cost.begin(),cost.end());

	lestOperator = cost[0];
	return lestOperator;
}


int main()
{


	ifstream infile;
	ofstream outfile; 
	infile.open("D:\\A-small-attempt0.in");
	outfile.open("D:\\A-small-attempt0.out");

	if(!infile.is_open())
		cout<<"can not open input file"<<endl;
	if(!outfile.is_open())
		cout<<"can not open output file"<<endl;

	long numCases = 0;
	string aline;
	//get the number of cases
	getline(infile, aline);
	numCases = ::atol(aline.c_str());

	for(unsigned int i=1;i<=numCases;i++)
	{
		//get input for each case
		getline(infile, aline);
		stringstream alinestream;
		 int A;
		 int numMotes;
		vector< int> otherMotes;
		string temp;
		alinestream << aline;
		alinestream >> temp;
		A=atoi(temp.c_str());
		alinestream >> temp;
		numMotes=atoi(temp.c_str());
		stringstream datalinestream;
		getline(infile, aline);
		datalinestream << aline;
		//cout<<alinestream;
		for(unsigned j=1;j<=numMotes;j++){
			datalinestream >> temp;
			otherMotes.push_back(atoi(temp.c_str()));
		}

		//process
		unsigned int lestOperators;
		if(A==1)
			lestOperators=numMotes;
		else
			lestOperators=check(A,numMotes,otherMotes);
		//output result for each case
				
		outfile<<"Case #"<<i<<": "<<lestOperators<<endl;
		
	}

	infile.close();
	outfile.close();
	return 0;
}