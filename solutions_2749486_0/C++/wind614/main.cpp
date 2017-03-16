/*
FileName:  B.cpp
Created:  2013年05月12日 17时50分39秒
Author:  shiqi_614
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int N=205;
const int dx[]={0, 0,1,-1};//NSEW
const int dy[]={1,-1,0, 0};

int main()
{
	freopen("B-small-attempt4.in","r",stdin);
	freopen("B.out","w",stdout);

	int t,t_cnt=0;
	scanf("%d",&t);
	while(t--)
	{
	    int ed_x,ed_y;
		scanf("%d%d",&ed_x,&ed_y);

		string ans;

		string xx,yy;
		if(ed_x>0) xx="WE";
		else xx="EW";
		if(ed_y>0) yy="SN";
		else yy="NS";
		for(int i=0;i<abs(ed_x);i++) ans+=xx;
		for(int i=0;i<abs(ed_y);i++) ans+=yy;
		printf("Case #%d: %s\n",++t_cnt,ans.c_str());
	}
	return 0;
}

