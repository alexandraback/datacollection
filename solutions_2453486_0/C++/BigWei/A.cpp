#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>

#define TIED 0
#define XWON 1
#define OWON 2
#define NOTCOMPLETED 3

using namespace std;
char board[4][4];
bool used [4][4];
bool check(int r, int c){
  return (r >=0 && r <4 && c >=0 && c < 4);
}
int find(int depth , int r,  int c){
  if(board[r][c] == '.')return -1;
  int get = 0;
  for(int i=0;i<4;i++){
	if(board[r][i] == board[r][c] || board[r][i]=='T')get ++;
  }
  if(get == 4)return board[r][c]=='O' ? OWON : XWON;
  get=  0;
  for(int i=0;i<4;i++){
	if(board[i][c] == board[r][c] || board[i][c]=='T')get ++;
  }
  if(get == 4)return board[r][c]=='O' ? OWON : XWON;
  get = 0;
  for(int i=0;i<4;i++){
	if(board[i][i] == board[r][c] || board[i][i] == 'T')get++;
  }
  if(r == c && get == 4)return board[r][c]=='O' ? OWON : XWON;
  
  get = 0;
  for(int i=0;i<4;i++){
	if(board[i][3-i] == board[r][c] || board[i][3-i] == 'T')get++;
  }
  if(r == 3-c && get == 4)return board[r][c]=='O' ? OWON : XWON;

  return -1;	

}
int main(){
  int N , M , D;
  cin >> N;
  map<int  , string> Map;
  Map[0] = "Draw";Map[1]="X won"; 
  Map[2] = "O won"; Map[3] = "Game has not completed";
  for(int c=1;c<=N;c++){
	for(int i=0;i<4;i++)for(int j=0;j<4;j++){board[i][j]=0;used[i][j]=0;}
	string s;
	getline(cin , s);
	for (int r=0;r<4 ; r++){
	  getline(cin , s);
	  for (int i=0;i<4;i++){
		board[r][i] = s[i];
	  }
	}
	int ans = -1;
	for(int i=0;i<4;i++){
	  ans = -1;
	  for(int j=0;j<4;j++){
		ans = find(0 , i , j);
//		cout<<i<<" "<<j<<" "<<ans<<endl;
		if(ans !=-1 ){
		  cout <<"Case #"<<c<<": "<<Map[ans]<<endl;break;
		}
	  }
	  if(ans !=-1)break;
	}
	int notcom = 0;
	if(ans ==-1){
	  for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
		  if(board[i][j]=='.'){
			cout <<"Case #"<<c<<": "<<Map[3]<<endl;
			notcom = 1;
			break;
		  }
		  if(notcom == 1)break;
		}
	  if(!notcom)
		cout <<"Case #"<<c<<": "<<Map[0]<<endl;					
	}
  }

}
