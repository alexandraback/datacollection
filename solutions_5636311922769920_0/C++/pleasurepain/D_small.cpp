#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <string>
#include <ctime>
//#include <string.h>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>


using namespace std;



int main() 
{
	

	ifstream fin("D-small-attempt2.in");  
	ofstream fout("output.out");

	/*ifstream fin("input.txt");  
	ofstream fout("output.txt");*/
	
	int T;
	fin>>T;

	for (int cnt=1; cnt<=T; cnt++)
	{
		long int K,C,S;
		fin>>K>>C>>S;

		long long int index[100];
		for (int indexofl=1; indexofl<=K; indexofl++)
		{
			long long int M=indexofl-1;

			for (long long int complexity=2; complexity<=C; complexity++)
			{
				M=K*M+indexofl-1;
			}
			index[indexofl-1]=M+1;
		}

		fout<<"Case #"<<cnt<<":";
		for (int i=0; i<K; i++)
			fout<<" "<<index[i];
		fout<<endl;
		

	}
	

	//system("pause");
	//return 0;
}
