#include <cstdlib>
#include <set>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm> 
#include <stack>
#include <queue>
#include<map>
using namespace::std;
int Case,X,R,C;


int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	cin >> Case;
	for (size_t z = 1; z <= Case; z++)
	{
		cin >> X >> R >> C;
		bool res=false;
		if (X <= 6&&R*C%X==0){
			if (R < C)swap(R, C);
			if (R >= X){
				if (X == 1)res = true;
				if (X == 2)res = true;
				if (X == 3 && C >= 2)res = true;
				if (X == 4 && C >= 3)res = true;
				if (X == 5 && C >= 4)res = true;
				if (X == 6 && C >= 4)res = true;
			}
		}
		if (res)printf("Case #%d: GABRIEL\n",z);
		else printf("Case #%d: RICHARD\n",z);
	}
}