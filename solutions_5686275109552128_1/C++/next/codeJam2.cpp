#include<iostream>
#include <fstream>
#include<algorithm>

using namespace std;

int NoOfCakes[1010];

int main()
{
	int t, d;
	int minutes = 0, cases = 0;
	ifstream ifile ("B-large.in");
	//ifstream ifile ("test.in");
	ofstream ofile;
	ofile.open ("Output.out");
	ifile>>t;
	while(t--)
	{
		int maximum = 0, minimum = INT_MAX;
		ifile>>d; 
        for(int i = 0 ; i < d ; i++) 
		{  
			ifile>>NoOfCakes[i]; 
            maximum = max(maximum,NoOfCakes[i]);
        }  
        minimum = maximum ;  
        for(int i = 1 ; i <= maximum ; i++)
		{  
            minutes = i ;  
            for(int j = 0 ; j < d ; j++) 
			{  
                if( NoOfCakes[j] > i ) 
				{  
                    if( NoOfCakes[j] % i == 0 )  
                        minutes += (NoOfCakes[j] / i - 1);  
                    else  
                        minutes += (NoOfCakes[j] / i);  
                }  
            }  
            minimum = min(minimum,minutes);
		}
		ofile<<"Case #"<<++cases<<": "<<minimum<<endl;
	}
	ifile.close();
	ofile.close();
	return 0;
}