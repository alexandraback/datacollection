#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int t=1; t<=T; t++)	{
    int M, N;
    int lawn[101][101];
    int max_for_row[101];
    int max_for_col[101];
	  cin >> N >> M;
    
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        cin >> lawn[i][j];
        if (j == 0 || max_for_row[i] < lawn[i][j]) max_for_row[i] = lawn[i][j];
        if (i == 0 || max_for_col[j] < lawn[i][j]) max_for_col[j] = lawn[i][j];
      }
    }

    int result=1;
    for (int i=0; i<N && result; i++)
      for (int j=0; j<M; j++) 
        if (lawn[i][j] < max_for_col[j] && lawn[i][j] < max_for_row[i]) {
          result = 0;
          break;
        }

    cout << "Case #" << t << ": " << (result ? "YES" : "NO") << endl;
	}
  
	return 0;
}
