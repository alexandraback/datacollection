#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<pii, pii> line;

#define F first
#define S second

char str[2000];


int main()
{
  int i, j;
  int n;
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    scanf(" %s", str);

    deque<char> d;
    d.push_back(str[0]);
    for (j = 1; str[j]; j++)
      if (str[j] >= d.front())
        d.push_front(str[j]);
      else
        d.push_back(str[j]);

    deque<char>::iterator it;
    printf("Case #%d: ", i + 1);
    for (it = d.begin(); it != d.end(); it++)
      printf("%c", *it);
    printf("\n");
  }
  
  return 0;
}
