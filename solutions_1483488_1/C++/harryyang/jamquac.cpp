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
#include<iterator>
#include<fstream>
using namespace std;

class Sol
{
public:
	string large;
	string n;

	int HowMany()
	{
		int cnt=0;
		int size=n.size();
		vector<string> store;
		for(int i=1;i<size;i++)
		{
			bool flag=true;
			
			if(size==large.size())
			{
				for(int j=i;j<size+i;j++)
				{
					char c1=n[j%size];
					char c3=large[j-i];
					if(c1!=c3)
					{
						if(c1>c3)
						{
							flag=false;
							break;
						}
						else if(c1<c3)
						{
							flag=true;
							break;
						}
					}
				}
			}
			string ss="";
			if(flag)
			{
				flag=false;
				for(int j=i;j<size+i;j++)
				{
					char c1=n[j%size];
					char c2=n[j-i];
					if(c1>c2)
					{
						flag=true;
						for(int k=i;k<size+i;k++)
						{
							char c4=n[k%size];
							ss+=c4;
						}
						break;
					}
					else if(c1<c2)
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{
					bool flag2=false;
					for(int k=0;k<store.size();k++)
					{
						if(ss==store[k])
						{
							flag2=true;
							break;
						}
					}
					if(!flag2)
					{
						store.push_back(ss);
						cnt++;
					}
				}
			}
		}
		return cnt;
	}
};

int main()
{
	ifstream ifs("C-large.in");
	ofstream ofs("C-large.out");
	int num;
	ifs>>num;
	int i=1;
	while(num--)
	{
		string s1,s2;
		ifs>>s1>>s2;
		int small=atoi(s1.c_str());
		int large=atoi(s2.c_str());
		Sol sol;
		sol.large=s2;
		int cnt=0;
		for(int i=small;i<=large;i++)
		{
			stringstream out;
			out<<i;
			sol.n=out.str();
			int res=sol.HowMany();
			cnt+=res;
		}
		ofs<<"Case #"<<i<<": "<<cnt<<endl;
		i++;
	}
	ifs.close();
	ofs.close();
	system("pause");
}