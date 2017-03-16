#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
deque<char> q;
char s[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;++cas)
	{
		q.clear();
		scanf("%s",s);
		for(int i=0;s[i]!='\0';++i)
		{
			if(q.empty()||s[i]>=q.front())q.push_front(s[i]);
			else q.push_back(s[i]);
		}
		printf("Case #%d: ",cas);
		for(int i=0;i<q.size();++i)
			putchar(q[i]);
		puts("");
	}
	return 0;
}
