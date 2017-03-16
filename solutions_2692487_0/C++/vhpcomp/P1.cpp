#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;
int curMin = 999999999;

void getMin(vector<int> &m, int cur, int pos, int total)
{
	if (pos == m.size()) {
		if (total < curMin) 
			curMin = total;
		return;
	}
	int c = m[pos];
	if (cur > c)
	{
		getMin(m, cur+c, pos+1, total);
	} else {
		getMin(m, cur, pos+1, total+1);
		{
			if (cur-1 > 0)
			{
				while (cur <=c) 
				{
					cur += cur-1; total ++;
				}
				getMin(m, cur+c, pos+1, total);
			}
		}
		
	}
}

int main()
{

	int T;


    //ifstream fin("C:\\Compete\\CodeJam1A\\CodeJam1A\\A-large.in");

    ifstream fin("C:\\Compete\\CodeJam20121B\\A-small-attempt1.in");

    ofstream fout("C:\\Compete\\CodeJam20121B\\output.txt");

	fin >> T;
   
	for (int i=0; i < T; i++)
	{
		curMin = 999999999;
		int A, N;

		fin >> A >> N;

		vector<int> mote;
		for (int j=0; j < N; j++)
		{
			int mm = 0; fin >> mm; 
			mote.push_back(mm);
		}
		sort(mote.begin(), mote.end());

		getMin(mote, A, 0, 0);
		
		fout << "Case #" << i+1 <<  ": " << curMin  << endl;
		mote.clear();
	
	}
	return 0;
} 