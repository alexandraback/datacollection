#include <iostream>
using namespace std;

int main() {

  int T;

  cin >> T;

  for ( int i = 0; i < T; i++ ) {

    int N;

    cin >> N;

    double weight[2][1000];

    for ( int j = 0; j < 2; j++ ) {

      for ( int k = 0; k < N; k++ ) {

	cin >> weight[j][k];

      }

    }

    for ( int j = 0; j < 2; j++ ) {

      for ( int k = 0; k < N; k++ ) {

	for ( int l = 0; l < N - 1; l++ ) {

	  if ( weight[j][l] > weight[j][l+1] ) {

	    swap( weight[j][l], weight[j][l+1] );

	  }

	}

      }

    }

    int ans_max = 0;
    int ans_min = N;

    int flag[1000] = {0};

    for ( int j = 0; j < N; j++ ) {

      for ( int k = 0; k < N; k++ ) {

	if ( weight[0][k] > weight[1][j] && flag[k] == 0 ) {

	  flag[k]++;

	  ans_max++;

	  break;

	}

      }

    }

    int flag2[1000] = {0};

    for ( int j = 0; j < N; j++ ) {

      for ( int k = 0; k < N; k++ ) {

	if ( weight[1][k] > weight[0][j] && flag2[k] == 0 ) {

	  flag2[k]++;

	  ans_min--;

	  break;

	}

      }

    }

    cout << "Case #" << i+1 << ": " << ans_max << " " << ans_min << endl;

  }

  return 0;

}
