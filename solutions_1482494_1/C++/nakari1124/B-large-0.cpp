#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long i64;

#define FOREACH(type, collection, arg) for(vector<type>::iterator arg = collection.begin(); arg != collection.end(); arg++)
#define FOREACH_R(type, collection, arg) for(vector<type>::iterator arg = collection.rbegin(); arg != collection.rend(); arg++)

int main(int argc, char *argv[]){
  int T;
  cin >> T;

  for(int t=1;t<=T;t++) {
    printf("Case #%d: ", t);

    int N;
    cin >> N;
    vector<pair<int, int> > l2(N);
    vector<int> flags(N, 0);
    vector<int> l1(N, 1);
    for(int i=0;i<N;i++){
      cin >> l1[i] >> l2[i].first;
      l2[i].second = i;
    }

    sort(l2.begin(), l2.end());

    i64 result = 0;
    int stars = 0;
    while(stars != 2 * N) {
      int stars_prev = stars;
      int req_st = -1;
      for(int i=0;i<N;i++) {
	if(l2[i].first <= stars) {
	  if(flags[l2[i].second] != 2) {
	    stars += 2 - flags[l2[i].second];
	    flags[l2[i].second] = 2;
	    result++;
	  }
	}
	else {
	  req_st = l2[i].first;
	  break;
	}
      }

      if(req_st == -1) {
	continue;
      }

      for(int i=N-1;i>=0;i--) {
	if(l1[l2[i].second] <= stars && flags[l2[i].second] == 0) {
	  stars += 1;
	  flags[l2[i].second] = 1;
	  result++;
	  break;
	}
      }
      if(stars == stars_prev) {
	break;
      }
    }
    if(stars == N * 2)
      cout << result << endl;
    else
      cout << "Too Bad" << endl;
  }

  return 0;
}
