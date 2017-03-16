#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int LL;

LL removedSolve(int A, int remove, vector<int>& motes){
  int move = remove;
  int size = motes.size()-remove;
  for(int i = 0; i < size; i++){
    while(true){
      if(A > motes[i]){
	A+=motes[i];
	break;
      }else{
	if(A == 1){
	  return 10000000000;
	}
	A+=A-1; // add mote
	move++;
      } 
    }
  }
  return move;
}

LL solve(int A, vector<int>& motes){
  // greedily solve (eat when you can eat, add when you cannot eat)
  // check all the removal number
  LL bestMove = 10000000000;
  LL tmpMove;
  for(int remove = 0; remove <= motes.size(); remove++){
    tmpMove = removedSolve(A, remove, motes);
    if(tmpMove < bestMove){
      bestMove = tmpMove;
    }
  }
  return bestMove;
}

int main(){
  int T;
  cin >> T;
  for(int t = 0; t < T; t++){
    int A, N; // A is armin's mote size
    cin >> A >> N;
    vector<int> motes;
    int m;
    for(int n = 0; n < N; n++){
      cin >> m;
      motes.push_back(m);
    }
    sort(motes.begin(), motes.end());
    // use "motes" and "A"
    cout << "Case #" << t+1 << ": " <<  solve(A, motes) << endl;
  }
  return 0;
}
