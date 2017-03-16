#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int flag[10][20], X, m, n;
vector < pair<int,int> > a;
set < vector < pair<int,int> > > s[7], good;

vector < pair<int,int> > normalize(vector < pair<int,int> > a)
{
  int minY = 100, minX = 100;
  for (auto u : a) 
  {
    minY = min(minY, u.second);
    minX = min(minX, u.first);
  }
  
  for (int i = 0; i < int(a.size()); i++)
  {
    a[i].first -= minX;
    a[i].second -= minY;
  }
  
  sort(a.begin(), a.end());
  return a;
}

void generate(int id, int x, int y, int neighbor, int n)
{
  flag[x][y] = 1;
  a.push_back(make_pair(x, y));
  
  if (id + 1 == n) s[n].insert(normalize(a));
  else
    for (int i = neighbor; i <= id; i++)
      for (int z = 0; z < 4; z++)
      {
        int xx = a[i].first + dx[z], yy = a[i].second + dy[z];
        if ((xx > 0 || (xx == 0 && yy > 10)) && !flag[xx][yy])
          generate(id + 1, xx, yy, i, n);
      }
      
  flag[x][y] = 0;
  a.pop_back();
}

void attempt()
{
  for (int mask = 1; mask < 1 << (m * n); mask++)
    if (__builtin_popcount(mask) == X)
    {
      vector < pair<int,int> > a[2];
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          a[mask >> (i * n + j) & 1].push_back(make_pair(i, j));
      
      a[0] = normalize(a[0]);
      a[1] = normalize(a[1]);
      
      if (s[X].count(a[0]) && s[X].count(a[1]))
      {
        good.insert(a[0]);
        good.insert(a[1]);
      }
    }
}

int main()
{
  for (int n = 1; n <= 6; n++)
  {
    memset(flag, 0, sizeof flag);
    generate(0, 0, 10, 0, n);
  }
  
	freopen("d.in", "r", stdin); 
	freopen("d.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		cin >> X >> m >> n;
    int ans = 0;
    if (X < 7 && X * 2 == m * n)
    {
      good.clear();
      attempt();
      swap(m, n);
      attempt();
      ans = good.size() == s[X].size();
    }
    
		printf("Case #%d: ", noTest);
    cout << (ans ? "GABRIEL" : "RICHARD") << endl;
	}
}
