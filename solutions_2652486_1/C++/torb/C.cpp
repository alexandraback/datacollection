#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <cstdio>
#include <ctime>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;

int main() {
  int TC; cin >> TC;
  srand(time(NULL));
  for (int t = 1; t <= TC; t++) {
    int wrong = 0;
    
    printf("Case #%d:\n", t);
    int R, N, M, K; cin >> R >> N >> M >> K;
    for(int i = 0; i < R; ++i) {
      vi nums(M+1, 0);
      for(int j = 0; j < K; ++j) {
        int num; cin >> num;
        for(int l = 2; l <= M; ++l) {
          int count = 0;
          while(num % l == 0) {
            count++;
            num /= l;
          }
          nums[l] = max(nums[l], count);
        }
      }
      vi results;
      for(int j = 5; j <= M; ++j) {
        for(int l = 0; l < nums[j]; ++l) {
          results.push_back(j);
        }
      }
      int num2 = 0, num3 = 0;
      for(int j = 0; j < nums[2]; ++j)
        num2++;
      for(int j = 0; j < nums[3]; ++j)
        num3++;
      while(results.size() < N) {
        set<int> s;
        for(int twos = 0; twos <= num2; ++twos) {
          for(int threes = 0; threes <= num3; ++threes) {
            int a = (twos > 0 ? 2*twos : 1) * (threes > 0 ? 3*threes : 1);
            if(a < 2 || a > M) continue;
            s.insert(a);
          }
        }
        vi picks(s.begin(), s.end());

        if(num2 || num3) {
          int pick = picks[rand()%picks.size()];
          int tmp = pick;
          int tmp2 = 0, tmp3 = 0;
          while(tmp % 2 == 0) {
            tmp2++;
            tmp /=2;
          }
          while(tmp % 3 == 0) {
            tmp3++;
            tmp /=3;
          }
          if (tmp2 <= num2 && tmp3 <= num3 && pick <= M) {
            results.push_back(pick);
            num2 -= tmp2;
            num3 -= tmp3;
          } else {
            //cout << pick <<  ' ' << num2 << ' ' << num3 << endl;
          }
        } else {
          results.push_back(rand()%(M-1) + 2);
        }
      }
      while(num2 || num3) {
        bool changed = false;
        for(int j = 0; j < results.size(); ++j) {
          if(results[j] * 2 <= M && num2) {
            results[j] *= 2;
            num2--;
            changed = true;
          }
          if(results[j] * 3 <= M && num3) {
            results[j] *= 3;
            num3--;
            changed = true;
          }
        }
        if(!changed) {
          wrong++;
          break;
        }
      }
      for(int j = 0; j < results.size(); ++j) {
        cout << results[j];
      }
      cout << endl;
      /*
      int remaining = 0;
      for(int j = 0; j < nums[2]; ++j)
        remaining++;
      for(int j = 0; j < nums[3]; ++j)
        remaining++;
      int numPer = 1;

      if(count < N) numPer = (remaining - 1)/(N-count) + 1;
      while(count < N) {
        vi p;
        for(int j = 0; j < nums[2]; ++j)
          p.push_back(2);
        for(int j = 0; j < nums[3]; ++j)
          p.push_back(3);
        set<int> poss;
        for(int j =1; j < 1<<p.size(); ++j) {
          int num = 1;
          int tot = 0;
          for(int k = 0; k < p.size(); ++k) {
            if(j & (1<<k)) {
              tot++;
              num *= p[k];
            }
          }
          if(num < 2 || num > M || tot < numPer) continue;
          poss.insert(num);
        }
        if(poss.size()) {
          vi pull(poss.begin(), poss.end());
          int use = pull[rand()%pull.size()];
          cout << use;
          for(int j = 2; j <=3; ++j) {
            while(use % j == 0) {
              use /= j;
              nums[j]--;
            }
          }
        } else {
          if(p.size()) {
            for(int j =1; j < 1<<p.size(); ++j) {
              int num = 1;
              for(int k = 0; k < p.size(); ++k) {
                if(j & (1<<k)) {
                  num *= p[k];
                }
              }
              if(num < 2 || num > M) continue;
              poss.insert(num);   
            }
            vi pull(poss.begin(), poss.end());
            int use = pull[rand()%pull.size()];
            cout << use;
            for(int j = 2; j <=3; ++j) {
              while(use % j == 0) {
                use /= j;
                nums[j]--;
              }
            }
          } else {
            cout << rand() % (M-1) + 2;
          }
        }
        count++;
      }
      cout << endl;
      */
    }
    //cout << wrong << endl;
  }


  return 0;
}
