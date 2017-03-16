#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int tc; scanf("%d", &tc);
  char t[4][4];
  int i,j,nk;
  string s;
  int done;
  for(int tci = 0; tci < tc; tci++) {
	  for(i = 0; i < 4; i++) {
//		for(int j = 0; j < 4; j++) {
		scanf(" %c%c%c%c",&t[0][i],&t[1][i],&t[2][i],&t[3][i]);
		}
		done =0;
		s="Game has not completed";
//wiersze x won
		for(i = 0; i < 4; i++) {
			if (((t[0][i]=='X')||(t[0][i]=='T')) && ((t[1][i]=='X')||(t[1][i]=='T')) && 
			   ((t[2][i]=='X')||(t[2][i]=='T')) && ((t[3][i]=='X')||(t[3][i]=='T')) ) {
			   s="X won";done=1;break;	}}
//wiersze O won
		for(i = 0; i < 4; i++) {
			if (((t[0][i]=='O')||(t[0][i]=='T')) && ((t[1][i]=='O')||(t[1][i]=='T')) && 
			   ((t[2][i]=='O')||(t[2][i]=='T')) && ((t[3][i]=='O')||(t[3][i]=='T')) ) {
		s="O won";done=1;break;	}}

//kolumny X won
		for(i = 0; i < 4; i++) {
			if (((t[i][0]=='X')||(t[i][0]=='T')) && ((t[i][1]=='X')||(t[i][1]=='T')) && 
			   ((t[i][2]=='X')||(t[i][2]=='T')) && ((t[i][3]=='X')||(t[i][3]=='T')) ) {
		s="X won";done=1;break;	}}
//kolumny O won
		for(i = 0; i < 4; i++) {
			if (((t[i][0]=='O')||(t[i][0]=='T')) && ((t[i][1]=='O')||(t[i][1]=='T')) && 
			   ((t[i][2]=='O')||(t[i][2]=='T')) && ((t[i][3]=='O')||(t[i][3]=='T')) ) {
		s="O won";done=1;break;	}}
//przek_1 X won
			if (((t[0][0]=='X')||(t[0][0]=='T')) && ((t[1][1]=='X')||(t[1][1]=='T')) && 
			   ((t[2][2]=='X')||(t[2][2]=='T')) && ((t[3][3]=='X')||(t[3][3]=='T')) ) {
	         	s="X won";done=1;}
//przek_1 O won
			if (((t[0][0]=='O')||(t[0][0]=='T')) && ((t[1][1]=='O')||(t[1][1]=='T')) && 
			   ((t[2][2]=='O')||(t[2][2]=='T')) && ((t[3][3]=='O')||(t[3][3]=='T')) ) {
			  s="O won";done=1;	}
//PRZEK_2 X won
			if (((t[3][0]=='X')||(t[3][0]=='T')) && ((t[2][1]=='X')||(t[2][1]=='T')) && 
			   ((t[1][2]=='X')||(t[1][2]=='T')) && ((t[0][3]=='X')||(t[0][3]=='T')) ) {
			  s="X won";done=1;	}
//PRZEK_2 O won
			if (((t[3][0]=='O')||(t[3][0]=='T')) && ((t[2][1]=='O')||(t[2][1]=='T')) && 
			   ((t[1][2]=='O')||(t[1][2]=='T')) && ((t[0][3]=='O')||(t[0][3]=='T')) ) {
			  s="O won";done=1;	}
nk=1;
if (s=="Game has not completed") {
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
		if (t[j][i]=='.') nk=-1; 
		}
	}
	if (nk==1) s="Draw";
}

				
    printf("Case #%d: %s\n", tci+1, s.c_str());
  }
  return 0;
}

