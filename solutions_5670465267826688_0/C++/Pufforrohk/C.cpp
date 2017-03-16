#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
using namespace std;

int L,X;
vector<int> converted;

map<tuple<int,int,int>, bool> sav;

int conv(char c){
  if(c=='1')
    return 1;
  else
    return 2+(c-'i');
}

int mult(int a, int b){
  int mult = 1;
  if(a<0){
    a=-a;
    mult=-mult;
  }
  if(b<0){
    b=-b;
    mult=-mult;
  }
  int sol;
  if(a==1){
    sol=b;
  } else if(a==2){
    switch(b){
    case 1: sol=2;break;
    case 2: sol=-1;break;
    case 3: sol=4;break;
    case 4: sol=-3;break;
    }
  } else if(a==3){
    switch(b){
    case 1: sol=3;break;
    case 2: sol=-4;break;
    case 3: sol=-1;break;
    case 4: sol=2;break;
    }
  } else if(a==4){
    switch(b){
    case 1: sol=4;break;
    case 2: sol=3;break;
    case 3: sol=-2;break;
    case 4: sol=-1;break;
    }
  } else{
    assert(false);
  }  
  return mult*sol;
}

bool solvable(int pos, int cur, int target){
  if(pos==converted.size())
    return target==5;
  if(target==5)
    return false;
  auto tup = make_tuple(pos,cur,target);
  if(sav.find(tup) == sav.end()){
      cur = mult(cur,converted[pos]);
      if(cur==target && solvable(pos+1,1,target+1))
	sav[tup]=true;
      else
	sav[tup]=solvable(pos+1,cur,target);
  }
  return sav[tup];
}

string solve(){
  cin>>L>>X;
  string pattern;
  cin>>pattern;
  assert(pattern.size()==L);
  converted.clear();
  sav.clear();
  for(int j=0;j<X;j++)
    for(int i=0;i<L;i++){
      converted.push_back(conv(pattern[i]));
    }
  if(solvable(0,1,2))
    return "YES";
  else
    return "NO";
}

int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    cout<<"Case #"<<i+1<<": "<<solve()<<endl;
  }
  return 0;
}
