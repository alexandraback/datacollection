#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

typedef long long answer_type;

long long solve()
{
  long long answer = 0;
  vector < long long > wall(1000, 0);

  int tribes;
  cin >> tribes;
  vector < long long > d(tribes);
  vector < long long > n(tribes);
  vector < long long > w(tribes);
  vector < long long > e(tribes);
  vector < long long > s(tribes);
  vector < long long > delta_d(tribes);
  vector < long long > delta_p(tribes);
  vector < long long > delta_s(tribes);

  vector < pair < long long, int > > days(0);

  for (int i = 0; i < tribes; ++i)
  {
    cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
    w[i] += 300;
    e[i] += 300;
  }

  for (int i = 0; i < tribes; ++i)
    for (int j = 0; j < n[i]; ++j)
      days.push_back(make_pair(d[i] + delta_d[i] * j, i));

  sort(days.begin(), days.end());

  for (int i = 0; i < days.size(); ) 
  {
    long long day = days[i].first;
    int last = i;
    for (int j = i; j < days.size(); ++j)
    {
//      cerr << days[j].first << " " << days[j].second << endl;

      if (days[j].first == day)
      {
        last = j;
      }
      else
        break;
    }

    for (int j = i; j <= last; ++j)
    {
      int tribe = days[j].second;
      for (int r = w[tribe]; r < e[tribe]; ++r)
        if (wall[r] < s[tribe])
        {
//          cerr << "day: " << day << " tribe: " << tribe << " w: " << w[tribe] << " e: " << e[tribe] << " s: " << s[tribe] << " wall: " << wall[r] << endl;
          answer++;
          break;
        }
    }

    for (int j = i; j <= last; ++j)
    {
      int tribe = days[j].second;
      for (int r = w[tribe]; r < e[tribe]; ++r)
        wall[r] = max(wall[r], s[tribe]);

      s[tribe] += delta_s[tribe];
      w[tribe] += delta_p[tribe];
      e[tribe] += delta_p[tribe];
    }

    i = last + 1;
  }

  return answer;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int tests_number;
  scanf("%d", &tests_number);

  for (int test = 1; test <= tests_number; ++test)
  {
    answer_type answer = solve();
    cout << "Case #" << test << ": " << answer << endl;
  }
  
  return 0;
}
