#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long i64;

#define FOREACH(type, collection, arg) for(vector<type>::iterator arg = collection.begin(); arg != collection.end(); arg++)
#define FOREACH_R(type, collection, arg) for(vector<type>::iterator arg = collection.rbegin(); arg != collection.rend(); arg++)

int main(int argc, char *argv[]){
  int T;
  cin >> T;

  for(int t=1;t<=T;t++) {
    printf("Case #%d: ", t);
    
    int A, B;
    cin >> A >> B;

    int a = 0, N = 1;
    while(N < B) {
      N *= 10;
      a++;
    }
    if(a == 1) {
      printf("0\n");
      continue;
    }

    int count = 0;
    for(int n=A;n<=B;n++) {
      int m = n;
      set<int> nums;
      for(int k=0;k<a-1;k++) {
	int r = m % 10;
	m = m / 10 + r * N / 10;
	if(n < m && m <= B) {
	  //cerr << N << n << " " << m << endl;
	  nums.insert(m);
	}
      }
      count += nums.size();
    }

    printf("%d\n", count);
  }

  return 0;
}
