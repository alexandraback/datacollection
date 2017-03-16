#include <cstdio>

char map[10][10];

bool check(char p)
{
  for(int i=0; i<4; i++) {
    bool done = true;
    for(int j=0; j<4; j++)
      if((map[i][j]!=p) && (map[i][j]!='T'))
        done = false;
    if(done)
      return true;

    done = true;
    for(int j=0; j<4; j++)
      if((map[j][i]!=p) && (map[j][i]!='T'))
        done = false;
    if(done)
      return true;
  }
  bool donediag = true;
  for(int i=0; i<4; i++)
    if((map[i][i]!=p) && (map[i][i]!='T'))
      donediag = false;
  if(donediag)
    return true;

  donediag = true;
  for(int i=0; i<4; i++)
    if((map[4-i-1][i]!=p) && (map[4-i-1][i]!='T'))
      donediag = false;
  if(donediag)
    return true;

  return false;
}

void solve(int c)
{
  for(int i=0; i<4; i++)
    scanf("%s",map[i]);

  if(check('X'))
    printf("Case #%d: X won\n",c+1);
  else if(check('O'))
    printf("Case #%d: O won\n",c+1);
  else {
    bool found = false;
    for(int i=0; i<4; i++)
      for(int j=0; j<4; j++)
        if(map[i][j]=='.')
          found = true;
    if(found)
      printf("Case #%d: Game has not completed\n",c+1);
    else
      printf("Case #%d: Draw\n",c+1);
  }
}

main()
{
  int t;
  scanf("%d",&t);
  for(int i=0; i<t; i++)
    solve(i);
}
