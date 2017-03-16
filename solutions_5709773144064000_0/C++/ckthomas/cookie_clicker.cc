#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  int Nprob;
  cin >> Nprob;
  for (int np=0; np<Nprob; np++)
  { 
    double C, F, X;
    cin >> C >> F >> X;
    double best_time = X;
    double init_time = 0;
    for (int i=0; init_time < best_time; i++)
    {
      double cur_time = init_time + X / (2+i*F);
      if (cur_time < best_time)
        best_time = cur_time;
      init_time += C/(2+i*F);
    }
    cout << "Case #" << np+1 << ": ";
    printf("%.7f\n",best_time);
  }
}
