/*
 * =====================================================================================
 *
 *       Filename:  gcj.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年04月14日 11时54分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  
 *        Company:  hit-ACM-Group
 *
 * =====================================================================================
 */
#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
set<pair<int, int> > s;
int main()
{
	int a, b, t;
	scanf("%d", &t);
	for(int i = 0;i < t;i++)
	{
		s.clear();
		scanf("%d %d", &a, &b);
		for(int j = a;j <= b;j++)
		{
			char buf[1024];
			sprintf(buf, "%d%d", j, j);
			int len = strlen(buf) / 2;
			int n = j, m;
			for(int i = 1;i < len;i++)
			{
				if(buf[i] == '0') continue;
				m = 0;
				for(int k = 0;k < len;k++) m = m * 10 + buf[i + k] - '0';
				if(n < m && m <= b) s.insert(make_pair(n, m));
			}
		}
		printf("Case #%d: %d\n", i + 1, s.size());
	}
	return 0;
}
