#include<iostream>
#include <map>
#include <vector>
#include <stack>
#include <cassert>
#include <climits>
#include <cstdio>
#include <set>
#include <queue>
using namespace std;
#define lint unsigned long long int


int getId(string& s, map<string,int>& mp){
  if(mp.find(s)==mp.end()){
    int id = mp.size();
    mp[s]= id;
    return id;
  }
  return mp[s];
}

int recur(vector<pair<string,string>>& lista, int pos, set<string> output, int count, int T){
  if(pos==lista.size()){
    if(output.size()==T){
      return count;
    }else{
      return lista.size()+1;
    }
  }
  int s = recur(lista,pos+1,output,count,T);
  output.insert(lista[pos].first);
  output.insert(lista[pos].second);
  int s2 = recur(lista,pos+1,output,count+1,T);
  return min(s,s2);
}


int solve(vector<pair<string,string>> lista){
  set<string> target;
  for(auto& p:lista){
    target.insert(p.first);
    target.insert(p.second);
  }
  set<string> s;
  return lista.size() - recur(lista,0,s,0,target.size());
}

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int el;
    cin >> el;
    vector<pair<string,string>> list(el);
    for(int i=0;i<el;i++){
      cin>>list[i].first>>list[i].second;
      list[i].first+="0";
      list[i].second+="1";
    }
    cout<<"Case #"<<i+1<<": "<<solve(list)<<endl;
  }

  return 0;
}
