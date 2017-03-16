// R1C1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int ans(int r, int c, int w){
	int re=0;
	if((c+1)%w==0) re+=((c+1)/w-1)*(r-1);
	else re+=((c+1)/w)*(r-1);
	re+=c/w+(w-1);
	if(c%w!=0) re++;
	return re;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("D://CodeJam Practice//A-large.in", "r", stdin);
    freopen("D://CodeJam Practice//A-large.out", "w", stdout);

	int cases=0;
	cin>>cases;
	for(int i=0; i<cases; i++){
		int r, c, w;
		cin>>r>>c>>w;
		cout<<"Case #"<<i+1<<": "<<ans(r,c,w)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	system("PAUSE");

	return 0;
}

