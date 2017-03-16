#include <iostream>
#include <fstream>
#include <iomanip>

#define DEBUG 0
#define NUMBER 10

using namespace std;

int main(int argc, char *argv[])
{
	int i,j,k;
	int t;
	int level;
	int star;
	int table[NUMBER][2];
	bool finish[NUMBER][2];
	bool terminate;
	int round;
	int pos;
	ifstream inFile("B-small-attempt0.in");
	ofstream outFile("result.out");

	inFile>>t;
	for (i=0; i<t; i++)
	{
		cout<<"Case #"<<i+1<<endl;
		outFile<<"Case #"<<i+1<<": ";
		inFile>>level;
		for (j=0;j<level;j++)
		{
			inFile>>table[j][0]>>table[j][1];
			finish[j][0] = finish[j][1] = false;
		}
		star = 0;
		round = 0;
		terminate = false;
		while(!terminate)
		{
			terminate = true;
			// 2 stars
			j = 0;
			while (j<level)
			{
				if (table[j][1]<=star && finish[j][1]==false)
				{
					round++;
					if (finish[j][0]==false)
						star+=2;
					else
						star+=1;
					finish[j][0] = finish[j][1] = true;
					terminate = false;
					break;
				}
				else
				{
					j++;
				}
			}
			//1 star
			if (terminate)
			{
				j = 0;
				k = 0;
				pos = -1;
				while (j<level)
				{
					if (table[j][0]<=star && finish[j][0]==false && table[j][1]>k)
					{
						pos = j;
						k = table[j][1];
					}
					j++;
				}
				if (pos!=-1)
				{
					round++;
					star+=1;
					finish[pos][0] = true;
					terminate = false;
				}
				else
				{
					//ternimate
				}
			}
		}
		if (star==2*level)
			outFile<<round<<endl;
		else
			outFile<<"Too Bad"<<endl;
	}


#if DEBUG
	cin>>i;
#endif
	return 0;
}