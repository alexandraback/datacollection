#include <iostream>
#include <algorithm>


using namespace std;

int main() {
  int T;
  cin >> T;
  for(int t= 1; t<=T; t++) {
    int N;
    cin >> N;
    int next[1100];
    bool pair[1100];
    bool loops[1100];
    int temp;
    for(int i = 0; i < N; i++) {
      cin >> temp;
      temp--;
      next[i]=temp;
    }
    for(int i = 0; i < N; i++) {
      pair[i] = (i == next[next[i]]);
    }
    for(int i = 0; i < N; i++) {
      int j;
      int now=i;
      for(j=0; j<N+2; j++) {
	if (pair[now])
	  break;
	now = next[now];
      }
      loops[i]=(j==N+2);	  
    }
    int best_loop=0;
    for(int i = 0; i < N; i++) {
      if (loops[i]) {
	//cout << "looping" << endl;
	int now=i;
	for(int j = 0; j<N; j++) {
	  now = next[now];
	}
	int start=now;
	int l=1;
	while (next[now]!=start) {
	  l++;
	  now = next[now];
	}
	if (best_loop < l)
	  best_loop=l;
      }
    }
    int tail[1100];
    for(int i = 0; i < N; i++) {
      tail[i] = 0;
    }
    for(int i = 0; i < N; i++) {
      if (!loops[i]) {
	int l=1;
	int now = i;
	while (!pair[now]) {
	  tail[now] = max(tail[now],l);
	  l++;
	  now = next[now];
	}
	tail[now] = max(tail[now],l);
      }
    }
    int tot=0;
    for(int i = 0; i < N; i++) {
      if (pair[i])
	tot+=tail[i];
    }
    //    cout << best_loop << endl;
    cout << "Case #" << t << ": " << max(tot, best_loop) << endl;
  }
  return 0;
}
    
    
	
    
