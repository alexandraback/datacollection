/*
 * test.cpp
 *
 *  Created on: 2013-04-13
 *      Author: fudq
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
int n,m;
int f[102][102];

bool fun(int a,int b)
{
	int flag_t1,flag_t2;
	flag_t1=0;flag_t2=0;
	//row_up
	for(int i=a-1;i>=0;i--)
		if(f[i][b] > f[a][b])
		{
			flag_t1=1;
			break;
		}
	//row_down
	for(int i=a+1;i<n;i++)
		if(f[i][b] > f[a][b])
		{
			flag_t2=1;
			break;
		}
	if(flag_t1==0 && flag_t2==0)
		return true;

	flag_t1=0;flag_t2=0;
	//column_left
	for(int i=b-1;i>=0;i--)
		if(f[a][i] > f[a][b])
		{
			flag_t1=1;
			break;
		}
	//column_right
	for(int i=b+1;i<m;i++)
		if(f[a][i] > f[a][b])
		{
			flag_t2=1;
			break;
		}
	if(flag_t1==0 && flag_t2==0)
		return true;
	return false;
}

bool jud()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(fun(i,j) == false)
				return false;
		}
	return true;
}

int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&f[i][j]);
		printf("Case #%d: ",cas++);
		if(jud())
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}
