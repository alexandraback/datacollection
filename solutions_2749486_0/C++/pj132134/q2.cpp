#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

string north = "N";
string south = "S";
string east = "E";
string west = "W";


//class mycomparison
//{
//public:
//	bool operator() (int lhs, int rhs) const
//	{
//		return lhs > rhs;
//	}
//};  //ascending order


int main ()
{
	int no_testcases;
	scanf("%d", &no_testcases);
	
	
	for (int i=0; i<no_testcases; i++) {
		int X,Y;
		scanf("%d",&X);
		scanf("%d",&Y);
		string answer = "";
		
		int ind = 0;
		int x =0,y = 0;
		
		int count = 1;
		
		if (X>0) {
			ind = 1; /// go west 1st
		}
		
		while (x != X) {
			//printf("x,count = %d%d\n",x,count);
			if (ind == 0) {  // go east
				answer+=east;
				x+= count;
				ind = 1;
				
			}
			else {
				answer+=west;
				x-=count;
				ind = 0;
			}
			count++;
		}
		if (Y>0) {
			ind = 1; /// go south 1st
		}
		else {
			ind = 0;
		}

		while (y != Y) {
			if (ind == 0) {  // go north
				answer+=north;
				y+= count;
				ind = 1;
				
			}
			else {
				answer+=south;
				y-=count;
				ind =0;
			}
			count++;
		}
		answer[answer.length()] = '\0';
		
		printf("Case #%d: %s\n",i+1,&answer[0]);
		
	}
	
	return 0;
}