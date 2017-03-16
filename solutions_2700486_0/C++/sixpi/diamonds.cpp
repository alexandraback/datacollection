#include "common.h"

using namespace std;

int layer_count(int layer)
{
  static map<int, int> layer_counts;

  if(layer_counts.count(layer) > 0)
    return layer_counts[layer];
  
  int sum = 0;
  for (int i = 1; i <= (2 * layer + 1); ++i)
  {
    sum += i;
  }

  layer_counts[layer] = sum;
  return sum;
}

int min_diamonds(const pair<int, int> &coord)
{
  static map<pair<int, int>, int> counts;

  if (counts.count(coord) > 0)
    return counts[coord];

  int layer = (coord.first + coord.second) / 2;

  if (coord.first == 0)
    return layer_count(layer);

  return (layer_count(layer - 1) + coord.second + 1);
}

int max_diamonds(const pair<int, int> &coord)
{
  static map<pair<int, int>, int> counts;

  if (counts.count(coord) > 0)
    return counts[coord];

  int layer = (coord.first + coord.second) / 2;

  return (layer_count(layer) - coord.first);
}

double P(pair<int, int> coord, int N)
{
  static map<tuple<int, int, int>, double> probs;

  tuple<int,int,int> lookup(coord.first, coord.second, N);
  if (probs.count(lookup) > 0)
    return probs[lookup];

  int min_count = min_diamonds(coord);
  int max_count = max_diamonds(coord);

  if (N < min_count)
    return 0.0;
  if (N >= max_count)
    return 1.0;
  
  if (coord.second == 0)
    return 0.5 + 0.5 * P(coord, N - 1);
  else
    return 0.5 * P(pair<int, int>(coord.first + 1, coord.second - 1), N - 1) +
      0.5 * P(coord, N - 1);
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

  int N, X, Y;
  for (int i = 0; i < T; ++i)
  {
    ifs >> N >> X >> Y;

    X = abs(X); // Problem is symmetric

    cout << "Case #" << (i+1) << ": " << P(pair<int, int>(X, Y), N) << endl;
  }

  return 0;
}
