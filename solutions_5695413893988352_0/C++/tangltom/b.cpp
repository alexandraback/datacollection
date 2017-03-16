#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000;

int to_num(string s){
  int res = 0;
  for(char c:s){
    res = res*10 + c-'0';
  }
  return res;
}

string pat[2];
pair<string,string> best;
int bestdiff;
void f(int i, int idx=0, string cval="", string jval=""){
  if(i==pat[0].size()){
    if(idx==0){
      f(0,1,cval,jval);
    }
    else{
      int diff = abs(to_num(cval)-to_num(jval));
      if(diff < bestdiff || (diff==bestdiff && make_pair(cval,jval)<best)){
	bestdiff = diff;
	best = make_pair(cval,jval);
      }
    }
    return;
  }
  if(pat[idx][i]=='?')
    for(char c='0';c<='9';c++){
      if(idx==0)
	cval += c;
      else
	jval += c;
      f(i+1,idx,cval,jval);
      if(idx==0)
	cval.pop_back();
      else
	jval.pop_back();
      
    }
  else{
    if(idx==0)
      cval += pat[idx][i];
    else
      jval += pat[idx][i];
    f(i+1,idx,cval,jval);
  }
}

int main(){
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    
    cin>>pat[0]>>pat[1];
    bestdiff = inf;
    f(0);
    cout<<"Case #"<<t<<": "<<best.first<<' '<<best.second<<endl;
  }
  return 0;
}
