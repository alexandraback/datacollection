#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <map>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

int main()
{
	long long n;
	ifstream in("A-large.in");
	ofstream out("output.out");
	in >> n;
	vector<long long> motes(100);
	for(long long cases = 1; cases <= n; cases++)
	{
		long long a, v;
		in >> a >> v;
		for(int i = 0; i < v; i++)
			in >> motes[i];
		sort(motes.begin(),motes.begin()+v);
		vector<long long> answers;
		int count=0;
		bool check=false;
		for(int i=0;i<v;i++)
		{
			if(a>motes[i])
				a += motes[i];
			else if(a<=motes[i] && a>1)
			{
				answers.push_back(count+(v-i));
				while(a<=motes[i] && a>1)
				{
					a += a-1;
					count++;
				}
				a += motes[i];
			}
			else
			{
				check = true;
				answers.push_back(count+v-i);
				break;
			}
		}
		if(!check)
			answers.push_back(count);
		sort(answers.begin(),answers.end());
		out << "Case #" << cases << ": " << answers[0] << endl;
	}
	return 0;
}