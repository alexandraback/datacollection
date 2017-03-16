#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <queue>
#define LL long long
using namespace std;

template<typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
    s << '{';
    for (int i = 0 ;i <  v.size(); ++i) {
        s << (i ? "," : "") << v[i];
    }
    return s << '}';
}

template<typename T, typename U>
ostream& operator<<(ostream& s, const pair<T,U>& p) {
  s << "(" << p.first << "," << p.second << ")";
  return s;
}



int honest(vector<double> ours, vector<double> theirs){

  int contour = 0;
  int max_contour = 0;
  while(ours.size() > 0 || theirs.size() > 0){

    double a;
    double b;

    if(ours.size() == 0){
      a = -1;
    }
    else{
      a = ours.back();
    }

    if(theirs.size() == 0){
      b = -1;
    }
    else{
      b = theirs.back();
    }


    if(a>b){
      contour++;
      ours.pop_back();
    }

    else if(a<b){
      contour--;
      theirs.pop_back();
    }

    if(contour > max_contour){
      max_contour = contour;
    }

  }

  return max_contour;

}


double extract_max(vector<double> &v){

  double max = -1;
  int pos = 0;
  for(int i=0; i<v.size(); i++){
    if(v[i]>max){
      max = v[i];
      pos = i;
    }
  }

  v.erase(v.begin()+pos);
  return max;
}

double extract_min(vector<double> &v){

  double min = 2;
  int pos = 0;
  for(int i=0; i<v.size(); i++){
    if(v[i]<min){
      min = v[i];
      pos = i;
    }
  }

  v.erase(v.begin()+pos);
  return min;
}



int cheater(vector<double> ours, vector<double> theirs){

  int score = 0;

  while(ours.size() > 0 || theirs.size() > 0){

    double our_min = ours[0];
    double our_max = ours[ours.size()-1];
    double their_min = theirs[0];
    double their_max = theirs[theirs.size()-1];


    if(our_min > their_min){

      // trade our min for their min
      score++;
      extract_min(ours);
      extract_min(theirs);

    }

    else{

      // trade our min for their max
      extract_min(ours);
      extract_max(theirs);

    }
    

  }

  return score;
  

}



int main(){

  int ncases; cin>>ncases;

  for(int nc = 1; nc <= ncases; nc++) {

    int NUM_WEIGHT; cin>>NUM_WEIGHT;

    vector<double> ours;
    vector<double> theirs;

    for(int i=0; i<NUM_WEIGHT; i++) {
      double t; cin>>t; ours.push_back(t);
    }
    for(int i=0; i<NUM_WEIGHT; i++) {
      double t; cin>>t; theirs.push_back(t);
    }

    sort(ours.begin(),ours.end());
    sort(theirs.begin(),theirs.end());


    cout << "Case #" << nc << ": " << cheater(ours,theirs) << " " << honest(ours,theirs) << endl;


  }



}


