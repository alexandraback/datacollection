#include <iostream>
#include <cmath>
#include <set>

using namespace std;

typedef long long LL;
int H, W, D, X, Y;
char maze[100][100];
set<pair<int, int> > cache;


inline int ab(int x)
{ return x>= 0? x : -x;}

LL gcd(LL x, LL y)
{
  if (y > x)
    return gcd(y, x);
  else if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}

int solve()
{
  cache.clear();
  int x = X-1;
  int y = Y-1;
  int w = W-2;
  int h = H-2;
  int Ret = 0;
  // LR
  if (2*y + 1 <= D) ++Ret;
  if (2*(w-y) - 1 <= D) ++Ret;
  // UD
  if (2*x + 1 <= D) ++Ret;
  if (2*(h-x) - 1 <= D) ++Ret;

  int ret, newx, last;
  int newy, lasty, dist;
  // ABOVE (X decreasing)
  ret = 0;
  newx = x;
  last = 0;
  do
    {
      ret = 0;
      if (last == 0) newx = newx - 1 - 2*x;
      else newx = newx - 1 - 2*(h-x-1);
      last = 1-last;

      // LEFT (Y decreasing)
      newy = y;
      lasty = 0;
      while (true)
	{
	  if (lasty == 0) newy = newy - 1 - 2*y;
	  else newy = newy - 1 - 2*(w-y-1);
	  lasty = 1-lasty;
	  dist = (newx-x)*(newx-x) + (newy-y)*(newy-y);
	  if (dist > D*D) break;

	  int G = gcd(ab(newx-x), ab(newy-y));
	  pair<int, int> p = make_pair((newx-x)/G, (newy-y)/G);
	  if (cache.count(p) == 0)
	    {
	      cache.insert(p);
	      ++ret;
	      //	      cout << "OK ";
	    }
	  //	  cout << newx << " " << newy << endl;
	}
      //      cout << endl;
      // RIGHT (Y increasing)
      newy = y;
      lasty = 0;
      while (true)
	{
	  if (lasty == 0)       newy = newy + 1 + 2*(w-y-1);
	  else newy = newy + 1 + 2*y;
	  lasty = 1-lasty;
	  dist = (newx-x)*(newx-x) + (newy-y)*(newy-y);
	  if (dist > D*D) break;

	  int G = gcd(ab(newx-x), ab(newy-y));
	  pair<int, int> p = make_pair((newx-x)/G, (newy-y)/G);
	  if (cache.count(p) == 0)
	    {
	      cache.insert(p);
	      ++ret;
	      //	      cout << "OK ";
	    }
	  //	  cout << newx << " " << newy << endl;
	}
      Ret += ret;
    } while (ab(newx-x) < D);
  //      cout << endl;
  //      cout << endl;

  // BELOW (X increasing)
  ret = 0;
  newx = x;
  last = 0;
  do
    {
      ret = 0;
      if (last == 0) newx = newx + 1 + 2*(h-x-1);
      else newx = newx + 1 + 2*x;
      last = 1-last;

      // LEFT (Y decreasing)
      newy = y;
      lasty = 0;
      while (true)
	{
	  if (lasty == 0) newy = newy - 1 - 2*y;
	  else newy = newy - 1 - 2*(w-y-1);
	  lasty = 1-lasty;
	  dist = (newx-x)*(newx-x) + (newy-y)*(newy-y);
	  if (dist > D*D) break;

	  int G = gcd(ab(newx-x), ab(newy-y));
	  pair<int, int> p = make_pair((newx-x)/G, (newy-y)/G);
	  if (cache.count(p) == 0)
	    {
	      cache.insert(p);
	      ++ret;
	      //	      cout << "OK ";
	    }
	  //	  cout << newx << " " << newy << endl;
	}
      //      cout << endl;
      // RIGHT (Y increasing)
      newy = y;
      lasty = 0;
      while (true)
	{
	  if (lasty == 0)       newy = newy + 1 + 2*(w-y-1);
	  else newy = newy + 1 + 2*y;
	  lasty = 1-lasty;
	  dist = (newx-x)*(newx-x) + (newy-y)*(newy-y);
	  if (dist > D*D) break;

	  int G = gcd(ab(newx-x), ab(newy-y));
	  pair<int, int> p = make_pair((newx-x)/G, (newy-y)/G);
	  if (cache.count(p) == 0)
	    {
	      cache.insert(p);
	      ++ret;
	      //	      cout << "OK ";
	    }
	  //	  cout << newx << " " << newy << endl;
	}
      Ret += ret;
    } while (ab(newx-x) < D);
  return Ret;
}

