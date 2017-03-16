#include <cassert>
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <list>
#include <algorithm>

#include <map>

using namespace std;

typedef unsigned long long ull_t;

int main ()
{
  freopen ("in.txt", "rb", stdin);
  freopen ("out.txt", "wb", stdout);

  int T;
  scanf ("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    printf ("Case #%d: ", t);

    int J, P, S, K;
    scanf ("%d %d %d %d", &J, &P, &S, &K);

    int days_n = 0;
    int fashions_set = 0;
    
    if (J == 3 && P == 3 && S == 3) {
      map< pair<int, int>, int > j_p_cnt;
      map< pair<int, int>, int > j_s_cnt;
      map< pair<int, int>, int > p_s_cnt;
  
      for (int j = 1; j <= J; j++) {
        for (int p = 1; p <= P; p++) {
          for (int s = 1; s <= S; s++) {
          pair<int, int> j_p = make_pair (j, p);
          pair<int, int> j_s = make_pair (j, s);
          pair<int, int> p_s = make_pair (p, s);
  
          if (j_p_cnt[j_p] == K || j_s_cnt[j_s] == K || p_s_cnt[p_s] == K)
            continue;
  
            ++j_p_cnt[j_p];
            ++j_s_cnt[j_s];
            ++p_s_cnt[p_s];
  
            days_n++;
            fashions_set |= (1u << ((j - 1) * P * S + (p - 1) * S + (s - 1)));
          }
        }
      }
    } else {
      for (int i = 0; i < (1u << (J * P * S)); i++) {
        int days_n_l = 0;
  
        bool is_ok = true;
  
        map< pair<int, int>, int > j_p_cnt;
        map< pair<int, int>, int > j_s_cnt;
        map< pair<int, int>, int > p_s_cnt;
  
        for (int q = 0; q < J * P * S; q++) {
          if (i & (1u << q)) {
            unsigned int j = 1 + q / (P * S);
            unsigned int p = 1 + (q - (j - 1) * P * S) / S;
            unsigned int s = 1 + (q - (j - 1) * P * S - (p - 1) * S);
  
            assert (j <= J && p <= P && s <= S);
  
  	  pair<int, int> j_p = make_pair (j, p);
  	  pair<int, int> j_s = make_pair (j, s);
  	  pair<int, int> p_s = make_pair (p, s);
  
    	  if (j_p_cnt[j_p] == K || j_s_cnt[j_s] == K || p_s_cnt[p_s] == K) {
    	    is_ok = false;
            }
    
    	  ++j_p_cnt[j_p];
            ++j_s_cnt[j_s];
            ++p_s_cnt[p_s];
  
            days_n_l++;
          }
        }
  
        if (is_ok) {
          if (days_n_l > days_n) {
            days_n = days_n_l;
            fashions_set = i;
          }
        }
      }
    }

    printf ("%d\n", days_n);
    for (int q = 0; q < J * P * S; q++) {
      if (fashions_set & (1u << q)) {
        unsigned int j = 1 + q / (P * S);
        unsigned int p = 1 + (q - (j - 1) * P * S) / S;
        unsigned int s = 1 + (q - (j - 1) * P * S - (p - 1) * S);
      
        printf ("%u %u %u\n", j, p, s);
      }
    }
  }

  fclose (stdin);
  fclose (stdout);

  return 0;
}
