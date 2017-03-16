#include<iostream>
#include<fstream>

using namespace std;

int N;
double C;
double F;
double X;

ofstream myfile;

void input() {
  cin >> C;
  cin >> F;
  cin >> X;
}

void process(int n) {
  double answer = 987654321;
  double tmpAnswer;
  double R = 2;
  for(int i = 0; i * C <= X; i++) {
    R = 2;
    tmpAnswer = 0.0f;
    for(int j = 1; j <= i; j++) {
      tmpAnswer += (double)(C / R);
      R += F;
    }
    tmpAnswer += (double)(X / R);
    if(tmpAnswer < answer) {
      answer = tmpAnswer;
    }
  }

  cout.precision(9);
  myfile.precision(9);
  myfile << "Case #" << n << ": " << answer << endl;
  cout << "Case #" << n << ": " << answer << endl;
}

int main() {
  cin >> N;
  myfile.open("b.output");
  for(int i = 0; i < N; i++) {
    input();
    process(i + 1);
  }
  myfile.close();
}
