#include<iostream>
using namespace std;

char data[4][4];

int dy[] = {1,0,1,1};
int dx[] = {0,1,1,-1};

void input(bool& f){
   for(int i = 0 ; i < 4 ; i++){
      for(int j = 0 ; j < 4 ; j++){
	 cin >> data[i][j];
	 if(data[i][j] == '.')f = false;
      }
   }
}

const int X = 0;
const int O = 1;
const int T = 2;
const int ELSE = -1;

int rec(int x,int y,int d,int cnt[3],int now){
   if(now == 4){
      if(cnt[X] == 4)return X;
      if(cnt[O] == 4)return O;
      if(cnt[X] == 3 && cnt[T] == 1)return X;
      if(cnt[O] == 3 && cnt[T] == 1)return O;
      return ELSE;
   }
   if(data[y][x] == 'X')cnt[X]++;
   if(data[y][x] == 'O')cnt[O]++;
   if(data[y][x] == 'T')cnt[T]++;
   return rec(x + dx[d],y + dy[d],d,cnt,now+1);
}

void solve(){
   bool fin = true;
   input(fin);
   int win = ELSE;
   int cnt[3],r;
   for(int i = 0 ; i < 4 ; i++){
      for(int j = 0 ; j < 3 ; j++)cnt[j] = 0;
      r = rec(i,0,0,cnt,0);
      if(r != ELSE)win = r;
      for(int j = 0 ; j < 3 ; j++)cnt[j] = 0;
      r = rec(0,i,1,cnt,0);
      if(r != ELSE)win = r;
   }
   for(int j = 0 ; j < 3 ; j++)cnt[j] = 0;
   r = rec(0,0,2,cnt,0);
   if(r != ELSE)win = r;

   for(int j = 0 ; j < 3 ; j++)cnt[j] = 0;
   r = rec(3,0,3,cnt,0);
   if(r != ELSE)win = r;


   if(win == X)cout << "X won" << endl;
   else if(win == O)cout << "O won" << endl;
   else if(fin)cout << "Draw" << endl;
   else cout << "Game has not completed" << endl;

}

int main(){
   int tc;
   cin >> tc;
   for(int i = 1 ; i <= tc ; i++){
      cout << "Case #" << i << ": ";
      solve();
   }
   return 0;
}
