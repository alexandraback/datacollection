//Aleksander Łukasiewicz
#include<cstdio>
using namespace std;

int t;
int n, m, w;

int main(){
  scanf("%d", &t);
  for(int pp=1; pp<=t; pp++){
    scanf("%d %d %d", &n, &m, &w);
    int res = n*(m/w) + w;
    if(m%w == 0)
      res--;
    printf("Case #%d: %d\n", pp, res); 
  }

return 0;
}