#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>

using namespace std;


#define INPUT_REDIRECTION
#define OUTPUT_REDIRECTION

#define N 52
int edge[N][N];
long long cnt[N];

int main()
{
	#ifdef INPUT_REDIRECTION
    freopen( "B-large.in", "r", stdin );
	#endif // INPUT_REDIRECTION
	
	#ifdef OUTPUT_REDIRECTION
	    freopen( "out.txt", "w", stdout );
	#endif // OUTPUT_REDIRECTION
	
	cnt[1] = cnt[2] = 1;
	for (int i = 3; i <= 50; ++i) {
		cnt[i] = (cnt[i-1] * 2);	
	}
	
   int t;
   cin >> t;
   for (int k = 1; k <= t; ++k) {
      int n;
      long long m;
      cin >> n >> m;
      
      
      int i, j;
      for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				edge[i][j] = 0;	
			}
		}
      
      i = n;
      
      if (cnt[n] < m) {
			cout << "Case #" << k << ": IMPOSSIBLE" << endl;
			continue;
		}
		
		while (i >= 1 && cnt[i] > m) --i;
		m -= cnt[i];
		for (j = 1; j <= i; ++j) {
			for (int x = j+1; x <= i; ++x) {
				edge[j][x] = 1;	
			}
		}
		while (i <= n-1) {
			edge[i][i+1] = 1;	
			++i;
		}
      
      i = n;
      while (m) {
			while (i >= 1 && cnt[i] > m) --i;
			
			if (i > 1) {
				edge[i][n] = 1;
			}
			m -= cnt[i];
		}
		

      cout << "Case #" << k << ": POSSIBLE" << endl;
      for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				cout << edge[i][j];
			}
			cout << endl;
		}
   }

   return 0;
}
