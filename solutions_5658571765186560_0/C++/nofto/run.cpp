#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		int X,R,C;
		scanf("%d %d %d",&X, &R, &C);
		string winner;
		switch(X){
			case 1: winner="GABRIEL"; break;
			case 2: winner = R*C%2==0 ? "GABRIEL" : "RICHARD"; break;
			case 3:
				if(R*C%3!=0 || R*C==3) winner="RICHARD";
				else winner = "GABRIEL";
				break;
			case 4:
				if(R*C%4!=0 || R*C<=8) winner="RICHARD";
				else winner = "GABRIEL";
				break;
		}
		printf("Case #%d: %s\n",t,winner.c_str());
	}
  return 0;
}
