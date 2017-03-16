#include <iostream>
#include <vector>
using namespace std;

class hi {
public:
  int d;
  int m;
};
vector<hi> hk;
vector<int> dd;
vector<int> mm;

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    int d, h, m;
    hk.clear();
    hi hiker;
    for (int i=0;i<N;i++) {
      cin >> d;
      cin >> h;
      cin >> m;
      for (int j=0;j<h;j++) {
          hiker.d = d;
          hiker.m = m+j;
          hk.push_back(hiker);
      }
    }

    bool same = true;
    for (int i=1;i<hk.size();i++) {
      if (hk[i-1].m != hk[i].m) {
        same = false;
      }
    }
    if (same) {
      cout << "0" << endl;
      continue;
    }
    // 2 
    if (hk[0].m < hk[1].m)
      swap(hk[0], hk[1]);

    long long time = (360 - hk[0].d) * hk[0].m; // slow
    double time2 = (360 - hk[1].d) * hk[1].m; // fast
    long long dist = time * hk[1].m;
    
    if(time > ((360-hk[1].d) + 360)*hk[1].m) {
      cout << "1" << endl;
      continue;
    } else {
      cout << "0" << endl;
      continue;
    }

	}
	return 0;
}
