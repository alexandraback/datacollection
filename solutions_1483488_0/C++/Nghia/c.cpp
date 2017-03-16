#include "stdio.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int p10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int getPair(int n, int d, int p)
{
	int m = n / p10[p + 1];
	m += (n % p10[p+1]) * p10[d - p - 1];
	return m;
}

int cntpair(int n, int b)
{
	int d = 0;
	int v = n;
	while ( v>0 ) {
		v /= 10;
		++d;
	}	
	int res = 0;
	std::vector<int> cur;
	for(int j = 0; j < d - 1; ++j){
		int newNum = getPair(n, d, j);
		
		int fou = 0;
		for(int k = 0; k < cur.size(); ++k) 
			if (cur[k] ==newNum) {
				fou = 1;
				break;
			}
		if (!fou && newNum > n && newNum <= b) {
			//printf("%d %d\n", n, newNum);
			++res;
			cur.push_back(newNum);
		}	
	}
	return res;	
}

int main()
{
	ifstream fin("c.txt");
	ofstream fout("c.res");
	int T;
	fin >> T;
	for(int i = 0; i < T; ++i)
	{
		int a,b;
		fin >> a >> b;
		int res = 0;
		for(int j = a; j <= b; ++j)
		{
			res += cntpair(j, b);	
		}
		fout << "Case #"<<i+1<<": "<<res<<endl;
		//printf("----\n");
	}						
	return 0;
}			

