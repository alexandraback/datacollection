#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <math.h>

using namespace std;

double PI;

void runTest(long t, long radius, long paint) {
  // number of rings painted
  long numrings = 0;
  long paintleft = paint;

  while (paintleft > 0) {
    // deal in units of 'pi' we don't have to multiply / divide by pi
    long newringouter = (radius+1)*(radius+1);
    long newringinner = (radius*radius);
    long newringarea = newringouter - newringinner;
//    cout << "New ring area: " << newringarea << endl;
    paintleft -= newringarea;
//    cout << "Paint Left: " << paintleft << endl;
    numrings++;
    radius += 2;
  }

  if (paintleft < 0) {
    numrings--;
  }

  cout << "Case #" << t << ": " << numrings << endl;
}

int main (int argc, char *argv[]) {
  PI = atan(1)*4;
  int tests;

  cin >> tests;

  for (int t = 1; t <= tests; t++) {
    // process this test case
    long radius, paint;
    cin >> radius;
    cin >> paint;
    runTest(t, radius, paint);
  }
}
