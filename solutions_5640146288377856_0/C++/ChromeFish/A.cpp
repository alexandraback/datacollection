#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
ifstream in("A.in");
ofstream out("A.out");


int ans;

int r,c,w;

int check(int bit)
{
	int sum =0;
	for (int i=0; i<c-w+1; i++)
		if (((1<<i) & bit) != 0)
			sum++;
	return sum;
}

int dfs(int num, int vis, int no)
{
	int minN = c;
	for (int i=0; i<c; i++)
		if (((1<<i) & vis) == 0)
		{
			int v2 = vis + (1<<i);
			int tmp = 0;
			for (int j=max(0,i-w+1); j<=i; j++)
				tmp+=(1<<j);
			int no1= no & tmp;
			int no2= no & (((1<<(c-w+1))-1) - tmp);
			int n1, n2;
			n1 = check(no1);
			n2 = check(no2);
			int maxn = 0;
			if (n1 > 1)
				maxn = max(maxn,1+dfs(num+1, v2, no1));
			else
				if (n1 == 1)
					maxn = max(maxn, w-num);
			if (n2 > 1)
				maxn = max(maxn,1+dfs(num, v2, no2));
			else
				if (n2 == 1)
					maxn = max(maxn, 1+w-num);
			minN = min(minN, maxn);
		}
	return minN;
}

int main()
{
	int T;
	in>>T;
	for (int i=1; i<=T; i++)
	{
		in>>r>>c>>w;
		if (r==1)
		{
			ans = dfs(0,0,(1<<(c-w+1))-1);
		}
		out<<"Case #"<<i <<": "<<ans<<endl;
	}
}