#include <iostream>

using namespace std;

int main(int argc, char** argv) {

  int N;

  int T;

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N;
    
    bool seen[10];

    for (int j = 0; j < 10; j++) {
      seen[j] = false;
    }
    
    bool done = false;
    bool insomnia = false;

    int ctr = 0;
    
    while (!done) {
      ctr += N;
      if (ctr == 0) {
	insomnia = true;
	done = true;
      } else {
	int down = ctr;
	while (down > 0) {
	  seen[down % 10] = true;
	  down /= 10;
	}
	done = true;
	for (int j = 0; j < 10; j++) {
	  if (!seen[j]) {
	    done = false;
	    break;
	  }
	}
      }
    }
    
    cout << "Case #" << (i + 1) << ": ";
    if (insomnia) {
      cout << "INSOMNIA";
    } else {
      cout << ctr;
    }
    cout << endl;
  }
  
  return 0;
}
