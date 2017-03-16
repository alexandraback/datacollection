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

typedef vector<int> VI;
typedef vector<ll>  VL;
typedef vector<string> VS;

#define MAX 1010

int n;
vector<pair<int,int> > a;
int status[MAX];


void input(){
      cin >> n;
      a.clear();
      For(i,0,n-1){
         int x, y;
         cin >> x >> y;
         a.push_back(mp(x,y));
      }
}

int main(){
   //freopen("input.txt", "rt", stdin);
	//freopen("B-small-attempt0.in", "rt", stdin); 
	freopen("B-large.in", "rt", stdin);     
   freopen ("output.txt","w",stdout);
	
	int sotest;   cin >> sotest;
	For(run, 1, sotest){   cout << "Case #" << run << ": ";
      input();
      
      Clear(status);
      int cnt = 0;
      int score = 0;
            
      while(true){
         
         bool found = false;
         For(i,0,n-1) if(a[i].second <= score){
            if(status[i]==0){            
               
               status[i] = 2;
               score += 2;
               ++cnt;
               
               found = true;
               break;
            }
            if(status[i]==1){
               status[i]=2;
               score += 1;
               ++cnt;
               
               found = true;
               break;
            }
         }
         
         if(found)   continue;
         
         int idx=-1;
         For(i,0,n-1) if(a[i].first <= score && status[i]==0){
            if(idx==-1) idx=i;
            else if(a[i].second > a[idx].second){
               idx=i;
            }
         }         
         if(idx!=-1){
            ++cnt;
            status[idx]=1;
            score+=1; 
         }
         else{
            break;
         }        
      }
      
      if(score == 2*n)  cout << cnt << endl;
      else              cout << "Too Bad" << endl;
   }
	
	return 0;
}
