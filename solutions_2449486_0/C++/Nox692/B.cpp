#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int field[100][100];
int N, M;

bool north(int y, int x){
  int a = field[y][x];
  for(int i = y ; i >= 0 ; i--){
    if(field[i][x] > a) return true;
  }
  return false;
}

bool south(int y, int x){
  int a = field[y][x];
  for(int i = y ; i < N ; i++){
    if(field[i][x] > a) return true;
  }
  return false;
}

bool east(int y, int x){
  int a = field[y][x];
  for(int i = x ; i >= 0 ; i--){
    if(field[y][i] > a) return true;
  }
  return false;
}

bool west(int y, int x){
  int a = field[y][x];
  for(int i = x ; i < M ; i++){
    if(field[y][i] > a) return true;
  }
  return false;
}

bool solve(){
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      if((north(i, j) || south(i, j)) && (east(i, j) || west(i, j))){
	return false;
      }
    }
  }
  return true;
}

int main(){
  int T;
  cin >> T;
  for(int cs = 1 ; cs <= T ; cs++){
    cin >> N >> M;

    for(int i = 0 ; i < N ; i++){
      for(int j = 0 ; j < M ; j++){
	cin >> field[i][j];
      }
    }
    cout << "Case #" << cs << ": ";
    if(solve()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
