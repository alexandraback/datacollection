#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#define forn(i, n ) for(int i = 0;i < (int)(n);i++)

using namespace std;
typedef long long ll;

map<ll, vector<ll> > m;
vector<ll> a,b;
bool fl;
vector<ll> mas;
int n;
void rek(int i, ll sum,vector<ll> x){
  if( i == n)
    return ;
  if(fl)
    return ;
  if(m.count(sum) && m[sum] != x){
    fl = true;
    a = x;
    b = m[sum];
    fl = true;
    return ;
  }  
  if(x.size() > 6)
    return;
  //printf("sum = %d\n",sum);
  if(sum)
    m[sum] = x;
  rek(i + 1,sum ,x);
  sum += mas[i];
  x.push_back(mas[i]);
  rek(i +1, sum ,x);
}
int main(){
  int _;
  scanf("%d",&_);
  forn(__,_){
    printf("Case #%d: ",__ +1);
    fprintf(stderr,"%d\n",__ + 1);
    scanf("%d",&n);
    mas.resize(n);
    forn(i,n)
      scanf("%I64d",&mas[i]);
    a.resize(0);
    fl = false;
    rek(0, 0, a);
    forn(i,a.size())
      printf("%I64d ",a[i]);
    puts("");
    forn(i,b.size())
      printf("%I64d ",b[i]);
    puts("");
  }
}
