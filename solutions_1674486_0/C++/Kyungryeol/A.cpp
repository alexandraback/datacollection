#include <cstdio>
#include <queue>
#include <set>
#include <vector>

using namespace std;

bool a[1024];
int b[1024];
set<int> s[1024];
vector<int> v[1024];

int main()
{
	FILE *in = fopen("A-small-attempt0.in", "r");
	FILE *out = fopen("output.txt", "w");

	//in = stdin;
	//out = stdout;
	int tn, ti = 0;
	fscanf(in, "%d", &tn);
	while(tn--)
	{
		int n;
		fscanf(in, "%d", &n);
		for(int i = 0; i < n; ++i)
		{
			a[i] = false;
			s[i].clear();
			v[i].clear();
		}
		for(int i = 0; i < n; ++i)
		{
			fscanf(in, "%d", &b[i]);
			for(int j = 0; j < b[i]; ++j)
			{
				int t;
				fscanf(in, "%d", &t);
				v[t-1].push_back(i);
			}
		}
		fprintf(out, "Case #%d: ", ++ti);
		queue<int> q;
		for(int i = 0; i < n; ++i)
		{
			if(b[i] == 0) 
			{
				q.push(i);
				s[i].insert(i);
				a[i] = true;
			}
		}
		while(!q.empty())
		{
			int x = q.front(); q.pop();
			int sz = v[x].size();
			for(int i = 0; i < sz; ++i)
			{
				int r = v[x][i];
				for(set<int>::iterator it = s[x].begin(); it != s[x].end(); ++it)
					if(s[r].find(*it) == s[r].end()) s[r].insert(*it);
					else goto yes;
				if(!a[r]) {a[r] = true; q.push(r);}
			}
		}
		fprintf(out, "No\n");
		continue;
yes:;
		fprintf(out, "Yes\n");
	}
}

/*
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0
*/