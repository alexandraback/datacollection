#include <bits/stdc++.h>
using namespace std;

char a[1005];
deque<char> q;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("0.out","w",stdout);
	int T,_,i;
	for(scanf("%d",&T),_=1;_<=T;_++)
	{
		scanf("%s",a);
		printf("Case #%d: ",_);
		while(!q.empty())
			q.pop_back();
		q.push_front(a[0]);
		for(i=1;a[i];i++)
			if(a[i]>=q.front())
				q.push_front(a[i]);
			else
				q.push_back(a[i]);
		for(auto s:q)
			putchar(s);
		puts("");
	}
	return 0;
}
