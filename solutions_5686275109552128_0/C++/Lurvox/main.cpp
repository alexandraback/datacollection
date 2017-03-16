#include <fstream>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

static int D;
static int P[1001];

int hceil(int n) {
  if (n%2 == 0)
    return n/2;
  return (n/2)+1;
}


int solve() {
 
  priority_queue<int> q(P,P+D);
  int f[1001];
  int special = 0;
  f[0] = q.top();

  int max_iter = f[0];
  int minutes = f[0];

  for(int i=1;i<max_iter;i++) {
    int top = q.top();
    q.pop();
    q.push(top/2); q.push(hceil(top));
    f[i] = i + q.top();
    minutes = f[i] < minutes ? f[i] : minutes;
  }

  return minutes;

}


int main() {

  ifstream input ("B-small-attempt1.in");
  ofstream output ("output.txt");
  int T;
  string shy = "";
  input >> T;
  for (int i=1; i<=T; i++) {
    input >> D;
    for(int j=0;j<D;j++) {
      input >> P[j];
    }
    output << "Case #" << i <<": " << solve() << "\n";
  }

  input.close();
  output.close();

  return 0;
}
