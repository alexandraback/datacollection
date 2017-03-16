#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <map>
using namespace std;

const int MAX = 105;
long long box[MAX][2], toy[MAX][2];
int n, m;
char buf[MAX];
map<string, long long> mp;

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}
long long mymin(long long a, long long b)
{
	return a > b ? b : a;
}

long long dfs(int i, int j)
{
	if(i < 0 || j < 0)
		return 0;
	string str = string(itoa(i, buf, 10)) + string("a") + string(itoa(j, buf, 10)) + string("a")
		+ string(itoa(box[i][0], buf, 10)) + string("a") + string(itoa(toy[j][0], buf, 10));
	map<string, long long>::iterator itr;
	if((itr = mp.find(str)) != mp.end())
		return itr->second;
	long long s;
	if(box[i][1] == toy[j][1])
	{
		long long t = mymin(box[i][0], toy[j][0]);
		box[i][0] -= t, toy[j][0] -= t;
		int ii = i - (box[i][0] == 0), jj = j - (toy[j][0] == 0);
		s = dfs(ii, jj) + t;
		box[i][0] += t, toy[j][0] += t;
	}
	else
		s = mymax(dfs(i-1, j), dfs(i, j-1));
	mp.insert(make_pair(str, s));
	//cout<<i<<" "<<j<<" "<<box[i][0]<<" "<<box[j][0]<<" "<<s<<endl;
	return s;
}

int main()
{
	fstream in("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\data.txt");
	fstream out("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\ans.txt");

	int ntest;
	in>>ntest;
	for(int itest = 1; itest <= ntest; ++ itest)
	{
		mp.clear();
		in>>n>>m;
		for(int i = 0; i < n; ++ i)
		{
			in>>box[i][0]>>box[i][1];
			cout<<box[i][0]<<" "<<box[i][1]<<" ";
		}
		cout<<endl;

		for(int i = 0; i < m; ++ i)
		{
			in>>toy[i][0]>>toy[i][1];
			cout<<toy[i][0]<<" "<<toy[i][1]<<" ";
		}
		cout<<endl<<endl;
		if(itest == 98)
		{
			int a = 1;
		}
		out<<"Case #"<<itest<<": "<<dfs(n-1, m-1)<<endl;
	}

	in.close();
	out.close();

	return 0;
}