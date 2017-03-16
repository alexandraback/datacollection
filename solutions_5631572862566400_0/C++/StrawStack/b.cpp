#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct child{
  int id;
  int f;
};

void pv(vector<int> v){
  for(int i=0; i<v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

void pv(vector<child> v){
  for(int i=0; i<v.size(); i++){
    cout << v[i].id << "-(" << v[i].f << ") ";
  }
  cout << endl;
}

int lrg = 0;
void recurs( vector<child> left, vector<child> part){
/*
  cout << "for" << endl;
  cout << "left: ";
  pv(left);
  cout << "part: ";
  pv(part);
*/

  if(part.size() >= 2){
  if( (part[0].id == part[part.size()-1].f || part[part.size()-1].f == part[part.size()-2].id) && (part[0].f == part[part.size()-1].id || part[0].f == part[1].id)){
    lrg = max(lrg, static_cast<int>(part.size()));
    //cout << "lrg is now: " << lrg << endl;
  }
}

  // for each kid in left, try to add to circle
  for(int i=0; i<left.size(); i++){
    if( part[part.size()-1].id == left[i].f){
      vector<child> cleft = left;
      vector<child> cpart = part;
      cpart.push_back( cleft[i] );
      cleft.erase( cleft.begin() + i );
/*
      cout << "trying recurs with " << endl;
      cout << "cleft: ";
      pv(cleft);
      cout << "cpart: ";
      pv(cpart);
*/
      recurs( cleft, cpart );

    }
    if( left[i].f == part[0].id ){
      vector<child> cleft = left;
      vector<child> cpart = part;
      cpart.push_back( cleft[i] );
      cleft.erase( cleft.begin() + i );

      if( (cpart[0].id == cpart[cpart.size()-1].f || cpart[cpart.size()-1].f == cpart[cpart.size()-2].id) && (cpart[0].f == cpart[cpart.size()-1].id || cpart[0].f == cpart[1].id)){
        lrg = max(lrg, static_cast<int>(cpart.size()));
      }

    }
  }
}

int main(){

  int T;
  cin >> T;
  for(int t=1; t<=T; t++){

    int N;
    cin >> N;
    vector<child> v;
    for(int i=0; i<N; i++){
      child c;
      int t;
      cin >> t;
      c.id = i+1;
      c.f = t;
      v.push_back( c );
    }
    lrg = 0;
    for(int i=0; i<N; i++){
      vector<child> cv = v;
      vector<child> cp;
      cp.push_back( cv[i] );
      cv.erase(cv.begin() + i);
      recurs( cv, cp );
    }

    cout << "Case #" << t << ": " << lrg << endl;
  }

  return 0;
}
/*
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3

*/
