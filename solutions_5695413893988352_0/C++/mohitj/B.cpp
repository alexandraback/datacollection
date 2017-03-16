#include <iostream>
#include <algorithm>
using namespace std;

static void pop(int *poss, char *score, int idx, int v, int &cnt) {
  if(score[idx] == '\0') {
    poss[cnt++] = v;
	return;
  }

  if(score[idx] != '?') pop(poss, score, idx + 1, v * 10 + score[idx] - '0', cnt);
  else for(int i = 0; i < 10; ++i)  pop(poss, score, idx + 1, v * 10 + i, cnt);
}

int main() {
  int T;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for(int cn = 1; cn <= T; ++cn) {
cerr << cn << " of " << T << '\n';

    char C[5], J[5];
	cin >> C >> J;
	int goodC[1000], goodJ[1000], cc = 0, cj = 0;

    pop(goodC, C, 0, 0, cc);
    pop(goodJ, J, 0, 0, cj);

    int bd = 9999, bi, bj;

    for(int i = 0; i < cc; ++i) {
	  for(int j = 0; j < cj; ++j) {
	    int diff = (goodC[i] > goodJ[j]) ? goodC[i] - goodJ[j] : goodJ[j] - goodC[i];
		if(diff < bd) {
		  bd = diff;
		  bi = i;
		  bj = j;
		} else if (diff == bd) {
		  if(goodC[i] < goodC[bi]) {
		  bd = diff;
		  bi = i;
		  bj = j;
		  } else if(goodC[i] == goodC[bi] && goodJ[j] < goodJ[bj]) {
		  bd = diff;
		  bi = i;
		  bj = j;
		  }
		}
	  }
	}

	cout << "Case #" << cn << ": ";
	if(C[1] == '\0') cout << goodC[bi] << ' ' << goodJ[bj] << '\n';
	else if(C[2] == '\0') cout << goodC[bi] / 10 << (goodC[bi] % 10) << ' ' << goodJ[bj] / 10 << (goodJ[bj] % 10) << '\n';
	else cout << goodC[bi] / 100 << ((goodC[bi] / 10) % 10) << (goodC[bi] % 10) << ' '
	          << goodJ[bj] / 100 << ((goodJ[bj] / 10) % 10) << (goodJ[bj] % 10)  << '\n';
  }
}
