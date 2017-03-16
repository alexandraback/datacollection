#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define LL long long
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;

using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  for(int z=1; z<=t; z++)
  {
    int a, b, k;
    printf("Case #%d: ", z);
    scanf("%d %d %d", &a, &b, &k);
    int wynik = 0;
    for(int i=0; i<a; i++)
    {
      for(int j=0; j<b; j++)
      {
	if((i&j) < k)
	  wynik++;
      }
      
    }
    printf("%d\n", wynik);

  }
  return 0;
}