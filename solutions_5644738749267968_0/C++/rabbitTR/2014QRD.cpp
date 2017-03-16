#include <iostream>
using namespace std;

int ans_max, ans_min, N;
double weight[2][1000];

int saiki( int num, int cnt, int ans ) {

  for ( int i = 0; i < N; i++ ) {

    if ( ( cnt & ( 1 << i ) ) == 0 ) {

      int ans2 = ans;

      if ( weight[0][i] > weight[1][num] ) ans2++;

      if ( num == N - 1 ) {

	ans_max = max( ans_max, ans2 );
	ans_min = min( ans_min, ans2 );

      }else {

	saiki( num + 1, cnt + ( 1 << i ), ans2 );

      }

    }

  }

  return 0;

}

int main() {

  int T;

  cin >> T;

  for ( int i = 0; i < T; i++ ) {

    cin >> N;

    ans_max = 0;
    ans_min = N;

    for ( int j = 0; j < 2; j++ ) {

      for ( int k = 0; k < N; k++ ) {

	cin >> weight[j][k];

      }

    }

    saiki( 0, 0, 0 );

    cout << "Case #" << i+1 << ": " << ans_max << " " << ans_min << endl;

  }

  return 0;

}
