#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  freopen("A-large.in", "r",stdin);
  freopen("output.txt", "w",stdout);
  int T, n;
  char s[1000+5];
  scanf("%d",&T);
  for(int t = 1; t <= T; t++){
    scanf("%d",&n);
    gets(s);
    //cout<<T<<" "<<n<<" "<<s<<endl;
    int result = 0, cnt = 0;
    for(int i = 1; i <= n+1;i++){
        //cout<<s[i]<<" ";
        int value = s[i] - '0';
        if(value>0){
          if(cnt >= i-1)cnt+=value;
            else
                result += i-1-cnt, cnt = i-1+value;
        }
    }
    printf("Case #%d: %d\n",t,result);
  }
  return 0;
}