#include<iostream>
#include<fstream>

using namespace std;

int T;
int N;
double naomi[10];
double ken[10];
int visitedKen[10];

ofstream myfile;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    double tmp;
    cin >> tmp;
    naomi[i] = tmp;
  }
  for(int i = 0; i < N; i++) {
    double tmp;
    cin >> tmp;
    ken[i] = tmp;
  }
}

void process(int n) {
  int dwar = 0;
  int war = 0;

  double min = 2;
  int minI = -1;
  double max = -1;
  int maxI = -1;

  for(int i = 0; i < N; i++) {
      visitedKen[i] = 0;
  }

  for(int i = 0; i < N; i++) {
    min = 2;
    minI = -1;
    max = -1;
    maxI = -1;

    double now = naomi[i];
    for(int j = 0; j < N; j++) {
      if(visitedKen[j] == 1) continue;

      double know = ken[j];
      if(now > know) {
        if(now - know > max) {
          max = now - know;
          maxI = j;
        }
      } else {
        if(know - now < min) {
          min = know - now;
          minI = j;
        }
      }
    }

    if(minI >= 0) {
      visitedKen[minI] = 1;
    } else {
      visitedKen[maxI] = 1;
      war += 1;
    }
  }

  for(int i = 0; i < N; i++) {
      visitedKen[i] = 0;
  }

  for(int i = 0; i < N; i++) {
    min = 2;
    minI = -1;
    max = -1;
    maxI = -1;

    double now = naomi[i];
    for(int j = 0; j < N; j++) {
      if(visitedKen[j] == 1) continue;

      double know = ken[j];
      if(now > know) {
        if(now - know < min) {
          min = now - know;
          minI = j;
        }
      } else {
        if(know - now > max) {
          max = know - now;
          maxI = j;
        }
      }
    }

    if(minI >= 0) {
      visitedKen[minI] = 1;
      dwar += 1;
    } else {
      visitedKen[maxI] = 1;
    }
  }

  myfile << "Case #" << n << ": " << dwar << " " << war << endl;
  cout << "Case #" << n << ": " << dwar << " " << war << endl;
}

int main() {
  cin >> T;
  myfile.open("d.output");
  for(int i = 0; i < T; i++) {
    input();
    process(i + 1);
  }
  myfile.close();
}
