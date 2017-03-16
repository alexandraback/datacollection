#include <iostream>

using namespace std;

void icheck(char **f, int r, int c, int s_i, int s_j)
{
  int m_cnt = 0;
  if (s_i != 0)
  {
    m_cnt += f[s_i - 1][s_j] == '*';
    if (s_j != 0)
      m_cnt += f[s_i - 1][s_j-1] == '*';
    if (s_j != c - 1)
      m_cnt += f[s_i - 1][s_j+1] == '*';
  }
  if (s_i != r-1)
  {
    m_cnt += f[s_i + 1][s_j] == '*';
    if (s_j != 0)
      m_cnt += f[s_i + 1][s_j-1] == '*';
    if (s_j != c - 1)
      m_cnt += f[s_i + 1][s_j+1] == '*';
  }

  if (s_j != 0)
    m_cnt += f[s_i][s_j-1] == '*';
  if (s_j != c-1)
    m_cnt += f[s_i][s_j+1] == '*';

  f[s_i][s_j] = '0' + m_cnt;
  if (f[s_i][s_j] == '0')
  {
    for (int i = s_i-1; i <= s_i+1; i++)
      for (int j = s_j-1; j <= s_j+1; j++)
      {
        if (i >= 0 && i < r && j >= 0 && j < c)
          if (f[i][j] == '.')
            icheck(f, r, c, i, j);
      }
  }
}

bool check(char **in_f, int r, int c, int m)
{
  int i, j, s_i = -1, s_j = -1;
  char **f = new char*[r];
  for (i = 0; i < r; i++)
  {
    f[i] = new char [c];
    for (j = 0; j < c; j++)
    {
      f[i][j] = in_f[i][j];
      if (f[i][j] == '*')
        m--;
      else if (f[i][j] == 'c')
      {
        s_i = i; s_j = j;
      }
    }
  }
  bool result = false;
  if (s_i >= 0 && s_j >= 0 && m >= 0)
  {
    icheck(f, r, c, s_i, s_j);
    for (i = 0; i < r; i++)
    {
      for (j = 0; j < c; j++)
      {
        result |= f[i][j] == '.';
      }
    }
  }
  else
    result = true;

  for (i = 0; i < r; i++)
    delete [] f[i];
  delete [] f;
  return !result;
}

int main()
{
  /*
  //Generator for check;
  int q, p, a;
  cout<<10*10*10*10<<endl;
  for (q = 1; q <= 10; q++)
    for (p =1; p <= 10; p++)
      for (a = 1; a < p*q; a++)
        cout<<q<<" "<<p<<" "<<a<<endl;
  return 0;*/
  int T = 0;
  cin>>T;
  for (int t = 1; t <= T; t++)
  {
    int answer = 1;

    char **field = NULL;
    int R, C, M, i, j;
    cin>>R>>C>>M;
    field = new char* [R];
    for (i = 0; i < R; i++)
    {
      field[i] = new char [C+1];
      for (j = 0; j < C; j++)
        field[i][j] = '*';
      field[i][C] = 0;
    }


    int F = R*C - M;
    bool possible = true;
    if (F != 1)
    {
      if (R >= 3 && C >= 3)
      {
        switch (F)
        {
          case 2:
          case 3:
          case 5:
          case 7:
            possible = false;
            break;
          case 9:
            field[2][2] = '.';
          case 8:
            field[2][0] = field[2][1] = '.';
          case 6:
            field[0][2] = field[1][2] = '.';
          case 4:
            field[0][0] = field[0][1] = field[1][0] = field[1][1] = '.';
            break;
          default:
          {
            if (F <= C*3)
            {
              for (i = 0; i < F/3; i++)
                field[0][i] = field[1][i] = field[2][i] = '.';
              switch (F%3)
              {
                case 1:
                  field[2][F/3 - 1] = '*';
                case 2:
                {
                  field[0][F/3] = field[1][F/3] = '.';
                } break;
              }
            }
            else
            {
              for (i = 0; i < C; i++)
                field[0][i] = field[1][i] = field[2][i] = '.';
              F = F - C*3;
              for (i = 0; i < F/C; i++)
                for (j = 0; j < C; j++)
                  field[3+i][j] = '.';
              if (F%C == 1)
              {
                field[3+F/C][0] = field[3+F/C][1] = '.';
                field[2+F/C][C-1] = '*';
              }
              else if (F%C > 0)
              {
                for (i = 0; i < F%C; i++)
                  field[3+F/C][i] = '.';
              }
            }
          }
        }
      }
      else if (R==1 || C==1)
      {
        if (R==1)
          for (i = 0; i < F; i++)
            field[0][i] = '.';
        else
          for (i = 0; i < F; i++)
            field[i][0] = '.';
      }
      else
      {
        if (F%2 == 1 || F <= 3)
          possible = false;
        else
        {
          if (R==2)
            for (i = 0; i < F/2; i++)
              field[0][i] = field[1][i] = '.';
          else
            for (i = 0; i < F/2; i++)
              field[i][0] = field[i][1] = '.';
        }
      }
    }

    field[0][0] = 'c';

    //Check result;
    /*if (possible)
    {
      if (!check(field, R, C, M) )
        cerr<<"Error: "<<R<<" "<<C<<" "<<M<<endl;
    }*/

    cout<<"Case #"<<t<<":\n";
    if (possible)
    {
      for (i = 0; i < R; i++)
        cout<<field[i]<<"\n";
    }
    else
      cout<<"Impossible\n";
    for (i = 0; i < R; i++)
      delete [] field[i];
    delete [] field;
  }
  return 0;
}
