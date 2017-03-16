#include<stdio.h>

int main()
{
  int cases;

  char gridX[4][4];

  char gridO[4][4];

  cin>>cases;


  for(int cs = cases; cs > 0; cs--) {
    
	int xWin=0,oWin=0;

    int dotFound = 0;

	char line[4];


  for(int l=0;l<4;l++) {

	cin>>line

	  for(m=0;m<4;m++){
		 char c = line[m];
		 if(c == 'T') {
			gridX[l][m] = 'X';
			gridO[l][m] = 'O';
		 } else {
			 gridX[l][m]=c;
			 gridO[l][m]=c;
		 }

		 if(c == '.') {
			 dotFound = 1;
		 }
	   }
	}

   for(q=0;q<4;q++)
   {
    if((gridX[q][0]=='X')&&(gridX[q][1]=='X')&&(gridX[q][2]=='X')&&(gridX[q][3]=='X'))
	  xWin = 1;
    else if((gridX[0][q]=='X')&&(gridX[1][q]=='X')&&(gridX[2][q]=='X')&&(gridX[3][q]=='X'))
      xWin = 1;
    else if((gridX[q][0]=='O')&&(gridX[q][1]=='O')&&(gridX[q][2]=='O')&&(gridX[q][3]=='O'))
	  oWin = 1;
    else if((gridX[0][q]=='O')&&(gridX[1][q]=='O')&&(gridX[2][q]=='O')&&(gridX[3][q]=='O'))
      oWin = 1;
  }

   if((gridX[0][0]=='X')&&(gridX[1][1]=='X')&&(gridX[2][2]=='X')&&(gridX[3][3]=='X'))
	  xWin = 1;
   else if((gridX[0][3]=='X')&&(gridX[1][2]=='X')&&(gridX[2][1]=='X')&&((gridX[3][0]=='X')))
	  xWin = 1;
   else if((gridO[0][0]=='O')&&(gridO[1][1]=='O')&&(gridO[2][2]=='O')&&(gridO[3][3]=='O'))
      oWin = 1;
   else if((gridO[0][3]=='O')&&(gridO[1][2]=='O')&&(gridO[2][1]=='O')&&((gridO[3][0]=='O')))
      oWin = 1;

   if(xWin == 1){
	   cout <<"Case #%d: X won\n",cs;
   } else if (oWin == 1)  {
	   cout <<("Case #%d: O won\n",cs);
   } else {
		if(dotFound == 1) {
			cout<<"Case #%d: Game has not completed\n",cs;
		} else {
			cout<<"Case #%d: Draw\n",idx;
		}
   }
  }
}