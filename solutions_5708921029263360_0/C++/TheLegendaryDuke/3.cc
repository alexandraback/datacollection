#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct three {
  int x,y,z;
};

int main() {
  int c;
  cin >> c;
  for(int i = 0; i < c; i++) {
    int j,p,s,k;
    cin >> j >> p >> s >> k;
    //cerr << j << p << s << k << endl;
    cout << "Case #" << i + 1 << ": ";
    int com = j * p * s;
    int baseJP[j*p];
    for(int i1 = 0; i1 < j; i1++) {
      for(int i2 = 0; i2 < p; i2++) {
        baseJP[i1*p+i2] = 0;
      }
    }
    int baseJS[j*s];
    for(int i1 = 0; i1 < j; i1++) {
          for(int i2 = 0; i2 < s; i2++) {
                  baseJS[i1*s+i2] = 0;
          } 
    } 
    int basePS[s*p];
    for(int i1 = 0; i1 < p; i1++) {
          for(int i2 = 0; i2 < s; i2++) {
                  basePS[i1*s+i2] = 0;
          } 
    } 
    int co = 0;
    three pos[1000];
    for(int i1 = 0; i1 < s; i1++) {
      for(int i2 = 0; i2 < p; i2++) {
        for(int i3 = 0; i3 < j; i3++) {
          if(baseJP[i3*p+i2] < k && baseJS[i3*s+i1] < k && basePS[i2*s+i1] < k) {
            baseJP[i3*p+i2]++;
            baseJS[i3*s+i1]++;
            basePS[i2*s+i1]++;
            pos[co].x = i3+1;
            pos[co].y = i2+1;
            pos[co].z = i1+1;
            co++;
          }
        }
      }
    }
    /*if(i == 22) {
      cerr << baseJP[2] << baseJS[1] << basePS[1] << endl;
    }*/
    if(com > co) {
      cout << co << endl;
      for(int i1 = 0; i1 < co; i1++) {
        cout << pos[i1].x << " " << pos[i1].y << " " << pos[i1].z << endl;
      }
    }else {
      cout << com << endl;
      for(int i1 = 1; i1 <= j; i1++) {
        for(int i2 = 1; i2 <= p; i2++) {
          for(int i3 = 1; i3 <= s; i3++) {
            cout << i1 << " " << i2 << " " << i3 << endl;
          }
        }
      }
    }
  }
}
