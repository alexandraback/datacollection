#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
double d;
vector< pair<double, bool> > input;
vector<bool> Q;

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // input
    input.clear();
    Q.clear();
    scanf("%d", &N);
    for (int i = 0; i < 2 * N; ++i) {
      scanf("%lf", &d);
      input.push_back(make_pair(d, i < N));
    }
    sort(input.begin(), input.end());
    for (int i = 0; i < 2 * N; ++i)
      Q.push_back(input[i].second);
    
    // honest game
    int untakenNaomis = 0;
    int honestKevinPoints = 0;
    for (int i = 0; i < 2 * N; ++i)
      if (Q[i])
        untakenNaomis++;
      else if (untakenNaomis > 0) {
        honestKevinPoints++;
        untakenNaomis--;
      }
    
    // deceitful game
    int untakenKevins = 0;
    int deceitfulNaomiPoints = 0;
    for (int i = 0; i < 2 * N; ++i)
      if (!Q[i])
        untakenKevins++;
      else if (untakenKevins > 0) {
        deceitfulNaomiPoints++;
        untakenKevins--;
      }
    
    // output
    printf("Case #%d: %d %d\n", Ti, deceitfulNaomiPoints, N - honestKevinPoints);
  }
  return 0;
}
