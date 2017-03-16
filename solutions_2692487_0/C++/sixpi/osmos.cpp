#include "common.h"

using namespace std;

/**
   Returns the number of adds needed for a mote of size
   cur_size to absorb target_size. -1 if impossible
 */
int add_ops(int &cur_size, int target_size)
{
  if (cur_size == 1)
  {
    return -1;
  }

  int nadds = 0;
  while (cur_size <= target_size)
  {
    cur_size = 2 * cur_size - 1;
    ++nadds;
  }
  return nadds;
}

int min_ops(int A, int N, vector<int> &motes, vector<int> &sums)
{
  sort(motes.begin(), motes.end());
  sums[0] = A + motes[0];

  int cur_size = A;
  int nadds = 0;
  int total_adds = 0;
  for (int i = 0; i < N; ++i)
  {
//    cout << cur_size << " " << motes[i] << endl;
    if (cur_size <= motes[i])
    {
      nadds = add_ops(cur_size, motes[i]);
      if (nadds == -1)
        return N; // delete everything
      
      if (nadds > (N - i) &&
          (i == N - 1 || cur_size <= motes[i + 1]))
        return (total_adds + (N - i)); // delete rest

      total_adds += nadds;
      if (total_adds >= N)
        return N; // delete everything
    }
    else
    {
      cur_size += motes[i];
    }
  }

  return total_adds;
}

int min_ops2(int A, int N, vector<int> &motes)
{
  sort(motes.begin(), motes.end());

  int cur_size = A;
  int i = 0;
  int total_adds = 0;
  int remove_ops = 0;
  int total_ops = 0;
  int nadds;
  while (true)
  {
    // consume all we can
    while (i != N && cur_size > motes[i])
    {
      cur_size += motes[i];
      ++i;
    }

    if (i == N)
    {
      // we're done
      remove_ops = 0;
      break;
    }

    // compare removing rest of motes to adding motes until we can consume again
    remove_ops = (N - i);
    nadds = add_ops(cur_size, motes[i]);
    if (nadds == -1 || nadds >= remove_ops)
    {
      break;
    }
    else
    {
      total_adds += nadds;
    }
  }

  assert(total_adds + remove_ops <= N);
  return total_adds + remove_ops;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    exit(1);
  }

  ifstream ifs(argv[1]);

  int T;
  ifs >> T;

  int A, N;
  vector<int> motes;
  vector<int> sums;
  int minops;
  for (int i = 0; i < T; ++i)
  {
    // Read input
    ifs >> A >> N;
    motes.resize(N);
    sums.resize(N);
    for (int j = 0; j < N; ++j)
    {
      ifs >> motes[j];
    }
    
    cout << "Case #" << (i+1) << ": ";
    cout << min_ops2(A, N, motes);
    cout << endl;
  }

  return 0;
}
