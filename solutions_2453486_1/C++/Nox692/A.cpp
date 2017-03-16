#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

string field[4];
bool isT;
int tx, ty;

char column(){
  for(int x = 0 ; x < 4 ; x++){
    int cnt = 0;
    char ret = '#';
    for(int y = 0 ; y < 3 ; y++){
      if(field[y][x] == '.') break;
      if(ret == '#') ret = field[y][x];
      if(field[y][x] == field[y+1][x]) cnt++;
      else break;
    }
    if(cnt == 3) return ret;
  }
  return '0';
}

char row(){
  for(int y = 0 ; y < 4 ; y++){
    int cnt = 0;
    char ret = '#';
    for(int x = 0 ; x < 3 ; x++){
      if(field[y][x] == '.') break;
      if(ret == '#') ret = field[y][x];
      if(field[y][x] == field[y][x+1]) cnt++;
      else break;
    }
    if(cnt == 3) return ret;
  }
  return '0';
}

char diagonal(){
  int cnt = 0;
  char ret = '#';
  for(int i = 0 ; i < 3 ; i++){
    if(field[i][i] == '.') break;
    if(ret == '#') ret = field[i][i];
    if(field[i][i] == field[i+1][i+1]) cnt++;
    else break;
  }
  if(cnt == 3) return ret;
  cnt = 0;
  ret = '#';
  for(int i = 0 ; i < 3 ; i++){
    if(field[i][3-i] == '.') break;
    if(ret == '#') ret = field[i][3-i];
    if(field[i][3-i] == field[i+1][3-i-1]) cnt++;
    else break;
  }

  if(cnt == 3) return ret;
  return '0';
}

void output(int cs){
  string ret;
  bool f = false;
  char ans;
  
  cout << "Case #" << cs << ": ";

  if(isT){
    for(int i = 0 ; i < 2 ; i++){
      if(i == 0) field[ty][tx] = 'O';
      if(i == 1) field[ty][tx] = 'X';
      ans = column();
      if(ans != '0'){
	cout << ans << " won" << endl;
	return;
      }
      ans = row();
      if(ans != '0' && !f){
	cout << ans << " won" << endl;
	return;
      }
      ans= diagonal();
      if(ans != '0' && !f){
	cout << ans << " won" << endl;
	return;
      }
    }
  }
  else{
    ans = column();
    if(ans != '0'){
      cout << ans << " won" << endl;
      return;
    }
    ans = row();
    if(ans != '0' && !f){
      cout << ans << " won" << endl;
      return;
    }
    ans= diagonal();
    if(ans != '0' && !f){
      cout << ans << " won" << endl;
      return;
    }
  }
  
  bool flag = true;
  for(int i = 0 ; i < 4 ; i++){ // 全部埋まってるか
    for(int j = 0 ; j < 4 ; j++){
	if(field[i][j] == '.') flag = false;
    }
  }
  if(flag){
    cout << "Draw" << endl;
    return;
  }
  
  
  if(!f){
    cout << "Game has not completed" << endl;
    return;
  }
}

int main(){
  int T;
  cin >> T;
  for(int cs = 1 ; cs <= T ; cs++){
    for(int i = 0 ; i < 4 ; i++){
      cin >> field[i];
    }
    isT = false;
    for(int i = 0 ; i < 4 ; i++){
      for(int j = 0 ; j < 4 ; j++){
	if(field[i][j] == 'T'){
	  tx = j;
	  ty = i;
	  isT = true;
	}
      }
    }       
    output(cs);
  }
  return 0;
}
