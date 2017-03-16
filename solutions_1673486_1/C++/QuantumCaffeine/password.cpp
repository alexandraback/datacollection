/*********************************************************************/
/*                                                                   */
/* Program to solve the "Password Problem" problem, posed            */
/* for the 2012 Google Code Jam. Uses only standard C++ libraries.   */
/*                                                                   */
/* Using gcc, compile as: g++ -o password password.cpp               */
/*                                                                   */
/* Usage: password <input data file> <output file>                   */
/*                                                                   */
/* By Peter Mattsson (peter.mattsson@lineone.net)                    */
/*                                                                   */
/* Licence: Public Domain (or as specified by Google)                */
/*                                                                   */
/*********************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
  
int main(int argc, const char* argv[]) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <input data file> <output file>\n";
    return 1;
  }
  ifstream input;
  ofstream output;
  int num_inputs;
  int A,B;
  input.open(argv[1]);
  output.open(argv[2]);
  if ((!input.is_open()) || (!output.is_open())) return 1;
  input >> num_inputs;
  for (int n = 0; n < num_inputs; n++) {
    input >> A >> B;
    double prob;
    double cum_prob = 1;
    double best;
    best = B + 2;
    for (int m = 0; m < A; m++) {
	input >> prob;
	cum_prob *= prob;
	int right_keys = A - 2*(m+1)+B+1;
	float keys = cum_prob*(right_keys) + (1-cum_prob)*(right_keys+B+1);
	if (keys < best) best = keys;
    }
    cout.precision(6);
    output << "Case #" << (n+1) << ": "  << fixed << best << "\n";
  }
  input.close();
  output.close();
  return 0;
}