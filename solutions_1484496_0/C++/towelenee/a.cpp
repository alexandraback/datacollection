#include<cstdio>
#include<vector>
#include<cmath>
#define forn(i, n ) for(int i = 0;i < (int)(n);i++)

using namespace std;

vector<int> x,ans, f;
void rek(int i,bool fl,int sum){
  if(ans.size())
    return ;
  if(fl && sum == 0){
    ans = f;
    for(int j = i;j<f.size();j++)
      ans[j] = 0;
    return ; 
  }
  if( i == x.size())
    return;
  f[i] = 0;
  rek(i+1,fl,sum);
  f[i] = 1;
  rek(i+1,1, sum + x[i]);
  f[i] = 0;
  f[i] = -1;
  rek(i+1,1, sum - x[i]);
  f[i] = 0;

}
int main(){
  int _;
  scanf("%d",&_);
  forn(__,_){
    printf("Case #%d:\n",__ + 1);
    int n;
    scanf("%d",&n);
    x.resize(n);
    ans.resize(0);
    f.resize(n);
    forn(i, n){
      scanf("%d", &x[i]);
      f[i] = 0;
    }
    rek(0,0,0);
    if(ans.size()){
      int sum1 = 0 , sum2 = 0;
      forn(i,ans.size())
        if(ans[i] == 1){
          printf("%d ",x[i]);
          sum1 += x[i]; 
        }
      puts("");
      forn(i,ans.size())
        if(ans[i] == -1){
          printf("%d ",x[i]);
          sum2 += x[i]; 
        }
      puts("");
      //printf("%d %d\n",sum1,sum2);


    }
    else
      puts("Impossible");
  }
}
