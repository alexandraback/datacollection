#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int GCD(int a, int b)
{
  while(b != 0)
  {
    int x = a % b;
    a = b;
    b = x;
  }

  return a;
}

struct Rat;
Rat reduce(Rat a);

struct Rat
{
  Rat() {}
  Rat(int n) : num(n), denom(1) {}
  Rat(int n, int d) : num(n), denom(d)
  {
    if(d < 0)
    {
      n = -n;
      d = -d;
    }
  }

  Rat operator + (Rat rhs)
  {
    return reduce(Rat(num * rhs.denom + denom * rhs.num, denom * rhs.denom));
  }

  Rat operator - (Rat rhs)
  {
    return reduce(Rat(num * rhs.denom - denom * rhs.num, denom * rhs.denom));
  }

  Rat operator * (Rat rhs)
  {
    return reduce(Rat(num * rhs.num, denom * rhs.denom));
  }

  Rat operator / (Rat rhs)
  {
    return reduce(Rat(num * rhs.denom, denom * rhs.num));
  }

  Rat operator += (Rat rhs)
  {
    *this = *this + rhs;
    return *this;
  }

  Rat operator -= (Rat rhs)
  {
    *this = *this - rhs;
    return *this;
  }

  Rat operator *= (Rat rhs)
  {
    *this = *this * rhs;
    return *this;
  }

  Rat operator /= (Rat rhs)
  {
    *this = *this / rhs;
    return *this;
  }

  bool operator == (Rat rhs)
  {
    return num * rhs.denom == denom * rhs.num;
  }

  bool operator != (Rat rhs)
  {
    return !(*this == rhs);
  }

  bool operator < (Rat rhs)
  {
    return num * rhs.denom < denom * rhs.num;
  }

  bool operator > (Rat rhs)
  {
    return num * rhs.denom > denom * rhs.num;
  }

  bool operator <= (Rat rhs)
  {
    return !(*this > rhs);
  }

  bool operator >= (Rat rhs)
  {
    return !(*this < rhs);
  }

  int num, denom;
};

Rat reduce(Rat a)
{
  int g = GCD(a.num, a.denom);
  return Rat(a.num / g, a.denom / g);
}

Rat abs(Rat a)
{
  return Rat(abs(a.num), abs(a.denom));
}

int H, W, D, Dsqr;
int grid[32][32];
int youR, youC;
Rat youX, youY;

bool trace(int dx, int dy)
{
  if(dx == 0 || dy == 0)
  {
    if(dx == 0 && dy == 0)
      return false;

    int r = youR, c = youC;
    int dr = (dy > 0) ? 1 : ((dy < 0) ? -1 : 0);
    int dc = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0);
    int dist = 1;
    while(dist <= D)
    {
      r += dr;
      c += dc;
      if(grid[r][c])
        return true;
      dist += 2;
    }

    return false;
  }
  else
  {
    Rat x = youX, y = youY;
    Rat distX = 0, distY = 0;

    while(1)
    {
#ifdef DEBUG
      printf("  x=%d/%d (%f)   y=%d/%d (%f)   dx=%d dy=%d\n", x.num, x.denom, (double)x.num / x.denom, y.num, y.denom, (double)y.num / y.denom, dx, dy);
#endif
      
      Rat nextX1, nextY1, alpha1;
      Rat nextX2, nextY2, alpha2;
      if(dx > 0)
        nextX1 = (x.num + x.denom) / x.denom;
      else
        nextX1 = (x.num - 1) / x.denom;
      alpha1 = (nextX1 - x) / dx;
      nextY1 = y + alpha1 * dy;

      if(dy > 0)
        nextY2 = (y.num + y.denom) / y.denom;
      else
        nextY2 = (y.num - 1) / y.denom;
      alpha2 = (nextY2 - y) / dy;
      nextX2 = x + alpha2 * dx;

      Rat nextX, nextY, alpha;
      if(alpha1 < alpha2)
      {
        nextX = nextX1;
        nextY = nextY1;
        alpha = alpha1;
      }
      else
      {
        nextX = nextX2;
        nextY = nextY2;
        alpha = alpha2;
      }

      if((youX - x) * dy == (youY - y) * dx)
      {
        Rat youAlpha = (youX - x) / dx;
        if(youAlpha > 0 && youAlpha <= alpha)
        {
          Rat youDistX = distX + abs(youX - x);
          Rat youDistY = distY + abs(youY - y);
          return (youDistX * youDistX + youDistY * youDistY <= Dsqr);
        }
      }

      bool xEdge = (nextX.num % nextX.denom == 0);
      bool yEdge = (nextY.num % nextY.denom == 0);
      int ix = nextX.num / nextX.denom;
      int iy = nextY.num / nextY.denom;
      int nextDx = dx, nextDy = dy;

      bool cornerOf3 = false;
      if(xEdge && yEdge)
      {
        // corner
        int idx = 1, idy = 1;
        if(dx < 0)
        {
          ix--;
          idx = -1;
        }
        if(dy < 0)
        {
          iy--;
          idy = -1;
        }

        if(grid[iy][ix])
        {
          if(grid[iy-idy][ix])
          {
            if(grid[iy][ix-idx])
            {
              cornerOf3 = true;
            }
            else
            {
              nextDx = -dx;
            }
          }
          else if(grid[iy][ix-idx])
          {
            nextDy = -dy;
          }
          else
          {
            return false;
          }
        }
      }
      else if(xEdge)
      {
        if(dx < 0)
          ix--;
        if(grid[iy][ix])
          nextDx = -dx;
      }
      else
      {
        assert(yEdge);
        if(dy < 0)
          iy--;
        if(grid[iy][ix])
          nextDy = -dy;
      }

      distX += abs(nextX - x);
      distY += abs(nextY - y);

      Rat distSqr = distX * distX + distY * distY;
      if(cornerOf3)
        return (distSqr * 4 <= Dsqr);

      if(distSqr >= Dsqr)
        return false;

      x = nextX;
      y = nextY;
      dx = nextDx;
      dy = nextDy;
    }
  }
}

int search()
{
  int count = 0;
  int dx, dy;

  for(dx = -D; dx <= D; dx++)
  {
    for(dy = -D; dy <= D; dy++)
    {
      if(!(dx == 0 && dy == 0) &&
         dx * dx + dy * dy <= Dsqr &&
         abs(GCD(dx, dy)) == 1)
      {
        bool ok = trace(dx, dy);
#ifdef DEBUG
        printf("trace(%d, %d) ==> %d\n", dx, dy, ok);
#endif
        if(ok)
          count++;
      }
    }
  }

  return count;
}

int main(void)
{
  int T;
  scanf("%d", &T);

  int t;
  for(t = 0; t < T; t++)
  {
    scanf("%d %d %d", &H, &W, &D);
    Dsqr = D * D;

    memset(&grid[0][0], 0, sizeof(grid));
    int r = 0, c = 0;
    int ch;
    while((ch = getchar()) != EOF)
    {
      if(ch == '#' || ch == '.' || ch == 'X')
      {
        if(ch == '#')
          grid[r][c] = 1;
        else
          grid[r][c] = 0;
        if(ch == 'X')
        {
          youR = r;
          youC = c;
          youY = Rat(r) + Rat(1, 2);
          youX = Rat(c) + Rat(1, 2);
        }

        if(++c == W)
        {
          c = 0;
          if(++r == H)
            break;
        }
      }
    }

    int answer = search();
    printf("Case #%d: %d\n", t + 1, answer);
  }
  
  return 0;
}
