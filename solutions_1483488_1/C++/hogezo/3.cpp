#include <iostream> 
#include <sstream> 
#include <cmath>
#include<set>
using namespace std; 

int ketacalc(int x){
  int keta = 1;
  for(int i = 1;; i++){
    if(x-((int)pow(10.0,(double)(i))) >= 0){
      keta = i;
    } else {
      break;
    }
  }
  return keta+1;
}

int trans(int num,int sh){
  int keta,ret;
  set<int> ans;
  keta = ketacalc(num);

  for(int i = 1; i < keta; i++){
    int a = (int)pow(10.0,(double)(keta-i));
    int b = (int)pow(10.0,(double)(i));
    ret = num*b - ((int)(num/a))*a*b + ((int)(num/a));
    if(ret <= sh && ret > num) {
      ans.insert(ret);
    }
  }

  
  return ans.size();
}
    
int main(){
  int t,a,b;
  cin >> t;
  for(int i = 0; i < t; i++){
    int ans = 0;
    cin >> a >> b;
    for(int j = a; j < b; j++){
      ans += trans(j,b);
    }
    cout << "Case #" << i+1 << ": " << ans <<endl;
  }
  return 0;
}

