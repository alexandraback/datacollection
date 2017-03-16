#include <cstdio>

void treatThin(int sX, int sY, int nbM)
{
  if (sX*sY <= nbM)
  {
    printf("Impossible");
    return;
  }

  for (int i = 1; i < sX*sY; ++i)
  {
    if (i <= nbM) putchar('*');
    else putchar('.');
    if (sX == 1) putchar('\n');
  }
  putchar('c');
  putchar('\n');
}

void treatThick(int sX, int sY, int nbM)
{
  char map[sX][sY];
  for (int x = 0; x < sX; ++x)
  for (int y = 0; y < sY; ++y)
    map[x][y] = '*';

  while (1)
  {
    int nbFree = sX*sY - nbM;
    if (nbFree == 1)
      break;
    if (nbFree < 8 && nbFree!=4 && nbFree!=6)
    {
      printf("Impossible\n");
      return;
    }
    if ((sX == 2 || sY == 2) && nbFree%2 == 1)
    {
      printf("Impossible\n");
      return;
    }

    // Monads... :(

    for (int x = 0; x < 2; ++x)
    for (int y = 0; y < 2; ++y)
      map[x][y] = '.';
    nbFree -= 4;
    if (nbFree == 0) break;

    if (sY > 2)
    {
      map[0][2] = map[1][2] = '.';
      nbFree -= 2;
      if (nbFree == 0) break;
    }

    int maxX = 2;
    while (nbFree > 1 && maxX < sX)
    {
      map[maxX][0] = map[maxX][1] = '.';
      nbFree -= 2;
      ++maxX;
    }

    int maxY = 3;
    while (nbFree > 1 && maxY < sY)
    {
      map[0][maxY] = map[1][maxY] = '.';
      nbFree -= 2;
      ++maxY;
    }

    if (nbFree == 1)
    {
      map[2][2] = '.';
      break;
    }
    if (nbFree == 0) break;

    for (int x = 2; nbFree > 0 && x < sX; ++x)
    for (int y = 2; nbFree > 0 && y < sY; ++y)
    {
      map[x][y] = '.';
      --nbFree;
    }
    break;
  }

  map[0][0] = 'c';

  for (int y = 0; y < sY; ++y)
  {
    for (int x = 0; x < sX; ++x)
      putchar(map[x][y]);
    putchar('\n');
  }
}

void treatCase()
{
  int sX, sY, nbM;
  scanf("%d%d%d", &sY, &sX, &nbM);

  if (sX == 1 || sY == 1)
    treatThin(sX,sY,nbM);
  else
    treatThick(sX,sY,nbM);
 }

int main()
{
  int nbCases;
  scanf("%d", &nbCases);
  for (int iCase = 1; iCase <= nbCases; ++iCase)
  {
    printf("Case #%d:\n", iCase);
    treatCase();
  }
  return 0;
}
