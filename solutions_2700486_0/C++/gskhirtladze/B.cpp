//gskhirtladze

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

map <int,bool> fix[25000];
long long t,t1,X,Y;
double N;

double df(double left)
 {
  double convert,convert1,convert2;
  if (left == 0)
   {
    if (fix[X+12000][Y]) return 1; else return 0;
   }
  long long nowy=31,nowx=12000;
  while (true)
   {
    if (fix[12000][nowy] == 1) break;
    nowy--;
    if (nowy == -1) break;
   }
  if (nowy == -1)
   {
    fix[12000][0]=true;
    convert=df(left-1);
    fix[12000][0]=false;
    return convert;
   }
  nowy++;
  if (fix[nowx-1][nowy])
   {
    while (nowy>=0)
     {
      if (fix[nowx+1][nowy]) break;
      nowy--;
      nowx++;
     }
    fix[nowx][nowy+1]=true;
    convert=df(left-1);
    fix[nowx][nowy+1]=false;
    return convert;
   }
  if (fix[nowx+1][nowy])
   {
    while (nowy>=0)
     {
      if (fix[nowx-1][nowy]) break;
      nowy--;
      nowx--;
     }
    fix[nowx][nowy+1]=true;
    convert=df(left-1);
    fix[nowx][nowy+1]=false;
    return convert;
   }
  long long NOX=nowx;
  long long NOY=nowy;
  while (nowy>=0)
   {
    if (fix[nowx+1][nowy]) break;
    nowy--;
    nowx++;
   }
  fix[nowx][nowy+1]=true;
  convert1=df(left-1);
  fix[nowx][nowy+1]=false;
  nowx=NOX;
  nowy=NOY;
  while (nowy>=0)
   {
    if (fix[nowx-1][nowy]) break;
    nowy--;
    nowx--;
   }
  fix[nowx][nowy+1]=true;
  convert2=df(left-1);
  fix[nowx][nowy+1]=false;
  return (convert1+convert2)/2;
 }

void solve(double N)
 {
  for (int q=0;q<=24000;q++) fix[q].clear();

  printf("%.9f\n",df(N));
 }

main()
 {
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  
  cin>>t;
  for (t1=1;t1<=t;t1++)
   {
    cout<<"Case #"<<t1<<": ";
    cin>>N>>X>>Y;
    solve(N);
   }
  
 }
