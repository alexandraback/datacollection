#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void main()
{
	//open input file and build output file
	ifstream infile("B-large.in");
	ofstream outfile("result.out");

	// obtain number of test cases
	unsigned int numOftestcases=0;
	string firstline;
	getline(infile,firstline);
	numOftestcases = atoi(firstline.c_str());

	//process all test cases
	for(unsigned int i=1;i<=numOftestcases;i++)
	{
		//read one test case
		string tempcase;
		getline(infile, tempcase);

		//Obtain N, S, P t1, t2,...,tN
		unsigned int tempNumofDancers=0;
		unsigned int tempNumofSurprising=0;
		unsigned int tempBaseMark=0;
		vector<unsigned int> scores;
		unsigned int myStart=0;
		unsigned int myEnd=0;
		unsigned int tag=1;
		unsigned int casesize=tempcase.size();
		//start to convert structural string to numbers
		for(;myEnd<casesize;)
		{
			if(tempcase[myEnd]!=' ')
				myEnd++;
			else
			{
				string 	number_str=tempcase.substr(myStart,myEnd-myStart);
				unsigned int number_find=atoi(number_str.c_str());
				if(tag<4)
				{
					if (tag==1)
						tempNumofDancers=number_find;
					else if (tag==2)
						tempNumofSurprising=number_find;
					else if(tag==3)
						tempBaseMark=number_find;
					else
						cout<<"input error happens"<<endl;

					tag++;					
				}
				else
					scores.push_back(number_find);

				//move to another number
				myEnd++;
				myStart=myEnd;
			}
		}
		//add the the score of last dancer to the "socres"
		string last_score_str=tempcase.substr(myStart,myEnd-myStart);
		scores.push_back(atoi(last_score_str.c_str()));
		
		//process the case
		unsigned int tempresult=0;
	
		if(tempBaseMark==0)
			tempresult=tempNumofDancers;
		else if(tempBaseMark==1)
		{
			for(unsigned int j=0;j<tempNumofDancers;j++)
			{
				if(scores[j]>0)
					tempresult++;
			}
		}
		else //when tempBaseMark is larger than 1
		{		
			unsigned int baseline = 3*(tempBaseMark-1);
			for(unsigned int k=0;k<tempNumofDancers;k++)
			{
				if(scores[k]>baseline)
					tempresult++;
				else
				{
					if(tempNumofSurprising>0)
					{
						if(scores[k]==baseline || scores[k]==baseline-1)
						{
							tempresult++;
							tempNumofSurprising--;
						}
					}
					else
						continue;
				}
			}
		}

		//output the result
		outfile<<"Case #"<<i<<": "<<tempresult<<endl;
	}
	infile.close();
	outfile.close();

}