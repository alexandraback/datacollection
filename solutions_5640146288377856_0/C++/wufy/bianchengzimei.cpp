//============================================================================
// Name        : bianchengzimei.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
int main()
{

	int T;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		int r,c,w;
		cin>>r>>c>>w;
		int tmp;
		if(c%w!=0)tmp=(c/w)*r+w;
		else tmp=(c/w)*r+w-1;
		cout<<tmp<<endl;
	}
	return 0;
}
