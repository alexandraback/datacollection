#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

struct hiker {
  long long time;
  int first;
  long long lap;
};

bool operator<(const hiker& a, const hiker&b) {
  return a.time > b.time;
}

int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    int N;
    cin>>N;
    int numHikers=0;
    priority_queue<hiker> Q;
    for (int i=0;i<N;i++) {
      int D,H,M;
      cin>>D>>H>>M;
      for (int h=0;h<H;h++) {
	hiker hik;
	hik.time=(360L-D)*(M+h);
	hik.first=1;
	hik.lap=(M+h)*360L;
	Q.push(hik);
	numHikers++;
      }
    }
    int best = numHikers;
    int cur = numHikers;
    long long curTime=0;
    while(cur<numHikers*2) {
      hiker hik = Q.top();
      //      cout<<hik.time<<' '<<hik.first<<' '<<hik.lap<<endl;
      Q.pop();
      if (curTime != hik.time) {
	if (best>cur) {
	  best = cur;
	}
	curTime = hik.time;
      }
      if (hik.first == 1) {
	cur--;
	hik.first = 0;
      } else {
	cur++;
      }
      hik.time+=hik.lap;
      Q.push(hik);
    }    
    cout<<"Case #"<<t<<": "<<best<<endl;
  }
}

