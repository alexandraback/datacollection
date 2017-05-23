#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

unsigned int getNumberofDigits(unsigned int a)
{
	unsigned int temp_a=a;
	unsigned int w=0;
	for(;temp_a!=0;){w++;temp_a=temp_a/10;}
	return w;
}
unsigned int myPower(unsigned int base,unsigned int index)
{
	unsigned int temp=1;
	for(unsigned int i=1;i<=index;i++)
		temp=temp*base;
	return temp;
}
bool whether_m_exits(vector<unsigned int> qualified_m, unsigned int m)
{
	bool result=false;
	for(unsigned int i=0;i<qualified_m.size();i++)
	{
		if(qualified_m[i]==m){result=true;break;}
	}
	return result;
}

void main()
{
	//open input file and build output file
	ifstream infile("C-large.in");
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

		//Obtain A and B
		unsigned int A;
		unsigned int B;
		unsigned int myStart=0;
		unsigned int myEnd=0;

		while(tempcase[myEnd]!=' ')
			myEnd++;
		A = atoi((tempcase.substr(myStart,myEnd-myStart)).c_str());
		myStart=myEnd+1;
		myEnd=tempcase.size();
		B = atoi((tempcase.substr(myStart,myEnd-myStart)).c_str());
		
		//process the case
		unsigned int tempresult=0;
		if(A==B)
			tempresult=0;
		else if(A<B)
		{
			unsigned int width=getNumberofDigits(A);
			if(width==1)
				tempresult=0;
			else
			{
				//unsigned int firstDigit_B=B/myPower(10,width-1);
				for(unsigned int n=A;n<B;n++)
				{
					//unsigned int firstDigit_n=n/myPower(10,width-1);	
					vector<unsigned int> qualified_m;//table used to check the uniqueness of (n,m)
					for(unsigned int j=1;j<width;j++)//process starts from the last digit of n
					{
						unsigned int currentpower10=myPower(10,j);
						unsigned int possibleShiftPart=n%currentpower10;
						//unsigned int currentDigit=possibleShiftPart*10/currentpower10;
						//if(currentDigit>=firstDigit_n && currentDigit<=firstDigit_B)
						//{
							unsigned int possible_m=0;
							possible_m=possibleShiftPart*myPower(10,width-j)+n/currentpower10;
							if(possible_m>n && possible_m<=B)
							{
								if(!whether_m_exits(qualified_m,possible_m))// new m
									qualified_m.push_back(possible_m);
							}
						//}
							
					}
					tempresult=tempresult+qualified_m.size();
				}
			}
		}
		else
			cout<<"Error: "<<"Case #"<<i<<", "<<"A>B. "<<"A="<<A<<", B="<<B<<endl;

		//output the result
		outfile<<"Case #"<<i<<": "<<tempresult<<endl;
	}
	infile.close();
	outfile.close();

}