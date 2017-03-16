#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_CAR_LEN  1000
#define MAX_N  100

int n;
char cars[MAX_N][MAX_CAR_LEN];
char clen[MAX_N];

void read_input()
{
  scanf("%d",&n);
  for(int i=0; i<n; i++) {
    scanf("%s",cars[i]);
    clen[i] = strlen(cars[i]);
  }
}

int permutation[MAX_N];

bool astarted[26];
bool aended[26];

bool check()
{
  for(int i=0; i<26; i++) {
    astarted[i] = false;
    aended[i] = false;
  }

  char lastchar = '*';
  for(int i=0; i<n; i++) {
    int cnum = permutation[i];
    char *p = cars[cnum];
    for(int j=0; j<clen[cnum]; j++) {
      char curchar = *p;
      p++;
      if(curchar == lastchar)
        continue;
      if(lastchar != '*')
        aended[lastchar-'a'] = true;
      if(aended[curchar-'a']==true)
        return false;
      lastchar = curchar;
    }
  }
  return true;
}

void solve(int t)
{
  read_input();
  for(int i=0; i<n; i++)
    permutation[i] = i;
  int count = 0;
  bool res;
  do {
    if(check())
      count++;
  } while(next_permutation(permutation, permutation+n));
  printf("Case #%d: %d\n",t+1,count);
}

main()
{
  int tt;
  scanf("%d",&tt);
  for(int i=0; i<tt; i++)
    solve(i);
}
