#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int Nprob;
  cin >> Nprob;
  for (int np=0; np<Nprob; np++)
  { 
    int N;
    cin >> N;
    vector<double> Naomi(N,0);
    vector<double> Ken(N,0);
    for (int i=0; i<N; i++)
      cin >> Naomi[i];
    for (int i=0; i<N; i++)
      cin >> Ken[i];
    sort(Naomi.begin(), Naomi.end());
    sort(Ken.begin(), Ken.end());
    int war_result = 0;
    int Ken_offset = 0;
    for (int i=0; i+Ken_offset<N; i++)
    {
      while (i+Ken_offset<N && Naomi[i] > Ken[i+Ken_offset])
      {
        Ken_offset++;
        war_result++;
      }
    }
    int deceitful_result = 0;
    for (int j=0; j<N; j++)
    {
      int candidate_result = 0;
      for (int i=j; i<N; i++)
        if (Naomi[i] > Ken[i-j])
          candidate_result++;
      if (candidate_result > deceitful_result)
        deceitful_result = candidate_result;
    }
    cout << "Case #" << np+1 << ": "
         << deceitful_result << " " << war_result << "\n";
  }
}
