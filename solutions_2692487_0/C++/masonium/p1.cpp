#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<pair<long, size_t>, long> memo;

long num_ops_aux(long player_mote, vector<long>& motes, size_t start);

long num_ops(long player_mote, vector<long>& motes, size_t start)
{
  auto idx = make_pair(player_mote, start);
  
  auto it = memo.find(idx);
  if (it != memo.end())
    return it->second;

  long answer = num_ops_aux(player_mote, motes, start);
  memo.insert(make_pair(idx, answer));
  
  return answer;
}

long num_ops_aux(long player_mote, vector<long>& motes, size_t start)
{
  if (start >= motes.size())
    return 0;
  
  while ((start < motes.size()) && (player_mote > motes[start]))
  {
    player_mote += motes[start];
    start++;
  }
  
  if (start >= motes.size())
    return 0;


  long remove_strat = num_ops(player_mote, motes, start+1);

  if (player_mote > 1)
    return 1 + min( num_ops(player_mote + player_mote - 1, motes, start),
                    remove_strat);
  else
    return 1 + remove_strat;
  
}

void solve_case(int casenum)
{
  memo.clear();
  
  vector<long> motes;
  size_t num_motes;
  long player_mote;

  cin >> player_mote;
  cin >> num_motes;
  
  motes.resize(num_motes);
  for (size_t i = 0; i < num_motes; ++i)
    cin >> motes[i];

  sort(motes.begin(), motes.end());
  
  cout << "Case #" << casenum << ": " << num_ops(player_mote, motes, 0) << "\n";
}

int main(int argc, char ** args)
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
  {
    solve_case(i);
  }

  return 0;
}
