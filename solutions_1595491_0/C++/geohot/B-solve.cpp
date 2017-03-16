#include <iostream>
using namespace std;

int runcase() {
  int ret = 0;
  int N, S, p;
  cin >> N >> S >> p;
  for (int i = 0; i < N; i++) {
    int g;
    cin >> g;
    int pm1 = p-1; if (pm1 < 0) pm1 = 0;
    int pm2 = p-2; if (pm2 < 0) pm2 = 0;
    if (g >= (p+(pm1)+(pm1))) ret++;
    else if ((S>0) && (g >= (p+(pm2)+(pm2)))) { ret++; S--; }
  }
  return ret;
}

int main(int argv, char* argc[]) {
  int case_count;
  cin >> case_count;
  for (int i = 0; i < case_count; i++) {
    cout << "Case #" << (i+1) << ": " << runcase() << endl;
  }
}

