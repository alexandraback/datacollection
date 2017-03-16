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

vector<bool> countCons(1000000);

int main()
{
	int n;
	ifstream in("A-small-attempt0.in");
	ofstream out("output.out");
	in >> n;
	for(int cases = 1; cases <= n; cases++)
	{
		string temp;
		long long ans=0;
		int types;
		in >> temp >> types;
		for(int i = 0; i <= temp.length()-types; i++)
		{
			bool cos = true;
			for(int j = i; j < i+types; j++)
			{
				if (temp[j]=='a'||temp[j]=='e'||temp[j]=='i'||temp[j]=='o'||temp[j]=='u')
					cos = false;
			}
			countCons[i]=cos;
		}
		int n = temp.length()-types;
		for(int i=0;i<=temp.length()-types;i++)
		{
			for(int j=0;j<n+1;j++)
				if(countCons[j])
					ans++;
			for(int j=0;j<n;j++)
			{
				if(countCons[j]||countCons[j+1])
					countCons[j]=true;
				else
					countCons[j]=false;
			}
			n--;
		}
		out << "Case #" << cases << ": " << ans << endl;
	}
	return 0;
}