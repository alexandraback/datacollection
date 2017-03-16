#include <iostream>
#include <string>

using namespace std;

int main(){
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int cases;
  cin >> cases;
  for(int i=0; i<cases; ++i)
  {
    cout << "Case #" << i+1 << ": ";
    int N, S, p; cin >> N >> S >> p;
    int sum = 0;
    int specials = 0;
    for(int j=0; j<N; ++j)
    {
      int scoresum; cin >> scoresum;
      if(scoresum % 3 == 0)
      {
        if(scoresum/3 >= p)
        {
          sum++;
        }
        else if((scoresum/3)+1 >= p && (scoresum/3)-1 > -1 && specials < S)
        {
          sum++;
          specials++;
        }
      }
      else if(scoresum % 3 == 2)
      {
        if((scoresum/3)+1 >= p)
        {
          sum++;
        }
        else if((scoresum/3)+2 >= p && specials < S)
        {
          sum++;
          specials++;
        }
      }
      else
      {
        if((scoresum/3)+1 >= p)
        {
          sum++;
        }
      }
    }
    cout << sum << "\n";
  }
  return 0;
}