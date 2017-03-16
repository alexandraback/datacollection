#include<iostream>
#include <fstream>

using namespace std;

int cas, index = 1;

const int SIZE = 100;
int score[SIZE] = {0};
int n;
int s;
int p;
ifstream fin("B-large.in");
ofstream fout("B-large.OUT");

void read()
{
	fin >> n >> s >> p;

	for (int i=0; i < n; i ++)
	{
		fin >> score[i];
	}
}

void judge()
{
	int must = 0;
	int num = 0;

	for (int i=0; i < n; i ++)
	{
		if(p==0)
		{
			if(score[i] >= 0)
			{
				num ++;
			}
		}
		else if (p == 1)
		{
			if(score[i] >= 1)
			{
				num ++;
			}
		}
		else
		{
			if (score[i] >= p*3-4 && score[i] < p*3 -2 )
			{
				must ++;
				num ++;
			}
			else if(score[i] >= p*3-2)
			{
				num ++;
			}
		}
	}

	if (must > s)
	{
		num = num -  must + s;
	}
	fout << "Case #" << index << ": " << num << endl;
}

int main()
{
	fin >> cas;

	while (index <= cas)
	{
		read();
		judge();		
		index ++;
	}
	return 0;
}