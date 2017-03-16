#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> wall_east, wall_west;

void clear_wall()
{
  wall_east.clear();
  wall_west.clear();
  wall_east.reserve(10000000);
  wall_west.reserve(10000000);
}

int &height(int x)
{
  if (x >= 0)
  {
    if (x >= wall_east.size())
      wall_east.resize(x + 1, 0);
    return wall_east[x];
  }
  else
  {
    if (-x >= wall_west.size())
      wall_west.resize(-x + 1, 0);
    return wall_west[-x];
  }
}

int main()
{
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; ++case_num)
  {
    clear_wall();

    int N;
    cin >> N;
    vector<int> d(N), n(N), w(N), e(N), s(N), delta_d(N), delta_p(N), delta_s(N);

    map< int, vector<int> > next_attack;
    for (int t = 0; t < N; ++t)
    {
      cin >> d[t] >> n[t] >> w[t] >> e[t] >> s[t] >> delta_d[t] >> delta_p[t] >> delta_s[t];
      next_attack[d[t]].push_back(t);
    }
    
    int attacks_successful = 0;
    for (map< int, vector<int> >::iterator attack = next_attack.begin(); attack != next_attack.end(); ++attack)
    {
      int day = attack->first;
      cerr << "day " << day << endl;
      for (int ti = 0; ti < attack->second.size(); ++ti)
      {
	int t = attack->second[ti];
	bool success = false;
	for (int i = w[t]; i < e[t]; ++i)
	  if (height(i) < s[t])
	  {
	    success = true;
	    break;
	  }
	if (success)
	  ++attacks_successful;
      }
      cerr << " => " << attacks_successful << endl;

      for (int ti = 0; ti < attack->second.size(); ++ti)
      {
	int t = attack->second[ti];
	for (int i = w[t]; i < e[t]; ++i)
	  height(i) = max(height(i), s[t]);
      }

      for (int ti = 0; ti < attack->second.size(); ++ti)
      {
	int t = attack->second[ti];
	d[t] += delta_d[t];
	--n[t];
	w[t] += delta_p[t];
	e[t] += delta_p[t];
	s[t] += delta_s[t];
	if (n[t])
	  next_attack[d[t]].push_back(t);
      }

      next_attack.erase(attack);
    }

    cout << "Case #" << case_num << ": " << attacks_successful << endl;
  }
  return 0;
}
