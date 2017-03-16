#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<char> >& vec, bool reverse)
{
  if(!reverse)
    {
      for(int i = 0; i < vec.size(); ++i)
	{
	  for(int j = 0; j < vec[0].size(); ++j)
	    {cout << vec[i][j];}
	  cout << endl;
	}
    }
  else
    {
      for(int i = 0; i < vec[0].size(); ++i)
	{
	  for(int j = 0; j < vec.size(); ++j)
	    {
	      cout << vec[j][i];
	    }
	  cout << endl;
	}
    }
}

int main()
{
  int tot;
  cin >> tot;
  for(int i = 0; i < tot; ++i)
    {
      int R,C,M;
      bool reverse=false;
      cin >> R >> C >> M;
      cout << "Case #" << i+1 << ":" << endl;
      if(R>C)
	{
	  swap(R,C);
	  reverse=true;
	}
      vector<vector<char> > vec(R, vector<char>(C, '.'));
      if(R==1)
	{
	  for(int ele=0; ele < M; ++ele)
	    {
	      vec[0][C-1-ele]='*';
	    }
	  vec[0][0]='c';
	  print(vec, reverse);
	}
      else if(R==2)
	{
	  if(M==2*C-1)
	    {
	      for(int a=0; a < R; ++a)
		{
		  for(int b = 0; b < C; ++b)
		    {vec[a][b]='*';}
		}
	      vec[0][0]='c';
	      print(vec, reverse);
	    }
	  else if(M%2==0 && (R*C-M)!=2)
	    {
	      for(int a=0; a<M/2; ++a)
		{
		  vec[0][C-1-a]='*';
		  vec[1][C-1-a]='*';
		}
	      vec[0][0]='c';
	      print(vec, reverse);
	    }
	  else
	    {
	      cout << "Impossible" << endl;
	    }
	}
      else
	{
	  int diff=R*C-M;
	  if(diff<=9)
	    {
	      vec=vector<vector<char> >(R, vector<char>(C, '*'));
	      switch(diff)
		{
		case 2:
		case 3:
		case 5:
		case 7:
		  cout << "Impossible" << endl;
		  break;
		case 1:
		  vec[0][0]='c'; print(vec, reverse); break;
		case 4:
		  vec[0][1]=vec[1][0]=vec[1][1]='.';
		  vec[0][0]='c'; print(vec, reverse); break;
		case 6:
		  vec[0][1]=vec[0][2]=vec[1][0]=vec[1][1]=vec[1][2]='.';
		  vec[0][0]='c'; print(vec, reverse); break;
		case 8:
		  for(int a=0; a<3; ++a)
		    {
		      for(int b=0; b<3; ++b)
			{vec[a][b]='.';}
		    }
		  vec[2][2]='*';
		  vec[0][0]='c';
		  print(vec, reverse); break;
		case 9:
		  for(int a=0; a<3; ++a)
		    {
		      for(int b=0; b<3; ++b)
			{vec[a][b]='.';}
		    }
		  vec[0][0]='c';
		  print(vec, reverse); break;
		}
	    }
	  else
	    {
	      vec[0][0]='c';
	      int r=R-1, c=C-1;
	      while(r>2 && M>0)
		{
		  vec[r][c]='*';
		  --M;
		  --c;
		  if(c<0)
		    {
		      --r;
		      c=C-1;
		    }
		}
	      if(M==0)
		{
		  if(c==0)
		    {
		      vec[r][1]='.';
		      vec[r-1][C-1]='*';
		    }
		  print(vec, reverse);
		}
	      else
		{
		  c=C-1;
		  r=2;
		  while(M>0)
		    {
		      vec[r][c]='*';
		      --r;
		      --M;
		      if(r<0)
			{--c; r=2;}
		    }
		  if(r==0)
		    {
		      vec[1][c]='.';
		      vec[2][c-1]='*';
		    }
		  print(vec, reverse);
		}
	    }
	}
    }
}
