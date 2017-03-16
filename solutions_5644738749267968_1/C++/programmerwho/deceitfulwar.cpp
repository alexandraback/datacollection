#include<fstream>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int case_number;
	ifstream ifs("D-large.in");
	ofstream ofs("out.txt");
	ifs>>case_number;
	int block_number;
	int de_result;
	int result;
	double block1[2000];
	double block2[2000];
	int p1;
	int p2;
	for(int cases = 1; cases <= case_number; cases ++)
	{
		ifs>>block_number;
		for(int i =0; i!= block_number; i++)
		{
			ifs>>block1[i];
		}
		for(int i =0; i!= block_number; i++)
		{
			ifs>>block2[i];
		}
		sort(block1,block1+block_number);
		sort(block2,block2+block_number);
		p1=0;
		p2=0;
		result = block_number;
		while(1)
		{
			if(p2 == block_number)
				break;
			if(block2[p2]<block1[p1])
				p2++;
			else
			{
				p1++;
				p2++;
				result--;
			}
		}
		p1 = 0;
		p2 = 0;
		de_result = 0;
		while(1)
		{
			if(p1 == block_number)
			{
				break;
			}
			if(block1[p1]>block2[p2])
			{
				de_result++;
				p1++;
				p2++;
			}
			else
			{
				p1++;
			}
		}
		ofs<<"Case #"<<cases<<": "<<de_result<<" "<<result<<endl;
	}
	return 0;
}