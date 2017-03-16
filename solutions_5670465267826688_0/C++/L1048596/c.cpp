#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("my.out");

int a[10000];


const int matrix[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 2, 3, 4},
  {0, 2, -1, 4, -3},
  {0, 3, -4, -1, 2},
  {0, 4, 3, -2, -1}
};

    // 1 --> 1
    // 2 --> i
    // 3 --> j
    // 4 --> k

int cal(int x, int y){
  int result = 1;
  if(x < 0){
    result = -result;
    x = -x;
  }
  if(y < 0){
    result = -result;
    y = -y;
  }
  return result*matrix[x][y];
}

bool foo(int index){
    int L;
    long long X;
    fin >> L >> X;
    //cout << L << X;
    for(int i=0; i<L; i++){
      char c;
      //cout << c;
      fin >> c;
      //cout << c << endl;
      a[i] = c - 'i' + 2;
    }


    if(L*X<3) return false;

    // for(int i=0; i<L; i++)
    //   cout << a[i];
    // cout << endl;

    int result;
    bool isOK;
    int i;

    //look for i
    int length = 0;

    for(result=1, isOK=false, i=0; i<L*X-2; i++){
      length++;
      result = cal(result, a[i%L]);
      //cout << result << endl;
      if(result == 2){
        isOK = true;
        break;
      }
      if(length > 4*L) return false;
    }
    //cout << i << endl;
    if(isOK == false) return false;

    //look for j
    length = 0;
    for(result=1, isOK=false, i++; i<L*X-1; i++){
      result = cal(result, a[i%L]);
      if(result == 3){
        isOK = true;
        break;
      }
      length ++;
      if(length > 4*L) return false;
    }
    if(isOK == false) return false;
    //cout << i << endl;

    //look for k
    length = 0;
    for(result=1, isOK=false, i++; i<L*X; i++){
      length ++;
      result = cal(result, a[i%L]);
      if(result == 4){
        isOK = true;
        break;
      }
      if(length > 4*L) return false;
    }
    if(isOK == false) return false;
    //cout << i << endl;

    int temp = i;

    i++;
    for(result=1; i<X*L; i++){
      result = cal(result, a[i%L]);
    }

    if(result == 1) isOK = true;
    else isOK = false;


    //return isOK;
    i = temp;
    i++;

    int t = (X*L-i)/(4*L);
    int END = (X-4*t)*L; 
    //cout << END << endl;
    for(result=1; i<END; i++){
      result = cal(result, a[i%L]);
    }

    //if((result == 1) != isOK ) cout << index << " WRONG!!" << endl;
    if(result == 1) return true;

    return false; 


}
int main(){
  int M;
  fin >> M;

  //cout << M << endl;
  for(int index=1; index<=M; index++){
    if(foo(index))
      fout << "Case #" << index << ": YES" << endl;
    else
      fout << "Case #" << index << ": NO" << endl;
  }
  return 0;
}