int follow(int x, int y, int den)
{
  // cout << endl;
  // cout << "Follow" << " " << X << " " << Y <<" " << D <<" " << x<<" "<< y<< " "<< den<< endl;
  int denx = den * max(1, ab(y));
  int deny = den * max(1, ab(x));
  if (denx % 2 == 1 || deny % 2 == 1)
    {
      denx *= 2;
      deny *= 2;
    }
  int dx = x*denx/den, dy = y*deny/den;
  int G = gcd(ab(dx), ab(dy)); dx /= G; dy /= G;
  int px = int((X + 0.5) * denx) + dx, py = int((Y + 0.5) * deny) + dy;
  LL distn, distd;
  if (x == 0 || y == 0) {distn = 1; distd = 4;}
  else
    {
      int G = gcd(denx, deny);
      LL A = denx/G;
      LL B = deny/G;
      LL GG = G;
      distd = G*G*A*A*B*B;
      distn = A*A + B*B;
      GG = gcd(distn, distd);
      distd /= GG; distn /= GG;
    }
  // cout << dx << " " << dy  << " " << den << " " <<  denx << " " <<  deny << " " <<  distn <<"/" << distd<<endl; 
  int ndist = 1;
  while (true)
    {
      // cout << px << " " << py << "    " << dx << " " << dy << endl;
      if (ndist * ndist * distn > D * D * distd)
	//print " NIENTE :(!", ndist * dist
	return 0;
      
    
      if (px % denx == 0)
	{
	  if (py % deny == 0)
	    {
	      int nx = px / denx, ny = py / deny;
	      int uln = -1;
	      int lrn = -1;
	      if (dx < 0) //# =e= 0 non puo` essere
		{ nx -= 1; uln = +1;}
	      if (dy < 0)
		{ ny -= 1; lrn = +1;}
	      //print "   ", n
	      
	      if (maze[nx][ny] == '#')
		{
		  if (maze[nx+uln][ny] == '#')
		    {
		      if (maze[nx][ny+lrn] == '#')
			{
			  // cout << "B???" << ndist << endl;
			  if (ndist * ndist * distn * 4 <= D * D * distd) return 1;
			  else return 0;
			}
		      else 
		      { dy = -dy; px += dx; py += dy; ++ndist; }
		  }
		else
		  {
		    if (maze[nx][ny+lrn] == '#')
		      { dx = -dx; px += dx; py += dy; ++ndist; }
		    else return 0;
		  }
		}
	      else
		{ px += dx; py += dy; ++ndist; }
	    }
	  
	  else
	    {
	      int nx = px / denx, ny = py / deny;
	      if (dx < 0) nx -= 1;
	      
	      if (maze[nx][ny] == '#') dx = -dx;
	      px += dx; py += dy; ++ndist;
	    }
	}
      else
	{
	  if (py % deny == 0)
	    {
	      int nx = px / denx, ny = py / deny;
	      if (dy < 0) ny -= 1;
	      
	      if (maze[nx][ny] == '#') dy = -dy;
	      px += dx; py += dy; ++ndist;
	    }
	  else
	    {
	      // middle
	      //print
	      //	      cout << px << "    " << py << endl;
	      if ((px*2) % denx == 0 && (py*2) % deny == 0 &&
		  px / denx == X && py / deny == Y)
		{
		  // cout << "???" << ndist << endl;
		  if (ndist * ndist * distn <= D * D * distd) return 1;
		  else return 0;
		}
	      else
		{ px += dx; py += dy; ++ndist; }
	    }
	}
    }
}      

        
        


int find(int num, int den)
{
  int ret = 0;
  ret += follow(+den, num, den);
  ret += follow(num, +den, den);
  ret += follow(-den, num, den);
  ret += follow(num, -den, den);
  
  ret += follow(+den, -num, den);
  ret += follow(-num, +den, den);
  ret += follow(-den, -num, den);
  ret += follow(-num, -den, den);
  return ret;
}


int main(void)
{
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i)
    {
      cin >> H >> W>> D;
      string s;
      for (int j = 0; j < H; j++)
	{
	  cin >> s;
	  for (int k = 0; k < W; k++)
	    {
	      maze[j][k] = s[k];
	      if (s[k] == 'X')
		{ X = j; Y = k; }
	    }
	}

      // int Ret = 0;
      // Ret += follow(+1, 0, 2);
      // Ret += follow(0, +1, 2);
      // Ret += follow(-1, 0, 2);
      // Ret += follow(0, -1, 2);
      // Ret += follow(+1, +1, 2);
      // Ret += follow(+1, -1, 2);
      // Ret += follow(-1, +1, 2);
      // Ret += follow(-1, -1, 2);

      // int den = 2;
      // int lim = 4;
      // while (den <= lim)
      // 	{
      // 	  int ret = 0;
      // 	  for (int num = 0; num < den; ++num)
      // 	    if (gcd(num, den) == 1)
      // 	      ret += find(num, den);
      // 	  //	  cout << den << " " << ret << endl;
      // 	  if (ret > 0)
      //       lim = den * 2;
      // 	  den += 1;
      // 	  Ret += ret;
      //   }
      
      cout << "Case #" << (i+1) << ": " << solve() << endl;
    }
}    
        

