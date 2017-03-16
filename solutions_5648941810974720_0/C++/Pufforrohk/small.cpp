#include<iostream>
#include <map>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;
#define lint unsigned long long int

string arr[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

string ch[10]={"0","1","2","3","4","5","6","7","8","9"};


pair<bool,string> rec(string s,int id){
  if(id==10)
    return make_pair(s=="","");
  string cur = arr[id];
  string news = "";
  for(char c:s){
    auto it = cur.find_first_of(c);
    if(it==cur.npos){
      news.push_back(c);
    }else{
      cur.erase(cur.begin() + it);
    }
  }
  if(cur==""){
    auto ric = rec(news,id);
    if(ric.first){
      return make_pair(true, ch[id] + ric.second);
    }
  }  
  return rec(s,id+1);
}


string solve(string s){
  return rec(s,0).second;
}

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    string line;
    cin>>line;
    // Leggi
    cout<<"Case #"<<i+1<<": "<<solve(line)<<endl;
  }

  return 0;
}
