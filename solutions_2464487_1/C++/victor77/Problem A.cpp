#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

int main () {
	string line;
	int noOfCase;
	unsigned long long r,t;
	  
	ifstream myfile ("A-large.in");
	if (myfile.is_open())
	{  
		ofstream myfileOut;
		myfileOut.open("output.out");
		getline(myfile,line);
		
		istringstream(line) >> noOfCase;
		
		for(int k=0;k<noOfCase;k++)
		{
			int count=0;
			
				getline(myfile,line);
				istringstream(line) >> r >>t;
				
				unsigned long long temp=t/2;
				bool find=false;
				// if (temp <=1000000000000000)
				// {
					unsigned long long temp1=unsigned long long(floor(sqrt((long double)temp)));
					unsigned long long sol=min(temp1,t/(2*r+1));
					
					while(!find)
					{
						if ((sol+1)>t/(2*sol+2*r+1))
							if ((sol)<=t/(2*(sol-1)+2*r+1))						
								find=true;
							else
								sol--;
						else
							sol++;
					}
			
			cout<<"Case #"<<k+1<<": "<<sol<<endl;			
			myfileOut<<"Case #"<<k+1<<": "<<sol<<endl;
			
		
			
		}
		myfileOut.close();				
		myfile.close();
	}

	else cout << "Unable to open file";
	
	return 0;
}