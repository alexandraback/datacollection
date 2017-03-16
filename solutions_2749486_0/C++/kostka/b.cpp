#include<cstdio>
#include<algorithm>

using namespace std;

int x, y, dx, dy, licz;

void foo1()
{
  dx = 0; dy = 0; licz = 0;
  for(int i=1; i<=210; i++)
  {
    if(i==abs(y))
    {
      if(y>0)
      {
 	printf("N");
	dy += i;
      }
      else
      {
 	printf("S");
	dy -= i;
      }
      continue;
    }
    else
    {
      licz++;
      if(licz%2)
      {
 	printf("W");
	dx -= i;
      }
      else
      {
 	printf("E");
	dx += i;
      }
      if(dx==x)
	return;
    }
  }
}

void foo2()
{
  dx = 0; dy = 0; licz = 0;
  for(int i=1; i<=210; i++)
  {
    if(i==abs(y))
    {
      if(y>0)
      {
 	printf("N");
	dy += i;
      }
      else
      {
 	printf("S");
	dy -= i;
      }
      continue;
    }
    else
    {
      licz++;
      if(licz%2)
      {
 	printf("E");
	dx += i;
      }
      else
      {
 	printf("W");
	dx -= i;
      }
      if(dx==x)
	return;
    }
  }
}

void foo3()
{
  dx = 0; dy = 0; licz = 0;
  for(int i=1; i<=210; i++)
  {
    if(i==abs(x))
    {
      if(x>0)
      {
 	printf("E");
	dx += i;
      }
      else
      {
 	printf("W");
	dx -= i;
      }
      continue;
    }
    else
    {
      licz++;
      if(licz%2)
      {
	printf("S");
	dy -= i;
      }
      else
      {
 	printf("N");
	dy += i;
      }
      if(dy==y)
	return;
    }
  }
}

void foo4()
{
  dx = 0; dy = 0; licz = 0;
  for(int i=1; i<=210; i++)
  {
    if(i==abs(x))
    {
      if(x>0)
      {
 	printf("E");
	dx += i;
      }
      else
      {
	printf("W");
	dx -= i;
      }
      continue;
    }
    else
    {
      licz++;
      if(licz%2)
      {
 	printf("N");
	dy += i;
      }
      else
      {
 	printf("S");
	dy -= i;
      }
      if(dy==y)
	return;
    }
  }
}

void solve()
{
  scanf("%d%d", &x, &y);
  if(abs(x)==1 && abs(y)==1)
  {
    if(x==-1 && y==-1)
      printf("SEW");
    else if(x==-1 && y==1)
      printf("NEW");
    else if(x==1 && y==-1)
      printf("SWE");
    else if(x==1 && y==1)
      printf("NWE");
    printf("\n");
    return;
  }
  if(abs(x)>abs(y))
  {
    if(x>0)
      foo1();
    else
      foo2();
  }
  else
  {
    if(y>0)
      foo3();
    else
      foo4();
  }
  printf("\n");
  //printf("%d %d\n", dx, dy);
}

int main()
{
  int t;
  scanf("%d", &t);
  for(int ti = 1; ti <= t; ti++)
  {
    printf("Case #%d: ", ti);
    solve(); 
  }
  return 0;
}