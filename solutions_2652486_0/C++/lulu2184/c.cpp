#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;

vector <string> ans;
vector <int> v;
set <int> s;
int a[1010],n,m,K,R;

void gen(int x,int y)
{
	if (x>n) { s.insert(y);return; }
	gen(x+1,y);gen(x+1,v[x-1]*y);
}

void dfs(int x)
{
	if (x>n) 
	{
		s.clear();
		gen(1,1);
		bool flag=true;
		for (int i=1;i<=K;i++) if (s.find(a[i])==s.end()) { flag=false;break; }
		if (flag)
		{
			string ss;ss.clear();
			for (int i=0;i<v.size();i++) ss+=char(v[i]+48);
			ans.push_back(ss);
		}
		return;
	}
	for (int i=2;i<=m;i++) 	v.push_back(i),dfs(x+1),v.pop_back();
}

int main()
{
	freopen("c.in","r",stdin);
	printf("Case #1:\n");
	scanf("%d",&n);
	scanf("%d%d%d%d",&R,&n,&m,&K);
	while (R--)
	{
		for (int i=1;i<=K;i++) scanf("%d",&a[i]);
		ans.clear();
		dfs(1);
		cout<<ans[rand()%ans.size()]<<endl;
	}

	return 0;
}