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

int wall[1000];
int wall5[1000];

map<int, vector<int> > mp;
int main(){
  int t;
  si(t);
  int d[10]; int n[10]; int w[10]; int e[10]; int s[10]; int dd[10]; int dp[10]; int ds[10]; 
  f (cs, 1, t + 1){
    int res = 0;
    int N; si(N);
    fr (i, 1000){
      wall[i] = 0;
      wall5[i] = 0;
    }
    fr (i, N){
      si(d[i]); si(n[i]); si(w[i]); si(e[i]); si(s[i]); si(dd[i]); si(dp[i]); si(ds[i]);	      
      e[i] += 500; w[i] += 500;
    }

    map<int, vector<int> >::iterator it;

    fr (i, N){
      fr (j, n[i]){
	mp[d[i]].push_back(i);
	d[i] += dd[i];
      }
    }
    
    for (it = mp.begin(); it != mp.end(); it++){
      vector<int> nw = it->second;
      // cout << it->first << " " << nw.size() << endl;
      fr (i, nw.size()){

	int cur_tribe = nw[i];
	f (j, w[cur_tribe], e[cur_tribe] + 1){
	  if (wall[j] < s[cur_tribe] || (j != e[cur_tribe] && wall5[j] < s[cur_tribe])){
	    // cout << "succ " << it->first << " " << cur_tribe << endl;
	    res++;
	    break;
	  }
	}
      }
      
      fr (i, nw.size()){
	int cur_tribe = nw[i];
	/// cout << cur_tribe << " i" << endl;
	f (j, w[cur_tribe], e[cur_tribe] + 1){
	  if (wall[j] < s[cur_tribe]){
	    wall[j] = s[cur_tribe];
	  }
	  if (j != e[cur_tribe]){
	    if (wall5[j] < s[cur_tribe]){
	      wall5[j] = s[cur_tribe];
	    }
	  }
	}
	s[cur_tribe] += ds[cur_tribe];
	w[cur_tribe] += dp[cur_tribe];
	e[cur_tribe] += dp[cur_tribe];
      }
      // cout << "-------------\n";
    }
    mp.clear();
    printf("Case #%d: %d\n", cs, res);
  }

}
