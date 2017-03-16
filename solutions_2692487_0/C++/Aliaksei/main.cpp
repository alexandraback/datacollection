#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int st;
	cin >> st;
	for(int steps = 0; steps< st; steps++)
	{
		int a, n;
		cin >> a >> n;
		vector<int> v(n);
		for(int i = 0; i < n; ++i)
			cin >> v[i];
		sort(v.begin(), v.end());

		int best = 999999999, razm = a;
		for(int stop = 0; stop <= n; ++stop)
		{
			razm = a;
			int numb = 0;
			for(int i = 0; i < stop; ++i)
			{
				if(v[i]>=razm&&razm>1){
					while(v[i]>=razm)
					{
						++numb;					
						razm+=(razm-1);
					}
				}
				else if(v[i]>=razm&&razm==1){
					numb = 999999999;
					continue;					
				}
				razm+=v[i];
			}
			numb+=(n-stop);
			if(numb<best) best = numb;
		}
		printf("Case #%d: %d\n", steps+1, best);
	}

}