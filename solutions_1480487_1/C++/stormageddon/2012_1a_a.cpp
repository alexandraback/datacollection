#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
  int cases = 0;
  cin >> cases;
  for (int c = 1; c <= cases; c++)
  {
    cout << "Case #" << c << ":";
    int N = 0;
    cin >> N;
    vector<int> scores;
    int total = 0;
    int score = 0;
    for (int i = 1; i <= N; i++)
    {
      cin >> score;
      scores.push_back(score);
      total += score;
    }
    int final_total = 2* total;
    double minimum_score = static_cast<double>(final_total)/ static_cast<double>(scores.size());
    cout.precision(6);
    int vote_split = scores.size();
    vector<int> sorted_scores = scores;
    sort(sorted_scores.begin(), sorted_scores.end(), greater<int>());
    int k = 0;
    while (sorted_scores[k] >= minimum_score)
    {
        vote_split--;
        final_total -= sorted_scores[k];
        minimum_score = static_cast<double>(final_total)/ static_cast<double>(vote_split);
        k++;
    }
    for (int j = 0; j < scores.size(); j++)
    {
      if (static_cast<double>(scores[j]) >= minimum_score)
      {
        cout << " " << fixed << 0.0;
        continue;
      }
      double needs = ( minimum_score - static_cast<double>(scores[j])) / static_cast<double>(total);
      cout << " " << fixed << needs * 100.0;
    }
    cout << endl;
  }
  return 0;
}



    
