#include <iostream>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f

vector<double> prob;

double avg(int a, int b){
  vector<double> correct;
  correct.push_back(prob[0]);
  double temp = prob[0];
  for (int i = 1; i < prob.size(); ++i){
    temp *= prob[i];
    correct.push_back(temp);
  }
  vector<double> choices;
  for (int i = 0; i < correct.size(); ++i){
    int winStrokes = correct.size() - (i + 1) + (b - (i + 1)) + 1;
    double p = correct[i] * winStrokes + (1. - correct[i]) * (winStrokes + b + 1);
    choices.push_back(p);
  }
  choices.push_back(b + 2);
  double best = INF;
  for (int i = 0; i < choices.size(); ++i)
    if (choices[i] < best)
      best = choices[i];
  return best;
}

int main(){
  int t; cin>>t;
  cout.precision(6);
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 1; i <= t; ++i){
    int a, b; cin>>a>>b;
    for (int j = 0; j < a; ++j){
      double p; cin>>p; prob.push_back(p);
    }

    cout<<"Case #"<<i<<": "<<avg(a,b)<<endl;

    prob.clear();
  }
}
