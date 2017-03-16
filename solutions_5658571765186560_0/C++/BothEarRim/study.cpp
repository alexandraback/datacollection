#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <locale>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <climits>
#include <cfloat>
#include <map>
#include <functional>
using namespace std;
const double PI=acos(-1);

bool ans;
int row, col, x_in;

int main() // Problem D. Ominous Omino
{
	freopen("D-small-attempt0.in.txt", "r", stdin);
	freopen("output_D_small.txt", "w", stdout);

	int tc_N;
	scanf("%d", &tc_N);
	for(int tc=0; tc<tc_N; tc++)
	{
		scanf("%d %d %d", &x_in, &row, &col);
		if(row<col) swap(row, col);

		if(x_in==1) ans = true;
		else
		{
			if(row==1) ans = false;
			else if(row==2) ans = x_in==2;
			else if(row==3)
			{
				if(col==1) ans = false;
				else if(col==2) ans = x_in!=4;
				else ans = x_in==3; // col==3
			}
			else // row==4
			{
				if(col<=2) ans = x_in==2;
				else if(col==3) ans = true;
				else ans = x_in!=3; // col==4
			}
		}
		
		printf("Case #%d: %s\n", tc+1, ans? "GABRIEL":"RICHARD");
	}

	fclose(stdin);
	fclose(stdout);
    
    return 0;
}