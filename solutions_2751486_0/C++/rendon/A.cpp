#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;

const int BUFFER_SIZE = 1 * 1024;
const double EPS      = 10e-6;
const int MAX         = 100;
const int INF         = 1 << 30;

char buffer[BUFFER_SIZE];

char* read_line() 
{
  int ch, size = 0;
  while ((ch = getchar()) != '\n') buffer[size++] = ch;
  buffer[size] = '\0';
  return buffer;
}


set< pair<int, int> > S;

int main(int argc, char *argv[])
{
  int t, tc, n, i, j, k;
  string name;
  char vowels[] = "aeiou";

  scanf("%d", &t);

  for (tc = 1; tc <= t; tc++) {
    cin >> name >> n;

    int count = 0, a, b;
    int size = name.length();
    for (i = 0; i < size; i++) {
      bool found = false;
      for (j = size - 1; j - i + 1 >= n; j--) {
        int consonants = 0;
        for (k = 0; k < n; k++) {
          char ch = name[i+k];
          if (!strchr(vowels, ch))
            consonants++;
        }

        if (consonants == n) {
          count++;
          continue;
        }


        a = i;
        for (b = i + n; b <= j  && !found; b++) {
          if (!strchr(vowels, name[a]))
            consonants--;
          if (!strchr(vowels, name[b]))
            consonants++;
          a++;

          if (consonants >= n) {
            count++;
            break;
          }
        }
      }
    }
    printf("Case #%d: %d\n", tc, count);
  }


  return EXIT_SUCCESS;
}

