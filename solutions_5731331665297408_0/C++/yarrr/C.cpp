#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <stdint.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <bitset>
#include <deque>
#include <list>
#include <stack>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define foreach(it, v) for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define sz(v) int((v).size())

typedef pair < int, int > edge_t;

bool is_smaller(const string & first, const string & second)
{
  if(second.empty())
    return true;
  return first < second;
}

bool cannot(int edges_count, const vector < edge_t > & edges, int from, int to)
{
  for(int i = 0; i < edges_count; i++)
  {
    if(edges[i].first == from && edges[i].second == to)
      return false;
    if(edges[i].first == to && edges[i].second == from)
      return false;
  }
  return true;
}

bool check_path(int vertexes_count, int edges_count,
                const vector < edge_t > & edges,
                 vector < int > history)
{
  //history = {4, 1, 2, 3, 0};
  //cout << "CHECK" << endl;
  stack < int > path;
  //cout << "START: " << history[0] << endl;
  path.push(history[0]);
  for(int i = 1; i < vertexes_count; i++)
  {
    int target = history[i];
    //cout << "GO: " << target << endl;
    while(!path.empty() && cannot(edges_count, edges, path.top(), target))
    {
      //cout << "REMOVE: " << path.top() << endl;
      path.pop();
    }
    if(path.empty())
    {
      //cout << "FAIL" << endl;
      return false;
    }
    path.push(target);
  }
  //cout << "OK" << endl;
  return true;
}

void rec(int step, int vertexes_count, int edges_count,
         const vector < string > & zip_codes,
         const vector < edge_t > & edges,
         vector < bool > & used,
         vector < int > & history,
         string & result)
{
  if(step == vertexes_count)
  {
    string current;
    for(int i = 0; i < vertexes_count; i++)
    {
      //cout << "ADD: " << history[i] << endl;
      current += zip_codes[history[i]];
    }
    //cout << "PATH: " << current << endl;
    if(is_smaller(current, result) &&
       check_path(vertexes_count, edges_count, edges, history))
    {
      result = current;
    }
  }
  else
  {
    for(int i = 0; i < vertexes_count; i++)
    {
      if(!used[i])
      {
        used[i] = true;
        history[step] = i;
        rec(step + 1, vertexes_count, edges_count, zip_codes, edges, used, history, result);
        used[i] = false;
      }
    }
  }
}

string solve_dumb(int vertexes_count, int edges_count,
                  const vector < string > & zip_codes,
                  const vector < edge_t > & edges)
{
  string result;
  vector < bool > used(vertexes_count, false);
  vector < int > history(vertexes_count);
  rec(0, vertexes_count, edges_count, zip_codes, edges, used, history, result);
  assert(!result.empty());
  return result;
}

void solve()
{
  int vertexes_count, edges_count;
  cin >> vertexes_count >> edges_count;
  vector < string > zip_codes(vertexes_count);
  for(int i = 0; i < vertexes_count; i++)
    cin >> zip_codes[i];
  vector < edge_t > edges(edges_count);
  for(int i = 0; i < edges_count; i++)
  {
    cin >> edges[i].first >> edges[i].second;
    --edges[i].first;
    --edges[i].second;
  }
  cout << solve_dumb(vertexes_count, edges_count, zip_codes, edges);
}

int main()
{
  int tests;
  cin >> tests;
  for(int test = 1; test <= tests; test++)
  {
    cout << "Case #" << test << ": ";
    solve();
    cout << endl;
  }
  return 0;
}