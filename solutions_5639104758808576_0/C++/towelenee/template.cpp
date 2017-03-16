#include<cassert>
#include<queue>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<iostream>
#include<algorithm>

typedef long long ll;

using namespace std;

int main()         
{
  int test_n;
  scanf("%d",&test_n);
  for(int test_id = 0; test_id  < test_n; test_id++)
  {
    printf("Case #%d: ",test_id + 1);
    int ans = 0, currentLevel = 0;
    int n;
    string str;
    cin >> n >> str;
    for (int i = 0; i <= n; ++i)
    {
      if (currentLevel < i)
      {
	currentLevel++;
	ans++;
      }
      currentLevel += str[i] - '0';
    }
    printf("%d\n", ans);
  }
  return 0;
}

