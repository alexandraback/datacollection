#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

set<pair<int,int> > s;

int calcbit(int x)
{
	int ans = 0;
	while(x)
	{
		ans ++;
		x /= 10;
	}
	return ans;
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("C-small-attempt0.in","r",stdin);
	freopen("C-large.in","r",stdin);
	freopen("1.out","w",stdout);
	int testcase;
	scanf("%d\n",&testcase);
	for(int t = 1; t <= testcase; t ++)
	{
		s.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		
		int bit = calcbit(a),ten=1;
		for(int i = 1; i < bit; i ++) ten *= 10;

		int ans = 0;
		for(int i = a; i <= b; i ++)
		{
			int tmp = i;
			for(int j = 1; j < bit; j ++)		// loop (bit-1) times
			{
				int x = tmp%10;
				tmp /= 10;
				tmp += x*ten;
				
				if(a <= tmp && tmp <= b && i < tmp)
				{
					s.insert(make_pair(i,tmp));
				}
			}
		}
		
		printf("Case #%d: %d\n",t,s.size());
	}
}
