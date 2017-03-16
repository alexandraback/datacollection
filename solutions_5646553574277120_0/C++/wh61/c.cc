#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int main() {
    freopen("c_in.txt", "r", stdin);
    freopen("c_out.txt", "w", stdout);

    int T, ca = 0;
    scanf("%d", &T);
    while (T--) {
	int C, D, V;
	scanf("%d%d%d", &C, &D, &V);

	int val[100];
	for (int i = 0; i < D; ++i) {
	    scanf("%d", val + i);
	}
	int val_flag[100];
	memset(val_flag, 0, sizeof(val_flag));
	for (int i = 0; i < D; ++i) {
	    val_flag[val[i]] = true;
	}
	int f[100];
	memset(f, 0, sizeof(f));
	int ans = 0;
	for (int i = 1; i <= V; ++i) {

	    if (val_flag[i]) {
	      f[i] = true;
	      for (int j = 0; j < i; ++j) {
		  f[i + j] = true;
	      }
	      continue;
	    }
	    if (f[i]) {
		continue;
	    }
	    if (!val_flag[i]) {
		ans++;
		f[i] = true;
		for (int j = 0; j < i; ++j) {
		    f[i + j] = true;
		}
	    }
	}
	printf("Case #%d: %d\n", ++ca, ans);
    }


}
