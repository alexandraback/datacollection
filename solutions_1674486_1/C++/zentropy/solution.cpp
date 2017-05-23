#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;

bool is_diamond(const vector< vector<unsigned int> >& adjs,unsigned int root)
{
	size_t size = adjs.size();
	vector<bool> visited(size,false);
	vector<unsigned int> que(size*10);
	size_t quein = 0,queout = 0;
	que[quein] = root;++quein;
	visited[root] = true;
	for(;queout < quein;++queout)
	{
		unsigned int u = que[queout];
		for(size_t i = 0;i < adjs[u].size();++i)
		{
			unsigned int v = adjs[u][i] - 1;
			if(visited[v]) return true;
			visited[v] = true;
			que[quein] = v;++quein;
		}
	}
	return false;
}

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0;scanf("%d",&n);
		vector< vector<unsigned int> > adjs(n);
		for(unsigned int i = 0;i < n;++i)				// n*m
		{
			unsigned int m = 0;scanf("%d",&m);
			adjs[i].resize(m);
			for(unsigned int k = 0;k < m;++k) scanf("%d",&adjs[i][k]);
		}

		bool ans = false;
		for(unsigned int i = 0;i < n;++i)				// n*m*n
		{
			if(is_diamond(adjs,i)) { ans = true;break; }
		}

		printf("Case #%u: %s\n",iCases,(ans?"Yes":"No"));
	}
	return 0;
}