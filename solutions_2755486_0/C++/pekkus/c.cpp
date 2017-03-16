#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF 100000000

typedef struct tribe
{
  int attack_day;
  int n_attacks;
  int w_first_attack;
  int e_first_attack;
  int strength;
  int delta_days;
  int delta_dist;
  int delta_strength;

}tribe;

bool operator<(const tribe& a, const tribe& b) {
    return a.attack_day > b.attack_day;
}

tribe generate_new_tribe(tribe a)
{
  tribe res;
  res.attack_day = a.attack_day + a.delta_days;
  res.n_attacks = a.n_attacks - 1;
  res.w_first_attack = a.w_first_attack + a.delta_dist*2;
  res.e_first_attack = a.e_first_attack + a.delta_dist*2;
  res.strength = a.strength + a.delta_strength;
  res.delta_days = a.delta_days;
  res.delta_dist = a.delta_dist;
  res.delta_strength = a.delta_strength;
  return res;
}

bool attack(tribe t, vi &wall, vi &newWall)
{
  bool res = false;
  for(int i = t.w_first_attack; i <= t.e_first_attack; ++i)
  {
    if (wall[i] < t.strength)
    {
      res = true;
      newWall[i] = t.strength;
    }
  }
  if (res)
  {
    //cout << "Attack on day " << t.attack_day << " from " << t.w_first_attack << " to " << t.e_first_attack << " succeeded." << endl;
  }
  return res;
}

int main()
{
  int T; cin >> T;
  for(int test_case = 1; test_case <= T; ++test_case)
  {
    int N; cin >> N;
    priority_queue<tribe> pq;
    int res = 0;
    vi wall(5000, 0);
    vi newWall(5000, 0);
    int mid = 2500;
    for(int i = 0; i < N; ++i)
    {
      tribe t;
      cin >> t.attack_day >> t.n_attacks >> t.w_first_attack >> t.e_first_attack >> t.strength >> t.delta_days >> t.delta_dist >> t.delta_strength;
      t.w_first_attack *= 2;
      t.e_first_attack *= 2;
      t.w_first_attack += mid;
      t.e_first_attack += mid;
      pq.push(t);
    }
    int prevDay = 0;
    while(pq.size())
    {
      tribe now = pq.top();
      pq.pop();
      if (now.attack_day != prevDay)
      {
        prevDay = now.attack_day;
        wall = newWall;
        newWall = vi(5000);
        for(int i = 0; i < 5000; ++i)
        {
          newWall[i] = wall[i];
        }
      }
      
      res += attack(now, wall, newWall);

      tribe next_attack = generate_new_tribe(now);
      if (next_attack.n_attacks > 0)
      {
        pq.push(next_attack);
      }
    }
    printf("Case #%d: %d\n", test_case, res);
  }
}

