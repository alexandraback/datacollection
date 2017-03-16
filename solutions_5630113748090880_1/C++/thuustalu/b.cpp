#include <iostream>

const int MAX_HEIGHT = 2505;

using namespace std;

int count [MAX_HEIGHT];

int main () {
  int testc;
  cin >> testc;

  for (int t = 1; t <= testc; t++) {
    for (int i = 0; i < MAX_HEIGHT; i++) {
      count[i] = 0;
    }

    int width;
    cin >> width;
    
    for (int i = 0; i < 2 * width - 1; i++) {
      for (int j = 0; j < width; j++) {
        int soldier;
        cin >> soldier;
        count[soldier]++;
      }
    }

    cout << "Case #" << t << ":";
    for (int i = 0; i < MAX_HEIGHT; i++) {
      if (count[i] % 2 == 1) {
        cout << " " << i;
      }
    }
    cout << endl;
  }
}
