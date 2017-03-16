#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
 
using namespace std;
 
int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A-small-attempt0.out");
    int T;
    fin >> T;
     
    int S;
    for (int t = 1 ; t <= T; t++)
    {  
    	fin >> S;
    	bool found[10];
    	for (int i = 0 ; i < 10 ; i++) found[i] = false;

    	int count = 0;
    	if (S == 0) {fout << "Case #" << t << ": " << "INSOMNIA" << endl; continue;}
     	while(true) {
     		count++;
     		int number = count * S;

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
