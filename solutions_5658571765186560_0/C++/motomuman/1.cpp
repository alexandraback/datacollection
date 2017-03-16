#include<bits/stdc++.h>
using namespace std;

void solve(int CASE){
  cout << "Case #" << CASE << ": ";
  int X, R, C;
  cin >> X >> R >> C;
  if(R > C){
    swap(R, C);
  }
  if((R*C)%X != 0){
      cout << "RICHARD" << endl;
      return;
  }else if(max(R, C) < X){
      cout << "RICHARD" << endl;
      return;
  }else
  if(X == 1){
    cout << "GABRIEL"<< endl;
      return;
  }else if(X == 2){
    if((R*C) % 2 == 0){
      cout << "GABRIEL"<< endl;
      return;
    }else{
      cout << "RICHARD" << endl;
      return;
    }
  }else if(X==3){
    if(max(R, C) < 3 || C < 2){
      cout << "RICHARD" << endl;
      return;
    }else if((R==2 && C == 3) || (R == 3 && C == 3) || (R == 3 && C == 4)){
      cout << "GABRIEL"<< endl;
      return;
    }else{
      cout << "RICHARD" << endl;
      return;
    }
  }else{
    if( R >2 && C == 4){ 
      cout << "GABRIEL"<< endl;
      return;
    }else{
      cout << "RICHARD" << endl;
      return;
    }
  }
}


int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    solve(i+1);
  }
}

