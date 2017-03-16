#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
 
using namespace std;
 
int main()
{
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");
    int T;
    fin >> T;
     
    long long S;
    for (int t = 1 ; t <= T; t++)
    {  
    	fin >> S;
    	bool found[10];
    	for (int i = 0 ; i < 10 ; i++) found[i] = false;

    	long long count = 0;
    	if (S == 0) {fout << "Case #" << t << ": " << "INSOMNIA" << endl; continue;}
     	while(true) {
     		count++;
     		long long number = count * S;

    		while (number > 0)
			{
    			int digit = number%10;
    			number /= 10;
    			found[digit] = true;
			}
			bool sleep = true;
			for (int i = 0 ; i < 10 ; i++) 
				if (found[i] == false) {sleep = false; break;}
			if (sleep) break;
    	}
       	fout << "Case #" << t << ": " << count*S << endl;
    }
}
