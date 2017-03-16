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

#define SYM_I 1
#define SYM_J 2
#define SYM_K 3

// index 0부터: 1, i, j, k, -1, -i, -j, -k
const int arr[8][8] = {
	{0, 1, 2, 3, 4, 5, 6, 7},
	{1, 4, 3, 6, 5, 0, 7, 2},
	{2, 7, 4, 1, 6, 3, 0, 5},
	{3, 2, 5, 4, 7, 6, 1, 0},
	{4, 5, 6, 7, 0, 1, 2, 3},
	{5, 0, 7, 2, 1, 4, 3, 6},
	{6, 3, 0, 5, 2, 7, 4, 1},
	{7, 6, 1, 0, 3, 2, 5, 4}
};
int iptLen, repeat_N, totLen, lf, mid, rt;
char iptStr[10005], totStr[10005];
bool ans;

int main() // Problem C. Dijkstra
{
	freopen("C-small-attempt1.in.txt", "r", stdin);
	freopen("output_C_small.txt", "w", stdout);

	int tc_N;
	scanf("%d", &tc_N);
	for(int tc=0; tc<tc_N; tc++)
	{
		ans = false;
		for(int i=0; i<10005; i++) totStr[i] = 0;
		scanf("%d %d\n%s", &iptLen, &repeat_N, iptStr);
		for(int i=0; i<repeat_N; i++) strcat(totStr, iptStr);
		totLen = strlen(totStr);

		bool flag[3];
		for(int i=0; i<3; i++) flag[i] = false;
		for(int i=0; i<iptLen; i++) flag[iptStr[i]-'i'] = true;

		int cnt = 0;
		for(int i=0; i<3; i++)
			if(flag[i]) cnt++;

		if(totLen>=3 && cnt>=2)
		{
			lf = totStr[0]-'h';
			if(lf==SYM_I)
			{
				mid = totStr[1]-'h';
				if(mid==SYM_J)
				{
					rt = totStr[2]-'h';
					for(int k=3; k<totLen; k++) rt = arr[rt][totStr[k]-'h'];
					if(rt==SYM_K) ans = true;
				}

				for(int j=2; j<totLen-1 && !ans; j++)
				{
					mid = arr[mid][totStr[j]-'h'];
					if(mid==SYM_J)
					{
						rt = totStr[j+1]-'h';
						for(int k=j+2; k<totLen; k++) rt = arr[rt][totStr[k]-'h'];
						if(rt==SYM_K) ans = true;
					}
				}
			}

			for(int i=1; i<totLen-2 && !ans; i++)
			{
				lf = arr[lf][totStr[i]-'h'];
				if(lf==SYM_I)
				{
					mid = totStr[i+1]-'h';
					if(mid==SYM_J)
					{
						rt = totStr[i+2]-'h';
						for(int k=i+3; k<totLen; k++) rt = arr[rt][totStr[k]-'h'];
						if(rt==SYM_K) ans = true;
					}
					for(int j=i+2; j<totLen-1 && !ans; j++)
					{
						mid = arr[mid][totStr[j]-'h'];
						if(mid==SYM_J)
						{
							rt = totStr[j+1]-'h';
							for(int k=j+2; k<totLen; k++) rt = arr[rt][totStr[k]-'h'];
							if(rt==SYM_K) ans = true;
						}
					}
				}
			}
		}

		printf("Case #%d: %s\n", tc+1, ans? "YES":"NO");
	}

	fclose(stdin);
	fclose(stdout);
    
    return 0;
}