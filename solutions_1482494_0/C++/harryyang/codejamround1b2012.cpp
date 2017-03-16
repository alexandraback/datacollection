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

struct STARS
{
	int a;
	int b;
	int id;
	int completed;
};

bool Comp1(STARS s1,STARS s2){return s1.a<s2.a;}
bool Comp2(STARS s1,STARS s2){return s1.b<s2.b;}

int main()
{
	ifstream ifs("B-small-attempt0 (2).in");
	ofstream ofs("B-small-attempt0 (2).out");
	int testCase;
	ifs>>testCase;
	int id=1;
	while(id<=testCase)
	{
		int N;
		ifs>>N;
		vector<STARS>  levels(N);
		for(int i=0;i<N;i++)
		{
			ifs>>levels[i].a>>levels[i].b;
			levels[i].id=i;
		}
		vector<bool> completed1(N),completed2(N);
		fill(completed1.begin(),completed1.end(),false);
		fill(completed2.begin(),completed2.end(),false);
		int curStar=0;
		int res=0;
		while(true)
		{
			int tmpLevel=-1;
			for(int i=0;i<N;i++)
			{
				if(levels[i].b<=curStar && !completed2[i] && !completed1[i])
				{
					if(tmpLevel==-1)
						tmpLevel=i;
					else
					{
						if(levels[i].a>levels[tmpLevel].a)
							tmpLevel=i;
					}
				}
			}
			if(tmpLevel!=-1)
			{
				curStar+=2;
				completed2[tmpLevel]=true;
				res++;
			}
			else
			{
				for(int i=0;i<N;i++)
				{
					if(levels[i].b<=curStar && !completed2[i] && completed1[i])
					{
						if(tmpLevel==-1)
							tmpLevel=i;
						else
						{
							if(levels[i].a>levels[tmpLevel].a)
								tmpLevel=i;
						}
					}
				}
				if(tmpLevel!=-1)
				{
					curStar+=1;
					completed2[tmpLevel]=true;
					res++;
				}
				else
				{
					for(int i=0;i<N;i++)
					{
						if(levels[i].a<=curStar && !completed2[i] && !completed1[i])
						{
							if(tmpLevel==-1)
								tmpLevel=i;
							else
							{
								if(levels[i].b>levels[tmpLevel].b)
									tmpLevel=i;
							}
						}
					}
					if(tmpLevel!=-1)
					{
						curStar+=1;
						completed1[tmpLevel]=true;
						res++;
					
					}
					else
						break;
				}
			}
		}
		bool flag=true;
		for(int i=0;i<N;i++)
			if(!completed2[i])
				flag=false;
		ofs<<"Case #"<<id<<": ";
		if(!flag)
			ofs<<"Too Bad"<<endl;
		else
			ofs<<res<<endl;
		id++;
	}
	ifs.close();
	ofs.close();
	system("pause");
}