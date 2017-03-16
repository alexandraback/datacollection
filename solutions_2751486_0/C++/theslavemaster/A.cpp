#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <list>
#include <queue>
#include <math.h>
using namespace std;
static const int SIZE = 1e6+2;

char str[SIZE];
int arr[SIZE];
int main(int argc, char const *argv[])
{
  set<char> vowels;
  vowels.insert('a');
  vowels.insert('e');
  vowels.insert('i');
  vowels.insert('o');
  vowels.insert('u');
  int t=0;
  scanf("%d\n", &t);
  for(int idx = 0; idx < t; idx++) {
    int n=0;
    scanf("%s%d\n", str, &n);
    // printf("%s %d\n", str, n);
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
      if(vowels.find(str[i]) != vowels.end())
        arr[i] = 0;
      else
        arr[i] = 1;
    }
    // for (int i = 0; i < len; ++i)
    // {
    //   printf("%d", arr[i]);
    // }
    // printf("\n");
    int prevStart = -1, prevEnd = -1;
    int start=0, end=n-1;
    int curSum=0;
    for (int i = 0; i < n; ++i)
    {
      curSum += arr[i];
    }
    long long int count = 0;
    while(end < len) {
      if(curSum == n) {
        // printf("adding start = %d, end = %d!\n", start, end);
        count += ((long long)start - prevStart)*(len-(long long)end);
        prevStart = start;
        prevEnd = end;
      }
      curSum += arr[++end] - arr[start++];
    }
    printf("Case #%d: %lld\n", idx+1, count);
  }
  return 0;
}