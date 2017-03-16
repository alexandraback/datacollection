#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++)
    {
      char arr[4][4];
      for(int i = 0; i < 4; i++)
	for(int j = 0; j < 4; j++)
	  {
	    char c;
	    cin >> c;
	    arr[i][j] = c;
	  }

      bool xwon = false;
      bool owon = false;
      bool draw = true;
      bool gnc = false;

      //rows
      for(int i = 0; i < 4; i++)
	{
	  int cnt[256] = {0};
	  for(int j = 0; j < 4; j++)
	    cnt[(int)arr[i][j]]++;
	  if(cnt[(int)'.'] > 0)
	    {
	      draw = false;
	      gnc = true;
	    }
	  if(cnt[(int)'X'] ==4 || (cnt[(int)'X'] == 3 && cnt[(int)'T'] == 1))
	    xwon = true;
	  if(cnt[(int)'O'] ==4 || (cnt[(int)'O'] == 3 && cnt[(int)'T'] == 1))
	    owon = true;
	}

      //cols
      for(int i = 0; i < 4; i++)
	{
	  int cnt[256] = {0};
	  for(int j = 0; j < 4; j++)
	    cnt[(int)arr[j][i]]++;
	  if(cnt[(int)'.'] > 0)
	    {
	      draw = false;
	      gnc = true;
	    }
	  if(cnt[(int)'X'] ==4 || (cnt[(int)'X'] == 3 && cnt[(int)'T'] == 1))
	    xwon = true;
	  if(cnt[(int)'O'] ==4 || (cnt[(int)'O'] == 3 && cnt[(int)'T'] == 1))
	    owon = true;
	}

      //diag1
      int cnt1[256] = {0};
      for(int i = 0; i < 4; i++)
	cnt1[(int)arr[i][i]]++;
      if(cnt1[(int)'.'] > 0)
	{
	  draw = false;
	  gnc = true;
	}
      if(cnt1[(int)'X'] ==4 || (cnt1[(int)'X'] == 3 && cnt1[(int)'T'] == 1))
	xwon = true;
      if(cnt1[(int)'O'] ==4 || (cnt1[(int)'O'] == 3 && cnt1[(int)'T'] == 1))
	owon = true;

      //diag2
      int cnt2[256] = {0};
      for(int i = 0; i < 4; i++)
	cnt2[(int)arr[i][3-i]]++;
      if(cnt2[(int)'.'] > 0)
	{
	  draw = false;
	  gnc = true;
	}
      if(cnt2[(int)'X'] ==4 || (cnt2[(int)'X'] == 3 && cnt2[(int)'T'] == 1))
	xwon = true;
      if(cnt2[(int)'O'] ==4 || (cnt2[(int)'O'] == 3 && cnt2[(int)'T'] == 1))
	owon = true;

      //re
      cout << "Case #" << tc << ": ";
      if(xwon)
	{
	  cout << "X won\n";
	  continue;
	}
      if(owon)
	{
	  cout << "O won\n";
	  continue;
	}
      if(draw)
	{
	  cout << "Draw\n";
	  continue;
	}
      if(gnc)
	{
	  cout << "Game has not completed\n";
	  continue;
	}

    }
  return 0;
}
