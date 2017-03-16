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
  int t;
  si(t);

  f (cs, 1, t + 1){
    string res = "";
    int x, y; si(x); si(y);
    string r1 = "";
    if (x < 0){
      res += 'W'; x++;
      while (x != 0){
	res += "EW"; x++;
      }
    } else if (x > 0) {
      res += 'E'; x--;
      while (x != 0){
	res += "WE"; x--;
      }
    }
    
    x = y;

    if (x < 0){
      while (x != 0){
	res += "NS"; x++;
      }
    } else if (x > 0) {
      while (x != 0){
	res += "SN"; x--;
      }
    }

    printf("Case #%d: ", cs);
    cout << res << endl;
  }

}
