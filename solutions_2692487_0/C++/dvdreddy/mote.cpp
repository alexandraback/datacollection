// written by lonerdude(dvdreddy)
// all rights reserved
//the template by dvdreddy
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int main(){
  int t; si(t); int caset = 1;
  while (t--){
    int a, n;
    si(a); si(n);
    int b[n];
    fr (i, n){
      si(b[i]);
    }
    
    sort(b, b + n);
    
    int cur_size = a;
    int no_op = 0;
    int mini_no_op = n + 1;
    bool fx = false;
    fr (i, n){
      if (b[i] < cur_size){
	mini_no_op = min(mini_no_op, no_op + n - 1 - i);
	cur_size += b[i];
      } else if (b[i] < cur_size + cur_size - 1){
	mini_no_op = min(mini_no_op, no_op + n - i);
	no_op ++; 
	cur_size += (cur_size -1); cur_size += b[i];
      } else {
	mini_no_op = min(mini_no_op, no_op + n - i);
	if (cur_size == 1) {
	  break;
	}
	while (cur_size <= b[i] && cur_size != 1){
	  no_op++;
	  cur_size += (cur_size - 1);
	}
	cur_size += b[i];
      }
    }
    printf("Case #%d: %d\n", caset, mini_no_op);
    caset++;
  }
  return 0;
}
