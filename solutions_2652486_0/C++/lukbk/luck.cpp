#include <iostream>
#include <set>
using namespace std;

int main() {
  int T,R,N,M,K;
  int p;
  cin >> T;
  for(int i=1; i<=T; i++) {
    cin >> R >> N >> M >> K;
    cout << "Case #" << i <<":"<<endl;
    for(int j=0; j<R; j++) {
      int min[M-1];
      for(int j=0; j<M-1; j++)
	min[j] = 0;
      int count[M-1];
      for(int j=0; j<M-1; j++)
	count[j] = 0;
      for(int k=0; k<K; k++) {
	cin >> p;
	int minw[M-1];
	for(int j=0; j<M-1; j++)
	  minw[j] = 0;
	for(int l=2; l<=M; l++) {
	  int pp = p;
	  while(pp>0 && pp % l == 0) {
	    pp /= l;
	    minw[l-2]++;
	    //cout << l << endl;
	  }
	  if(minw[l-2])
	    count[l-2]++;
	}
	for(int j=0; j<M-1; j++)
	  if(minw[j] > min[j])
	    min[j] = minw[j];
      }//K
      multiset<int> S;
      for(int l=M; l>=2 && S.size()<N; l--)
	for(int ll=0; ll<min[l-2] && S.size()<N; ll++)
	  S.insert(l);
      int additional = N-S.size();
      while(additional>0) {
	bool found = false;
	for(int l=0; (l < M-2) && (additional > 0); l++)
	  if(count[l] > 0) {
	    cout << l+2;
	    additional--;
	    count[l]--;
	    found = true;
	  }
	if(!found) {
	  cout << 2;
	  additional--;
	}
      }
      while(!S.empty()) {
	cout << *S.begin();
	S.erase(S.begin());
      }
      cout << endl;
    } // R
  }//T
  return 0;
}
