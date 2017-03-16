#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(void)
{
	char lfeed[1024];
	ifstream in("B.in");
	ofstream out("B.out");
	in.getline(lfeed,1024);
	int cases = atoi(lfeed);
	int googlers, triplets, min, v;
	int total;
	
	for (int caseid = 1 ; caseid <= cases ; caseid ++)
	{
		total = 0;
		in.getline(lfeed,1024);
		googlers = atoi(strtok(lfeed, " "));
		triplets = atoi(strtok(NULL, " "));
		min = atoi(strtok(NULL, " "));
		
		for (int g = 0 ; g < googlers ; g ++)
		{
			v = atoi(strtok(NULL, " "));
			if (v < min) continue;
			if (v >= 3*min) total ++;
			else
			{
				int temp;
				temp = (v-min)/2;
				if ((min - temp) == 1) total ++;
				else if (((min - temp) == 2) && (triplets != 0))
				{
					total ++;
					triplets --;
				}
			}
		}
	out << "Case #" << caseid << ": " << total << endl;
	}
	
	in.close();
	out.close();
	return 0;
}
