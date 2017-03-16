#include<iostream>
using namespace std;

const int MAX = 100;

int data[MAX][MAX];
int H,W;

void input(){
   cin >> H >> W;
   for(int i = 0 ; i < H ; i++){
      for(int j = 0 ; j < W ; j++){
	 cin >> data[i][j];
      }
   }
}

bool solve(){
   input();
   for(int i = 0 ; i < H ; i++){
      for(int j = 0 ; j < W ; j++){
	 bool f1,f2;
	 f1 = f2 = false;
	 for(int k = 0 ; k < H ; k++){
	    if(data[k][j] > data[i][j])f1 = true;
	 }
	 for(int k = 0 ; k < W ; k++){
	    if(data[i][k] > data[i][j])f2 = true;
	 }
	 if(f1 && f2)return false;
      }
   }
   return true;
}

int main(){
   int tc;
   cin >> tc;
   for(int i = 1 ; i <= tc ; i++){
      cout << "Case #" << i << ": ";
      cout << (solve()?"YES":"NO") << endl;
   }
   return 0;
}
