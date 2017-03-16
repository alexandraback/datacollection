#include <iostream>
#include <map>

using namespace std;

int calc(){
  int A,B,ans=0;
  int i,j,k,M,N=0;
  map<int,char> cache; 
  cin >> A >> B;
  for(M=10;A/M;N++)M*=10;
  if(N==0)return 0;
  M /= 10;
  for(i=A;i<=B;i++){
    cache.clear();
    for(k=i,j=0;j<N;j++){
      k = (k/10) + (k%10)*M;
      if(k>=A && k<=B && i<k && cache.find(k)==cache.end()){
        cache[k] = 1;
        ans++;
      }
    }
  }
  return ans;
}

int main(){
  int N;
  cin >> N;
  for(int i=1; i<=N; i++){
    cout << "Case #" << i << ": " << calc() << endl;
  }
  return 0;
}
