#include<iostream>
#include<vector>
#include<set>
using namespace std;

int R,N,M,K;
set<int>st;

bool check(vector<int>v){
   int cnt = 0;

   set<int>st2;

   if(st.find(1) != st.end())st2.insert(1);

   for(int i = 0 ; i < v.size() ; i++){
      if(st.find(v[i]) != st.end() && st2.find(v[i]) == st2.end())cnt++,st2.insert(v[i]);
      for(int j = i+1 ; j < v.size() ; j++){
	 if(st.find(v[i]*v[j]) != st.end() && st2.find(v[i]*v[j]) == st2.end())cnt++,st2.insert(v[i]*v[j]);
	 for(int k = j+1 ; k < v.size() ; k++){
	    if(st.find(v[i]*v[j]*v[k]) != st.end() && st2.find(v[i]*v[j]*v[k]) == st2.end())cnt++,st2.insert(v[i]*v[j]*v[k]);
	 }
      }
   }
   return st2.size() >= st.size();
}

bool dfs(int now,vector<int>v){
   if(now == N){
      if(check(v)){
	 for(int i = 0 ; i < N ; i++)cout << v[i];
	 cout << endl;
	 return true;
      }
      return false;
   }
   for(int i = 2 ; i <= M ; i++){
      vector<int>nv = v;
      nv.push_back(i);
      if(dfs(now+1,nv))return true;
   }
   return false;
}

void solve(){
   cin >> R >> N >> M >> K;
   for(int i = 0 ; i < R ; i++){
      st.clear();
      for(int j = 0 ; j < K ; j++){
	 int tmp; cin >> tmp; st.insert(tmp);
      }
      vector<int>v;
      if(!dfs(0,v)){
	 for(int i = 0 ; i < N ; i++)cout << 2;
	 cout << endl;
      }
   }
}

int main(){
   int tc;
   cin >> tc;
   for(int i = 1 ; i <= tc ; i++){
      cout << "Case #" << i << ": " << endl;
      solve();
   }
   return 0;
}
