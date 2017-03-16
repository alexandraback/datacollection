#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
const int MAX=10000000;

vector<int> next;

void init(){
  next.resize(MAX+1);
  vector<int> d;
  int nd,n;
  long long sum;
  for(int i = 1; i <= MAX; i++){
    d.clear(); nd=0;
    n=i;
    while(n>0){
      d.insert(d.begin(), n%10);
      n/=10;
      nd++;
    }
    for(int start = 1; start <= nd; start++) if(d[start%nd]!=0){
      sum=0;
      for(int j = start; j < start+nd; j++){
        sum=10*sum+d[j%nd];
      }
      next[i]=sum;
      break;
    }
  }
}

void run(int case_index) {
  int A,B;
  cin >> A >> B;
  vector<int> done(MAX+1,0);
  int n;
  long long res,m;
  res=0;
  for(int i = A; i <= B; i++) if(not done[i]){
    m=1;
    n=next[i];
    while(n!=i){
      if(A<=n and n<=B and not done[n]){
        m++;
        done[n]=true;
      }
      n=next[n];
    }
    res += (m-1)*m/2;
  }
  cout << "Case #" << case_index << ": " << res;
  cout << endl;
}

int main(int argc, char* argv[]) {
  init();
  int n; 
  cin >> n;
  for(int i = 1; i <=n; i++){
    cerr << i << " ";
    run(i);
  }
  cerr << endl;
  return 0;
}
