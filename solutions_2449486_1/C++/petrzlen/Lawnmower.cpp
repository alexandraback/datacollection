#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int main()
{
  int T;
  cin >> T;
  REP(t, T){
    int N, M;
    cin >> N >> M;
    int F[N][M];
    REP(i, N) REP(j, M) cin >> F[i][j];
    
    vector<int> E1(N,0);
    vector<int> E2(M,0);
    REP(i, N) REP(j, M){
      E1[i] = max(E1[i], F[i][j]); 
      E2[j] = max(E2[j], F[i][j]); 
    }
    
    bool result = true;
    REP(i, N) REP(j, M){
      if(F[i][j] < E1[i] && F[i][j] < E2[j]) result = false;
    }
    cout << "Case #" << t+1 << ": " << ((result)?"YES":"NO") << endl;
  }
	return 0;
}
