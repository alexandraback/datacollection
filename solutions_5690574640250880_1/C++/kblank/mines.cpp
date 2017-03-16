#include<iostream>
#include<cstring>
using namespace std;
  int T, R, C, M;
  const int maks = 60;
  int t[maks][maks];
  int good[maks][maks];
    int bomb = 0;
    int row=0, col=0;
int lastr, lastc, lastb;
    int zero_neighbour = 0;

void fill_row(){
    while (bomb + C <= M && row < R-2) {
      bomb = bomb + (C-col);
      ++row;
      for(int j = 1; j <= C; ++j) t[row][j]=1;
    };
};

void fill_col(){
    while (bomb + (R-row) <= M && col < C-2) {
      bomb = bomb + (R-row);
      ++col;
      for(int j = row; j <= R; ++j) t[j][col]=1;
    };
};

void fill_row2(){
      for (int x = row+1; x<=R; ++x)
	for (int y = col+1; y <= C; ++y){
	  if (bomb<M) { t[x][y]=1; ++bomb;};
	};
};

void fill_col2(){
	for (int y = col+1; y <= C; ++y){
      for (int x = row+1; x<=R; ++x)

	  if (bomb<M) {t[x][y]=1; ++bomb;};
	};
};

bool check_possibility(){
    zero_neighbour = 0;
    for (int x = 1; x <= R; ++x)
      for (int y = 1; y <= C; ++y){
	if (t[x][y]==1) good[x][y] = -1;
	if (t[x][y] == 0) good[x][y] = t[x-1][y-1]+t[x-1][y]+t[x-1][y+1]+t[x][y-1]+t[x][y]+t[x][y+1]+t[x+1][y-1]+t[x+1][y]+t[x+1][y+1];
      };

    for (int x = 1; x <= R; ++x)
      for (int y = 1; y <= C; ++y){
	      if (good[x][y]==0) zero_neighbour++;
	      else if (good[x][y]>0) {
		bool zero = false;
		if (good[x-1][y-1]==0) zero=true;
		if (good[x-1][y]==0) zero=true;
		if (good[x-1][y+1]==0) zero=true;

		if (good[x][y-1]==0) zero=true;
		if (good[x][y+1]==0) zero=true;

		if (good[x+1][y-1]==0) zero=true;
		if (good[x+1][y]==0) zero=true;
		if (good[x+1][y+1]==0) zero=true;
		if (zero) zero_neighbour++;
	      };
      };
/*   cout << "bomb=" << bomb << endl;
   cout << "zero=" << zero_neighbour << endl;
   cout << "size=" << R*C << endl;*/
    if (zero_neighbour+bomb==R*C) return true;
    if (zero_neighbour==0 && bomb+1==R*C) return true;
    return false;
};

void extreme() {
  if (R-row==5 && C-col==5 && M-bomb==4){
    t[row+1][col+1]=1;
    t[row+1][C]=1;
    t[R][col+1]=1;
    t[R][C]=1;
    bomb+=4;
  }
  else if (R-row==5 && C-col==5 && M-bomb==16){
	  for (int a=row+1; a<=R; ++a) { t[a][col+1]=1; t[a][C]=1;};
	  for (int b=col+1; b<=C; ++b) {t[row+1][b]=1; t[R][b]=1;};
	  bomb+=16;
  }
  else if (R-row==4 && C-col==4 && M-bomb==3){
    t[row+1][col+1]=1;
    t[row+1][col+2]=1;
    t[row+2][col+1]=1;
    bomb+=3;
  };
};
/*
if (R-lastr==5 && C-lastc==5 && M-lastb==4) { //extreme case :-)
		possible = true;
		t[lastr+1][lastc+1]=1;
	} else
};*/


int main(){

  cin >> T;
  for (int i = 1; i <= T; ++i) {
    bool possible = false;
    memset(t, 0, sizeof(t));
    memset(good, -1, sizeof(good));
    cin >> R >> C >> M;

    cout << "Case #" << i << ": " << endl;
//    cout << R << " " <<  C << " " <<  M << endl;
    bomb = 0;
    row=0; col=0;
    // whole row
    for (int k = 1; k <= 4 && !possible; ++k){
      memset(t, 0, sizeof(t));
      memset(good, -1, sizeof(good));
      bomb = 0;
      row=0; col=0;
      switch (k) {
	      case 1: extreme(); fill_row(); fill_col();
		      extreme();
                      if (R-row > C-col)
	                fill_col2();
                      else
                        fill_row2();

		      break;
	      case 2: fill_row(); fill_col();
		      extreme();
                      if (R-row > C-col)
	                fill_row2();
                      else
                        fill_col2();

		      break;
	      case 3: fill_col(); fill_row();
		      extreme();
                      if (R-row > C-col)
	                fill_col2();
                      else
                        fill_row2();

		      break;
	      case 4: fill_col(); fill_row();
		      extreme();
		      lastr=row;lastc=col;lastb=bomb;
                      if (R-row > C-col)
	                fill_row2();
                      else
                        fill_col2();

		      break;
      };
      possible = check_possibility();

    };
//    fill_col();
//    fill_row();

/*    for (int x = 1; x <= R; ++x){
      for (int y = 1; y <= C; ++y){
	      cout << t[x][y];
      };
      cout << endl;
    };
    cout << "bomb=" << bomb << endl;*/
    // whole col
    //fill_col();

/*
    for (int x = 1; x <= R; ++x){
      for (int y = 1; y <= C; ++y){
	      cout << t[x][y];
      };
      cout << endl;
    };
    cout << "bomb=" << bomb << endl;
*/
    /*
    if (R-row > C-col) { // fill col
	    //fill_row2();
	    fill_col2();

    } else { //fill row
	    //fill_col2();
	    fill_row2();
    };*/
/*
    for (int x = 1; x <= R; ++x){
      for (int y = 1; y <= C; ++y){
	      cout << t[x][y];
      };
      cout << endl;
    };
    cout << "bomb=" << bomb << endl;
    */



    if (!possible) {
	    //cout << (R-lastr) << "x" << (C-lastc) << "  " << (M-lastb) << endl;

	  cout << "Impossible" << endl;
    }else{
    //if (possible)  {
//	cout << "possible" << endl;
   	    

      bool clicked = false;
      for (int x = 1; x <= R; ++x){
	for (int y = 1; y <= C; ++y){
          if (t[x][y] == 1) cout << "*";
	  else {
	    if (clicked) cout << ".";
	    else {
	      if (good[x][y]==0 || zero_neighbour==0){ clicked=true; cout << "c";}
	      else cout << ".";

	    };
	  };
	};
	cout << endl;
      };
    };
  };
};
