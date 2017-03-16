/*********************************************************************/
/*                                                                   */
/* Program to solve the "Kingdom Rush" problem, posed                */
/* for the 2012 Google Code Jam. Uses only standard C++ libraries.   */
/*                                                                   */
/* Using gcc, compile as: g++ -o rush rush.cpp                       */
/*                                                                   */
/* Usage: rush <input data file> <output file>                       */
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
  input.open(argv[1]);
  output.open(argv[2]);
  if ((!input.is_open()) || (!output.is_open())) return 1;
  int levels_1star[1000];
  int levels_2star[1000];
  int levels_done[1000];
  int N;
  input >> num_inputs;
  for (int n = 0; n < num_inputs; n++) {
    input >> N;
    for (int m = 0; m < N; m++) {
	input >> levels_1star[m] >> levels_2star[m];
	levels_done[m] = 0;
    }
    int tries = 0;
    int stars = 0;
    int levels = 0;
    bool done = false;
    bool failed = false;
    while (levels < N) {
	done = false;
	while (!done) {
	    if (levels == N)
		break;
	    done = true;
	    for (int m = 0; m < N; m++) {
		if (levels_done[m] == 2) continue;
		if (levels_2star[m] <= stars) {
		    done = false;
		    stars += 2-levels_done[m];
		    levels_done[m] = 2;
		    tries++;
		    levels++;
		}
	    }
	}
	if (levels < N) {
	    int level = -1;
	    int best_level = -1;
	    for (int m = 0; m < N; m++) {
		if (levels_done[m] != 0) continue;
		if (levels_1star[m] <= stars) {
		    if (levels_2star[m] > best_level) {
			best_level = levels_2star[m];
			level = m;
		    }
		}
	    }
	    if (level == -1) {
		failed = true;
		break;
	    }
	    stars += 1;
	    levels_done[best_level] = 1;
	    tries++;
	}
    }
    if (failed) {
	output << "Case #" << (n+1) << ": "  << "Too Bad" << endl;
    } else {
	output << "Case #" << (n+1) << ": "  << tries <<endl;
    }
  }
  input.close();
  output.close();
  return 0;
}