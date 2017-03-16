#include"stdio.h"
#include"set"
using namespace std;
int main(){
  int T;
  scanf("%d",&T);
  for(int test=1;test<=T;test++){
    int a,b;
    scanf("%d%d",&a,&b);
    int place=1,len=0;
    long long soln=0;
    while(10*place<=a)place*=10,len++;
    for(int i=a;i<=b;i++){
      int j=i;
      set<int> ans;
      for(int tt=0;tt<len;tt++){
	j=j/10+place*(j%10);
	if(j>i&&j<=b)
	  ans.insert(j);
      }
      soln+=ans.size();
    }
    printf("Case #%d: %Ld\n",test,soln);
  }
}