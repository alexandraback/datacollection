#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int solve(int s_max, string shy) {
 
  int cum_sum[1001];

  for(int i=0;i<=s_max;i++){
    cum_sum[i] = shy[i] - '0';
  }

  for(int i=1;i<=s_max;i++){
    cum_sum[i] = cum_sum[i] + cum_sum[i-1];
  }

  int num_friends = 0;
  
  for(int i=1;i<=s_max;i++){
    if(cum_sum[i-1]+num_friends<i)
      num_friends=i-cum_sum[i-1];
  }

  return num_friends;


}


int main() {

  ifstream input ("A-large.in");
  ofstream output ("output.txt");
  int T, s_max;
  string shy = "";
  input >> T;
  for (int i=1; i<=T; i++) {
    input >> s_max >> shy;
    output << "Case #" << i <<": " << solve(s_max,shy) << "\n";
  }

  input.close();
  output.close();

  return 0;
}
