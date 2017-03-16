#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream f("input.txt");
ofstream w("output.txt");
int R,C,M;
char matrix[250][250];
int c,r;


void printAnswer()
{
  
  bool vw=false;
  if (c!=C||r!=R)vw=true;
  if (vw)
  for (int i=0;i<c;i++)
  {
    for (int j=0;j<r;j++)
      w<<matrix[j][i];
    w<<endl;
  }
  else
    for (int i=0;i<r;i++)
  {
    for (int j=0;j<c;j++)
      w<< matrix[i][j];
    w<<endl;
  }
}

bool solve33(int ofr,int ofc, int M)
{
    for (int i=0;i<M/3;i++)
       for (int j=0;j<3;j++) 
	matrix[i+ofr][j+ofc]='*';
      if (M==1)
      {
	matrix[ofr][ofc]='*';
	return true;
      }
      else if (M==3)
      {
	return true;
      } else if (M==5)
      {
	matrix[ofr+1][ofc]='*';
	matrix[ofr+2][ofc]='*';
	return true;
      }
      else if (M==6)
      {
	return false;
      }
      else if (M==7)
      {
	return false;
      }
      else if (M==8)
      {
	for (int i=0;i<3;i++)
       for (int j=0;j<3;j++) 
	matrix[i+ofr][j+ofc]='*';
       matrix[2+ofr][2+ofc]='c';
	return true;
      } else
      {
	return false;
	
      }
      return true;
}

int main()
{
  
  int T;
  f>>T;
  for (int ti=1;ti<=T;ti++)
  {
    f>>R>>C>>M;
    w<<"Case #"<<ti<<":"<<endl;
    memset(matrix,'.',250*250*sizeof(char));
     c = min(R,C);
     r = max(R,C);
    matrix[r-1][c-1]='c';
    if (c==3){
      for (int i=0;i<M/3;i++)
       for (int j=0;j<3;j++) 
	matrix[i][j]='*';
      
      if (M<=(r-3)*c+1){
	if (M%3==0)
	{
	 printAnswer();
	  continue;
	}
	else if (M%3==1)
	{
	  matrix[M/3][0]='*';
	  printAnswer();
	  continue;
	} else
	{
	  matrix[M/3][0]='*';
	  matrix[M/3+1][0]='*';
	  printAnswer();
	  continue;
	}
      } else{
	if (solve33(r-3,0,M-(r-3)*c)){
	  printAnswer();
	  continue;
	} else {
	  w<<"Impossible"<<endl;
	continue;
	}
      }
      

    } else if (c==2)
    {
      for (int i=0;i<M/2;i++)
       for (int j=0;j<c;j++) 
	matrix[i][j]='*';
      if (M%2==0&&M<=(r-2)*2)
      {
	printAnswer();
	continue;
      } else if (M%2==1&&M==(r-1)*2+1)
      {
	matrix[r-1][0]='*';
	printAnswer();
	continue;
      } else
      {
	w<<"Impossible"<<endl;
	continue;
      }
    } else if (c==1){
      for (int i=0;i<M;i++)
	matrix[i][0]='*';
      if (M<r)
      {
	printAnswer();
	continue;
      } else
      {
	w<<"Impossible"<<endl;
	continue;
      }
    } else {
      if (M<=(c-3)*(r-3)){
	int tm=0;
	for (int i=0;i<r-3;i++){
	  if (tm==M) break;
	  for (int j=0;j<c-3;j++) {
	    tm++;
	    matrix[i][j]='*';
	    if (tm==M) break;
	  }
	}
	printAnswer();
	continue;
      }
      for (int i=0;i<r-3;i++)
	  for (int j=0;j<c-3;j++) 
	    matrix[i][j]='*';
	M-=(c-3)*(r-3);
      if (M<=3*(r-3))
      {
	int tm=0;
	for (int i=0;i<r-3;i++){
	  if (tm==M) break;
	  for (int j=c-3;j<c;j++) {
	    tm++;
	    matrix[i][j]='*';
	      if (tm==M) {
		if (j==c-2){
		  if(c-4!=0&&r-4!=0&&i!=r-4){
		    matrix[c-4][r-4]='.';
		    matrix[i][j+1]='*';
		  }else
		  {
		    matrix[i][j]='.';
		    if (matrix[i+1][0]=='.')
		    matrix[i+1][0]='*'; else matrix[i+2][0]='*';
		  }
		}
	      break;
	      }
	    }
	  
	}
	printAnswer();
	  continue;
      }
      M-=(r-3)*3;
      for (int i=0;i<r-3;i++)
	for (int j=c-3;j<c;j++) 
	  matrix[i][j]='*';
      if (M<=(c-3)*3)
      {
	int tm=0;
	for (int j=0;j<c-3;j++){
	  if (tm==M) break;
	   for (int i=r-3;i<r;i++){
	    tm++;
	    matrix[i][j]='*';
	      if (tm==M) {
		if (i==r-2){
		matrix[i][j]='.';
		matrix[r-3][j+1]='*';
		
		}
	      break;
	      }
	    }
	  
	}
	printAnswer();
	  continue;
      }
      M-=(c-3)*3;
      for (int i=r-3;i<r;i++)
	for (int j=0;j<c-3;j++) 
	  matrix[i][j]='*';
	if (solve33(r-3,c-3,M)){
	  printAnswer();
	  continue;
	} else {
	  w<<"Impossible"<<endl;
	continue;
	}
	
      
    }
      
  }
  
  
  return 0;
}