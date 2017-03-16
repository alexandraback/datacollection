#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1LL<<61;

ll to_num(string s, int repl){

  ll res = 0;
  for(char c:s){
    res = res*10;
    if(c=='?')
      res += repl;
    else
      res += c-'0';
  }
  return res;
}
string a,b;

ll dp_diff[20];
pair<int,int> action[20];

ll min_diff(int i){
  if(i==a.size())
    return 0;
  
  ll &res = dp_diff[i];
  if(res!=-1)
    return res;

  res = inf;
  if(a[i]=='?' && b[i]=='?'){
    // a=0 b=0
    res = min_diff(i+1);
    action[i] = {0,0};
    //a=0 b=1
    a[i]='0',b[i]='1';
    ll diff = abs(to_num(a.substr(i),9)-to_num(b.substr(i),0));
    if(diff < res){
      res = diff;
      action[i] = {0,1};
    }
    //a=1 b=0
    a[i]='1',b[i]='0';
    diff = abs(to_num(a.substr(i),0)-to_num(b.substr(i),9));
    if(diff < res){
      res = diff;
      action[i] = {1,0};
    }
    a[i]=b[i]='?';
  }
  else if(a[i]=='?' && b[i]!='?'){
    // a=x-1 b=x
    if(b[i]!='0'){
      a[i] = b[i]-1;
      ll diff = abs(to_num(a.substr(i),9)-to_num(b.substr(i),0));
      res = diff;
      action[i] = {a[i]-'0',b[i]-'0'};
    }
    //a=x b=x
    a[i] = b[i];
    ll diff = min_diff(i+1);
    if(diff < res){
      res = diff;
      action[i] = {a[i]-'0',b[i]-'0'};
    }
    //a=x+1 b=x
    if(b[i]!='9'){
      a[i]=b[i]+1;
      diff = abs(to_num(a.substr(i),0)-to_num(b.substr(i),9));
      if(diff < res){
	res = diff;
	action[i] = {a[i]-'0',b[i]-'0'};
      }
    }
    a[i]='?';
  }
  else if(a[i]!='?' && b[i]=='?'){
    // a=x b=x-1
    if(a[i]!='0'){
      b[i] = a[i]-1;
      ll diff = abs(to_num(a.substr(i),0)-to_num(b.substr(i),9));
      res = diff;
      action[i] = {a[i]-'0',b[i]-'0'};
    }
    //a=x b=x
    b[i]=a[i];
    ll diff = min_diff(i+1);
    if(diff < res){
      res = diff;
      action[i] = {a[i]-'0',b[i]-'0'};
    }
    //a=x b=x+1
    if(a[i]!='9'){
      b[i]=a[i]+1;
      diff = abs(to_num(a.substr(i),9)-to_num(b.substr(i),0));
      if(diff < res){
	res = diff;
	action[i] = {a[i]-'0',b[i]-'0'};
      }
    }
    b[i]='?';
  }
  else{
    action[i] = {a[i]-'0',b[i]-'0'};
    if(a[i]==b[i]){
      res = min_diff(i+1);
    }
    else if(a[i]<b[i]){
      res = abs(to_num(a.substr(i),9)-to_num(b.substr(i),0));
    }
    else{
      res = abs(to_num(a.substr(i),0)-to_num(b.substr(i),9));
    }
  }
  return res;
}

int main(){
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    cin>>a>>b;
    memset(dp_diff,-1,sizeof(dp_diff));
    min_diff(0);
    cout<<"Case #"<<t<<": ";
    string resa,resb;
    resa = a;
    resb = b;
    for(int i=0;i<a.size();i++){
      resa[i] = '0' + action[i].first;
      resb[i] = '0' + action[i].second;
      if(resa[i]<resb[i]){
	//	a ->9 b->0
	for(int j=i;j<a.size();j++){
	  if(resa[j]=='?')
	    resa[j]='9';
	  if(resb[j]=='?')
	    resb[j]='0';
	}
	break;
      }
      else if(resa[i]>resb[i]){
	// a-0 b-9
	for(int j=i;j<a.size();j++){
	  if(resa[j]=='?')
	    resa[j]='0';
	  if(resb[j]=='?')
	    resb[j]='9';
	}
	break;
      }
    }
    cout<<resa<<' '<<resb<<endl;
  }
  return 0;
}
