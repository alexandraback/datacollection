#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int getOrder(ll N) {
  int order = 0;
  while(N > 0) {
    order++;
    N /= 10;
  }
  return order;
}

ll getStep(int digit) {
  ll step = 1;
  while(digit > 0) {
    step *= 10;
    digit--;
  }
  step--;
  return step;
}

ll getPow(int N) {
  ll n = 1;
  while(N > 0) {
    n *= 10;
    N--;
  }
  return n;
}

ll getReverse(ll N) {
  ll n = 0;
  while (N > 0) {
    n *= 10;
    n += N % 10;
    N /= 10;
  }
  return n;
}

int main() {
  int T;
  cin >> T;
  
  forn(i, T) {
    ll N;
    cin >> N;
    int order = getOrder(N);
    int buffer = 0;
    if(N % 10 == 0) {
      N--;
      buffer++;
    }
    
    ll step = 0;
    forn(j, order) {
      if(j >= 1) {
        step += getStep((j + 1) / 2);
        step += getStep(j / 2);
        step++;
      }
    }

    ll add1 = N - getPow(order - 1);
    if(order == 1) {
      add1++;
    }
    if(order > 1) {
      ll add2 = 0;
      add2 += N % getPow(order / 2);
      add2 += getReverse(N) % getPow((order + 1) / 2);
      if(add2 < add1) {
        add1 = add2;
      }
    }

    step += add1;
    step += buffer;

    cout << "Case #" << i + 1 << ": " << step << endl;
  }

  return 0;
}
