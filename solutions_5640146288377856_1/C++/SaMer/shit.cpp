//============================================================================
// Name        : shit.cpp
// Author      : SaMer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
#define mp make_pair
typedef long long ll;
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
#endif
  int t;
  scanf("%d",&t);
  while(t--){
	  int r,c,w;
	  scanf("%d%d%d",&r,&c,&w);
	  int ans=(c/w)*r;
	  if(c%w==0) ans+=w-1;
	  else ans+=w;
	  static int cas=1;
	  printf("Case #%d: %d\n",cas++,ans);
  }


    return 0;
}
