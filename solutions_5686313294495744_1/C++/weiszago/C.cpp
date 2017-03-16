#include <bits/stdc++.h>
using namespace std;

map<string, int> a, b;
int n;
vector<pair<string, string> > gg;


typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

VI aaa, bbb;

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

VVI graph;

void solve()
{
  cin >> n;
  a.clear();
  b.clear();
  int aszam=0;
  int bszam=0;
  gg.clear();
  aaa.clear();
  bbb.clear();
  for (int i=0;i<n;i++)
  {
    string x, y;
    cin >> x>>y;
    if (a.find(x)==a.end())
    {
      a[x]=aszam;
      aszam++;
    }
    if (b.find(y)==b.end())
    {
      b[y]=bszam;
      bszam++;
    }
    gg.push_back(make_pair(x, y));
  }


  graph.clear();
  for (int i=0;i<aszam;i++)
  {
    VI sor;
    for (int j=0;j<bszam;j++)
    {
      sor.push_back(0);
    }
    graph.push_back(sor);
  }
  for (auto el : gg)
  {
    graph[a[el.first]][b[el.second]]=1;
  }

  /*for (int i=0;i<aszam;i++)
  {
    for (int j=0;j<bszam;j++)
    {
      cout << graph[i][j];
    }
    cout << endl;
  }*/
  cout << n-(aszam+bszam-BipartiteMatching(graph, aaa, bbb));
}

int main()
{
  freopen("C-large (1).in", "r", stdin);
  freopen("C-large.out", "w", stdout);
  ios_base::sync_with_stdio(false);

  int test;
  cin >> test;
  for (int t = 1;t<=test;t++) {
    cout << "Case #" << t<<": ";
    solve();
    cout << endl;
  }

  return 0;
}
