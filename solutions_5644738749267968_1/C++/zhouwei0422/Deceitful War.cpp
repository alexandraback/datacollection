#include <algorithm>  
#include <bitset>  
#include <cctype>  
#include <cmath>  
#include <complex>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <ctime>  
#include <deque>  
#include <functional>  
#include <iomanip>  
#include <iostream>  
#include <fstream>
#include <list>  
#include <map>  
#include <numeric>  
#include <queue>  
#include <set>  
#include <sstream>  
#include <stack>  
#include <string>  
#include <utility>  
#include <vector>   
using namespace std;

ifstream ifile;
ofstream ofile;

int T, N;

void solve(int cases)
{
	ifile>>N;

	vector<int> naomi,ken;
	string tmp;
	for(int i = 0; i < N; i++)
	{
		ifile>>tmp;
		naomi.push_back((int)(atof(tmp.c_str())*1000000));
	}
	for(int i = 0; i < N; i++)
	{
		ifile>>tmp;
		ken.push_back((int)(atof(tmp.c_str())*1000000));
	}

	sort(naomi.begin(),naomi.end());
	sort(ken.begin(),ken.end());

	int dsum = 0;

	vector<bool> used;
	for(int i = 0; i < N; i++)
		used.push_back(true);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(used[j]==true)
			if(naomi[i]>ken[j])
			{
				dsum++;
				used[j]=false;
				break;
			}
		}
	}

	int sum = N;
	
	for(int i = 0; i < N; i++)
		used[i]=true;
	for(int i = 0;i < N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			if(used[j]==true)
			if(ken[j]>naomi[i])
			{
				sum--;
				used[j]=false;
				break;
			}
		}
	}

	ofile<<"Case #"<<cases+1<<": "<<dsum<<" "<<sum<<endl;

}

int main(void)
{
	ifile.open("input.txt");
	ofile.open("output.txt");

	ifile>>T;
	for(int cases = 0; cases < T; cases++)
	{
		solve(cases);
	}
	
	ifile.close();
	ofile.close();
	return 0;
}