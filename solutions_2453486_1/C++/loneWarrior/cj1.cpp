#include<iostream>

using namespace std;

int main()
{
  int c, T, i, j;
  bool x[4][4], o[4][4], winX, winO, empty;
  char ch;
  cin>>T;
  c=1;
  while(T--)
  {
    cout<<"Case #"<<c<<": ";
    c++;
    empty=winX=winO=false;
    for(i=0;i<4;++i)
    {
      for(j=0; j<4; ++j)
      {
	ch='a';
	while(ch!='X' && ch!='O' && ch!='T' && ch!='.')
	  cin>>ch;
	if(ch=='O' || ch=='T')
	  o[i][j]=1;
	else
	  o[i][j]=0;
	if(ch=='T' || ch=='X')
	  x[i][j]=1;
	else
	  x[i][j]=0;
	if(ch=='.')
	  empty=true;
      }
      if(x[i][0] && x[i][1] && x[i][2] && x[i][3])
	winX=true;
      else if(o[i][0] && o[i][1] && o[i][2] && o[i][3])
	winO=true;
    }
    for(i=0; i<4; ++i)
    {
      if(x[0][i] && x[1][i] && x[2][i] && x[3][i])
	winX=true;
      else if(o[0][i] && o[1][i] && o[2][i] && o[3][i])
	winO=true;
    }
    if((x[0][0] && x[1][1] && x[2][2] && x[3][3]) || (x[3][0] && x[2][1] && x[1][2] && x[0][3]))
      winX=true;
    else if((o[0][0] && o[1][1] && o[2][2] && o[3][3]) || (o[3][0] && o[2][1] && o[1][2] && o[0][3]))
      winO=true;
    if(winX)
      cout<<"X won\n";
    else if(winO)
      cout<<"O won\n";
    else if(empty)
      cout<<"Game has not completed\n";
    else
      cout<<"Draw\n";
  }
  return 0;
}