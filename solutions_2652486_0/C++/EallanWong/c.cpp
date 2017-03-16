#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <ctime>

using namespace std;

#define maxn 110
#define datat int
#define ansdatat int

int n, m, k, r;
int x[maxn];

void init_deal(){
}

int main(){
	
	int tttt;
	scanf("%d", &tttt);
	for(int ttt = 1;ttt<=tttt;ttt++){
		printf("Case #%d: \n",ttt);
		scanf("%d%d%d%d", &r, &n, &m, &k);
		for (int i = 1; i<=r; i++)
		{
			for (int j = 1; j<=k; j++)
			{
				scanf("%d", &x[j]);
			}
			
			int y[3], z[3];
			z[0] = z[1] = z[2];
			bool got = false;
			for (y[0] = 2 ; y[0]<=5 && !got; y[0]++)
			for (y[1] = 2 ; y[1]<=5 && !got; y[1]++)
			for (y[2] = 2 ; y[2]<=5 && !got; y[2]++)
			{
				bool yes = true;
				for (int j = 1; j<=k; j++)
				if(x[j] == 1 ||
				   x[j] == y[0] || x[j] == y[1] || x[j] == y[2] ||
				   x[j] == y[0]*y[1] || x[j] == y[0]*y[2] || x[j] == y[1]*y[2] ||
				   x[j] == y[0]*y[1]*y[2])
				{
				}
				else{
					yes = false;
					break;
				}

				if(yes){
					z[0] = y[0];
					z[1] = y[1];
					z[2] = y[2];
					got = true;
					break;
				}

			}

			printf("%d%d%d\n", z[0], z[1], z[2]);


		}

	}
	

	return 0;
};

