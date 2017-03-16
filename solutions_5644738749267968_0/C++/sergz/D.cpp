#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int
main() {
  int T;

  cin >> T;

  for(int i = 1; i <= T; i++) {
    int n;
    vector<float> naomi;
    vector<float> ken;

    cin >> n;

    for(int j = 0; j < n; j++) {
      float v;
      cin >> v;

      naomi.push_back(v);
    }

    for(int j = 0; j < n; j++) {
      float v;
      cin >> v;

      ken.push_back(v);
    }

    sort(naomi.begin(), naomi.end(), greater<float>());
    sort(ken.begin(), ken.end(), greater<float>());

    int n_dw = n, n_w = 0;
    int nb = 0, ne = n-1;
    int kb = 0, ke = n-1;
    for(int j = 0; j < n; j++) {
      if(naomi[ne] < ken[ke]) {
	n_dw--;
	ne--;
      } else {
	ke--;
	ne--;
      }

      if(ken[kb] < naomi[nb]) {
        n_w++;
	nb++;
      } else {
	nb++;
	kb++;
      }
    }

    cout << "Case #" << i << ": " << n_dw << " " << n_w << endl;
  }

  return 0;
}

