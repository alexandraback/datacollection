#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const long long MAX = 1ll<<22;

vector<long long> primes;

long long divisor(long long a){
  bool prime = true;
  if(a<0)
    return 0;
  if(a < MAX){
  if(a%2 == 0)
    return 2;
  long long sq = sqrt(a);
  for(auto i : primes){
    if(i > sq)
      break;
    if(a%i == 0){
      prime = false;
      break;
    }
  }
  }
  else
    prime = false;
  if(prime)
    return 0;
  for(long long i =3 ;i<sqrt(a);i+=2)
    if(a%i == 0)
      return i;
  return 0;
}

bool coin(long long i){
  long long ii = i;
  vector<long long> v(9,0);
  vector<long long> m(9,1);
  while(i>0){
    int l = i&1;
    i=i>>1;
    for(int i = 0;i<9;i++){
      v[i] += l*m[i];
      m[i] *= 2+i;

    }
  }
  for(int i = 0;i<9;i++){
    if(divisor(v[i]) == 0)
      return false;
  }
  for(int j = log2(ii);j>=0;j--)
    cout << ((1ll<<j & ii)!=0);
  for(int i = 0;i<9;i++)
    cout << " " << divisor(v[i]);
  cout << endl;
  return true;
}

int main(){
  primes.push_back(2);
  for(long long i = 3;i<MAX;i+=2){
    long long sq = sqrt(i);
    bool b = true;
    for(long long j = 0;j<primes.size() && primes[j]<=sq;j++){
      if(i%primes[j] == 0){
        b=false;
        break;
      }
    }
    if(b)
      primes.push_back(i);
  }
  cout << "Begin?";
  string q;
  cin >> q;
  cout << "IT HAS BEGUN!!" << endl;
  //freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
  int t;
  cin >> t;
  for(int i = 0;i<t;i++){
    int n,j;
    cin >> n >> j;
    cout << "Case #" << i+1 << ": " << endl;
    long long c = (1ll<<(n-1)) + 1;
    while(j>0){
      j -= coin(c+=2);
    }
  }
  return 0;
}
