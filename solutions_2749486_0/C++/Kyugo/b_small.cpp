#include<iostream>
#include<map>
#include<set>
#include<queue>
using namespace std;

typedef pair<int,int>P;
typedef pair<int,P>PP;

struct T{
   PP pp;
   string res;
   T(PP _pp,string _res){
      pp = _pp; res = _res;
   }
   T(){};
};

string S = "SENW";
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

set<PP>st;
P G;

void bfs(){
   queue<T>que;
   que.push(T(PP(1,P(0,0)),""));
   while(que.size()){
      T t = que.front(); que.pop();
      int cost = t.pp.first;
      P p = t.pp.second;
      
      //cout << "cost = " << cost << " p.first = " << p.first << " p.second = " << p.second << endl;

      for(int i = 0 ; i < 4 ; i++){
	 P np = P(cost*dx[i] + p.first,
		  cost*dy[i] + p.second);

	 PP npp = PP(cost+1,np);
	 if(st.find(npp) != st.end())continue;
	 st.insert(npp);
	 que.push(T(npp,t.res + S[i]));
	 
	 if(np == G){
	    t.res += S[i];
	    cout << t.res << endl;
	    return;
	 }

      }
   }
}

void init(){
   st.clear();
}

void solve(){
   init();
   cin >> G.first >> G.second;
   bfs();
}

int main(){
   int tc;
   cin >> tc;
   int cnt = 1;
   while(tc--){
      cout << "Case #" << cnt++ << ": ";
      solve();
   }
   return 0;
}
