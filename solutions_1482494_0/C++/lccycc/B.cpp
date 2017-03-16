#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 1000 + 10;
multimap<int,int> lv0,lv1;
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int runs = 1; runs <= T; runs++)
	{
		int n;
		scanf("%d",&n);
		lv0.clear();
		lv1.clear();
		for (int i = 0; i < n; i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			lv0.insert(make_pair(b,a));
		}
		int cnt = 0;
		int star = 0;
		while (!(lv0.empty() && lv1.empty()))
		{
			bool fd = false;
			for (map<int,int>::iterator it = lv0.begin(); it != lv0.end(); it++)
				if (it->first <= star)
				{
					star+=2;
					lv0.erase(it);
					fd = true;
					cnt++;
					break;
				}
			if (fd)
				continue;
			for (map<int,int>::iterator it = lv1.begin(); it != lv1.end(); it++)
				if (it->first <= star)
				{
					star++;
					lv1.erase(it);
					fd = true;
					cnt++;
					break;
				}
			if (fd)
				continue;
			for (map<int,int>::reverse_iterator it = lv0.rbegin(); it != lv0.rend(); it++)
				if( it->second <= star)
				{
					for (map<int,int>::iterator jt = lv0.begin(); jt != lv0.end(); jt++)
						if (jt->first == it->first && jt->second == it->second)
						{
							lv1.insert(make_pair(jt->first,jt->second));
							lv0.erase(jt);
							break;
						}
					star++;
					fd = true;
					cnt++;
					break;
				}
			if (!fd) break;
		}
		printf("Case #%d: ",runs);
		if (!(lv0.empty() && lv1.empty()))
			puts("Too Bad");
		else
			printf("%d\n",cnt);
	}
}
