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

typedef long long LL;

int getMin(vector<LL> &m, LL cur, int pos)
{
	int total = 0;
	if (pos == m.size()) {
		return 0;
	}
	LL c = m[pos];
	if (cur > c)
	{
		total += getMin(m, cur+c, pos+1);
	} else {
		int a = 1+ getMin(m, cur, pos+1);
		int b = 0;
		{
			if (cur-1 > 0)
			{
				while (cur <=c) 
				{
					cur += cur-1; b ++;
				}
				b = b+ getMin(m, cur+c, pos+1);
			} else 
				b = 999999999;
		}	
		total = std::min(a, b);
	}
	return total; 
}

int main()
{

	int T;


    //ifstream fin("C:\\Compete\\CodeJam1A\\CodeJam1A\\A-large.in");

    ifstream fin("C:\\Compete\\CodeJam20121B\\A-large.in");

    ofstream fout("C:\\Compete\\CodeJam20121B\\output.txt");

	fin >> T;
   
	for (int i=0; i < T; i++)
	{
		curMin = 999999999;
		LL A, N;

		fin >> A >> N;

		vector<LL> mote;
		for (int j=0; j < N; j++)
		{
			LL mm = 0; fin >> mm; 
			mote.push_back(mm);
		}
		sort(mote.begin(), mote.end());

		int res = getMin(mote, A, 0);
		
		fout << "Case #" << i+1 <<  ": " << res  << endl;
		mote.clear();
	
	}
	return 0;
} 