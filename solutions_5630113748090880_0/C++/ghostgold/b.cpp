#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int c[6000];
void work()
{
  int n;
  memset(c, 0,sizeof(c));
  scanf("%d",&n);
  for (int i =0; i <2*n-1;i++){
    for(int j = 0; j <n;j++){
      int x;
      scanf("%d", &x);
      c[x]++;
    }
  }
  vector<int> res;
  for(int i =0; i< 3000;i++){
    if (c[i]%2)
      res.push_back(i);
  }
  for(int i = 0; i < n; i++){
    printf(" %d", res[i]);
  }
  printf("\n");
}
int main()
{
  int T;
  scanf("%d",&T);
  for(int i =1; i <=T; i++){
    printf("Case #%d:", i);
    work();
  }
}
