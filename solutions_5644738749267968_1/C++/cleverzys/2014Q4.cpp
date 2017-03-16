#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
using namespace std;

int BlockNum;
int SolveWar(vector<double> her,vector<double> his);
int SolveDeceitfulWar(vector<double> her,vector<double> his);
int SolveDeceitfulWar(vector<double> her,vector<double> his)
{
	int i;
	vector<double>::iterator it;
	sort(her.begin(),her.end());
	sort(his.begin(),his.end());
	int length=her.size();
	while(true)
	{
		for(i=0;i<length;i++)
		{
			if(her[i]<his[i])
				break;
		}
		if(i==length)
			return length;
		else
		{
			it=her.begin();
			her.erase(it);
			it=his.end();it--;
			his.erase(it);
			length=her.size();
		}
	}

}
int SolveWar(vector<double> his,vector<double> her)
{
	int i;
	vector<double>::iterator it;
	sort(her.begin(),her.end());
	sort(his.begin(),his.end());
	int length=her.size();
	while(true)
	{
		for(i=0;i<length;i++)
		{
			if(her[i]<his[i])
				break;
		}
		if(i==length)
			return BlockNum-length;
		else
		{
			it=her.begin();
			her.erase(it);
			it=his.end();it--;
			his.erase(it);
			length=her.size();
		}
	}
	
}
void main()
{
	//freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-large.in", "r", stdin);
	//freopen("1.txt", "r", stdin);
	//freopen("D-small-attempt0.out", "w", stdout);
	//freopen("2.txt", "w", stdout);
	freopen("D-large.out", "w", stdout);
	int Numcase;
	cin>>Numcase;
	
	double temp;
	for(int test=1;test<=Numcase;test++)
	{
		vector<double> She;
		vector<double> He;
		cout<<"Case #"<<test<<": ";
		cin>>BlockNum;
		for(int i=0;i<BlockNum;i++)
		{
			cin>>temp;
			She.push_back(temp);
		}
		for(int i=0;i<BlockNum;i++)
		{
			cin>>temp;
			He.push_back(temp);
		}
		cout<<SolveDeceitfulWar(She,He)<<" ";
		cout<<SolveWar(She,He)<<endl;
	}
	fclose(stdout);
}