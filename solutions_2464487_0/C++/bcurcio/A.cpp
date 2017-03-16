#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

const double pi=acos(-1);
const double eps=1e-7;

void solve(int caso){
  int R =in();
  double T = in() * pi;
  int step = 0;
  int rad=R+1;
  while(T+eps>pi*rad*rad-pi*(rad-1)*(rad-1)){
    T-=(pi*rad*rad-pi*(rad-1)*(rad-1));
    rad+=2;
  //cerr << T << ' ' << pi*rad*rad-pi*(rad-1)*(rad-1) << endl;
    step++;
  }
  printf("Case #%d: %d\n",caso+1,step);
}

int main(){
  for(int i=0,T=in();i<T;i++)
      solve(i);
}
