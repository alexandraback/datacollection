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


char owe[] = {'a', 'e', 'i', 'o', 'u'};

int main(){
  char nme[1000010];
  int arr[1000010];
  ll res = 0;
  int t, n, k;  
  scanf("%d\n", &t);
  // cout << t << endl;
  f (cs, 1, t + 1){
    res = 0;
    scanf("%s %d\n", &nme, &k);
    n = strlen(nme);
    // cout << nme << endl;
    // cout << nme << " " << k << " " << n << endl;
    fr (i, n){
      arr[i] = 0;
    }
    fr (i, n){
      fr (j, 5){
	if (nme[i] == owe[j]){
	  arr[i] = 1;
	}
      }
    }
    /*
    fr (i, n){
      cout << arr[i];
    }
    cout << endl;
    */
    int cur_start = 0;
    int cur_cnt = 0;
    int cur_sub_start = -1;
    fr (i, n){
      if (arr[i] == 0){
	cur_cnt++;
	if (cur_sub_start == -1){
	  cur_sub_start = i;
	}
      } else {
	cur_cnt = 0;
	cur_sub_start = -1;
      }

      if (cur_cnt == k){
	ll x1 = (cur_sub_start - cur_start + 1);
	ll x2 = (n - i);
	res += (x1 * x2);
	cur_start = cur_sub_start + 1;
	cur_sub_start++; cur_cnt--;
      }
    }
    
    if (cur_cnt == k){
      ll x1 = (ll)(cur_sub_start - cur_start + 1);
      ll x2 = (ll)(1);
      res += (x1 * x2);
    }      
    printf("Case #%d: %lld\n", cs, res);
  }

}
