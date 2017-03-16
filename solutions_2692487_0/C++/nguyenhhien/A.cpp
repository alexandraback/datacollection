#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF (1<<29)
#define eps 1e-9

#define ll long long
#define ld long double
#define ull unsigned long long

#define mp make_pair
#define pb push_back

#define Clear(t) memset((t), 0, sizeof(t))
#define Clear2(t, v) memset((t), (v), sizeof(t))

#define For(i,a,b) for(int i = (int)(a), _t = (int)(b); i <= _t; i++)
#define Ford(i,a,b) for(int i = (int)(a), _t = (int)(b); i >= _t; i--)

#define SZ(t) ( (int)((t).size()) )
#define All(v) (v).begin(), (v).end()
#define Sort(v) sort(All(v))
#define present(c,x) ((c).find(x) != (c).end())

#define MAX 1000

int A, N;
vector<int> s;

void input(){
   s.clear();
   
   cin >> A >> N;
   int tmp;
   For(i, 0, N-1){
      cin >> tmp; s.pb(tmp);
   }
   Sort(s);
}

void solve(){
   int res = MAX;
   
   int ans = 0;
   
   bool ok = true;
   For(i, 0, N-1){
      if(A > s[i])   A  += s[i];
      else{         
         //ignore s[i] & the rest;
         res = min(res, ans + N - i);
         
         //no chance to extend;
         if(A==1){ 
            ans = N;
            break;
         }
         
         //add s[i];
         while(A <= s[i]){
            A += (A-1);
            ++ans;
         }
         
         A += s[i];
      }
   }
    
   res = min(res, ans);
   
   cout << res << endl;
}

int main(){
   //freopen("input.txt", "rt", stdin);
	freopen("A-small-attempt2.in", "rt", stdin); 
	//freopen("A-large.in", "rt", stdin);     
   freopen ("output.txt","w",stdout);
	
	int sotest;   cin >> sotest;
	For(run, 1, sotest){   cout << "Case #" << run << ": ";
	  input();
	  
	  solve();
   }
	
	return 0;
}


