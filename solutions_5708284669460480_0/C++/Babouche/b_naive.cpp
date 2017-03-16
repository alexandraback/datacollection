// solution by Olivier Marty

#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr << #a << " = " << (a) << endl;

char dict[101];
int dictoc[255]; // letter -> occurence
char word[101];
int K, L, S;

void parse() {
  scanf("%d%d%d%s%s", &K, &L, &S, dict, word);
  memset(dictoc, 0, sizeof(dictoc));
  for(int i = 0; i < K; i++)
    dictoc[dict[i]]++;
}

// word feasible
bool check() {
  for(int i = 0; i < L; i++)
    if(dictoc[word[i]] == 0)
      return false;
  return true;
}

void preKMP(string pattern, int f[])
{
  int m = pattern.length(), k;
  f[0] = -1;
  for (int i = 1; i < m; i++)
  {
    k = f[i - 1];
    while (k >= 0)
    {
      if (pattern[k] == pattern[i - 1])
        break;
      else
        k = f[k];
    }
    f[i] = k + 1;
  }
}

// number of occurence
int KMP_oc(const char* pattern, const char* target)
{
  int r = 0;
  int m = strlen(pattern);
  int n = strlen(target);
  int f[m];
  preKMP(pattern, f);
  int i = 0;
  int k = 0;
  while (i < n)
  {
    if (k == -1)
    {
      i++;
      k = 0;
    }
    else if (target[i] == pattern[k])
    {
      i++;
      k++;
      if (k == m) {
        r++;
        k--;
        i--;
        k = f[k];
      }
    }
    else
      k = f[k];
  }
  return r;
}

int max_oc;
int nb_w;
int nb_oc;

void naive(int depth, char* w) {
  if(depth == S) {
    w[depth] = '\0';
    int oc = KMP_oc(word, w);
    if(oc > max_oc || max_oc == -1)
      max_oc = oc;
    nb_oc += oc;
    nb_w++;
  }
  else {
    for(int i = 0; i < K; i++) {
      w[depth] = dict[i];
      naive(depth+1, w);
    }
  }
}

void solve() {
  max_oc = -1;
  nb_w = 0;
  nb_oc = 0;
  char w[10];
  naive(0, w);
  double r = ((double)max_oc) - ((double)nb_oc)/((double)nb_w);
  printf("%f", r);
}

/*
// word feasible
bool check() {
  for(int i = 0; i < L; i++)
    if(dictoc[word[i]] == 0)
      return false;
  return true;
}

int overlap() {
  // KMP
  int f[101];
  preKMP(word, f);
  int over = f[L-1];
  if(over > 0 || word[0] == word[L-1])
    over++;
  return over;
}

int maximum() {
  int over = overlap();
  return (S - overlap()) / (L - overlap());
}

double expected1() {
  double res = 1.;
  for(int i = 0; i < L; i++)
    res *= ((double)dictoc[word[i]])/((double)K);
  return res;
}

void solve() {
  if(!check())
    printf("0.0");
  else {
    double expected = expected1();
    double maxi = (double)maximum();
    printf("%.7f", (1. - expected)*maxi);
  }
}
*/

int main() {
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; i++) {
    parse();
    printf("Case #%d: ", i);
    solve();
    printf("\n");
		//fprintf(stderr, "%d / %d = %.2f | %.2f\n", i, T, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * T) / CLOCKS_PER_SEC);
  }
}
