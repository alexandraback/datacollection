#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int D[1009];
int H[1009];
int M[1009];

int hikers;
int h_start[19];
int h_speed[19];

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // init
    hikers = 0;
    printf("Case #%d: ", Ti);
    
    // input
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf(" %d %d %d", &D[i], &H[i], &M[i]);
      for (int h = 0; h < H[i]; ++h)
      {
        h_start[hikers] = D[i];
        h_speed[hikers] = M[i];
        hikers++;
      }
    }
    //printf("Number of hikers = %d\n", hikers);
    
    // special cases
    if (hikers <= 1)
    {
      printf("0\n");
      continue;
    }
    
    // two hikers
    if (hikers == 2 && (h_speed[0] == h_speed[1]))
    {
      printf("0\n");
      continue;
    }
    if (hikers == 2)
    {
      // make 1 faster than 0
      if (h_speed[0] < h_speed[1])
      {
        int t = h_start[0];
        h_start[0] = h_start[1];
        h_start[1] = t;
        t = h_speed[0];
        h_speed[0] = h_speed[1];
        h_speed[1] = t;
      }
      
      // time until hikers reach zero
      double fast_to_zero = 1.0 * h_speed[1] * (360 - h_start[1]) / 360;
      double slow_to_zero = 1.0 * h_speed[0] * (360 - h_start[0]) / 360;
      //int fast_to_zero = h_speed[1] * (360 - h_start[1]);
      //int slow_to_zero = h_speed[0] * (360 - h_start[0]);
      //printf("fast to zero %lf\n", fast_to_zero);
      //printf("slow to zero %lf\n", slow_to_zero);
      if (slow_to_zero < fast_to_zero)
      {
        printf("0\n");
        continue;
      }
      
      //double slow_position_when_fast_at_zero = 1.0 * h_start[0] + 360.0 * fast_to_zero / h_speed[0];
      //double time_to_catch = slow_position_when_fast_at_zero / (360.0 / h_speed[1] - 360.0 / h_speed[0]);
      double slow_position_when_fast_at_zero = 1.0 * h_start[0] + 360.0 * fast_to_zero / h_speed[0];
      double time_to_catch = slow_position_when_fast_at_zero / (360.0 / h_speed[1] - 360.0 / h_speed[0]);
      //printf("slow_position_when_fast_at_zero %lf\n", slow_position_when_fast_at_zero);
      //printf("time_to_catch %lf\n", time_to_catch);
      
      if (fast_to_zero + time_to_catch <= slow_to_zero)
        printf("1\n");
      else
        printf("0\n");
    }
  }
  return 0;
}
