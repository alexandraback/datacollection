#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include<iterator>
using namespace std;

class Sol
{
public:
	int n; //number of googlers
	int surp;//surprsing
	int p;//best smallest result;

	vector<int> score;

	int HowMany()
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(p==0)
				cnt++;
			else if(p==1 && 2*(p-1)+p<=score[i])
				cnt++;
			else if(p>=2)
			{
				if((2*(p-1)+p)<=score[i])
					cnt++;
				else if((2*(p-2)+p)<=score[i])
				{
					if(surp>0)
					{
						cnt++;
						surp--;
					}
				}
			}

		}
		return cnt;
	}
};

int main()
{
	ifstream ifs("B-small-attempt0.in");
	ofstream ofs("B-small-attempt0.out");

	int num;
	ifs>>num;
	int cnt=1;
	while(num--)
	{
		Sol sol;
		ifs>>sol.n>>sol.surp>>sol.p;
		sol.score.resize(sol.n);
		for(int i=0;i<sol.n;i++)
			ifs>>sol.score[i];
		int res=sol.HowMany();
		ofs<<"Case #"<<cnt<<": "<<res<<endl;
		cnt++;
	}
	ifs.close();
	ofs.close();
	return 0;
}