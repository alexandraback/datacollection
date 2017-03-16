#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;

int A,B;
typedef pair<int,int> pii;
set<pii> st;

void rec(string s,int pos,int sz,int mul){
  if(pos==sz){
    mul/=10;
    int num=atoi(s.c_str());
    if(!(num>=A&&num<=B))return;
    for(int i=1;i<sz;i++){
      if(s[i]=='0')continue;
      int nnum=0;
      for(int j=0;j<s.size();j++)nnum=(nnum*10)+(s[(i+j)%sz]-'0');
      if(nnum>=A&&nnum<=B){
	int a=num;
	int b=nnum;
	if(a==b)continue;
	if(b<a)swap(a,b);
	st.insert(pii(a,b));
      }
    }
  }
  else{
    for(char i='0';i<='9';i++){
      if(pos==0&&i=='0')continue;
      rec(s+i,pos+1,sz,mul*10);
    }
  }
}

int main(){

  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    st.clear();
    cin>>A>>B;
    int sz=0;
    int tmpB=B;
    while(tmpB){
      sz++;
      tmpB/=10;
    }
    for(int j=1;j<=sz;j++)rec("",0,j,1);
    cout<<"Case #"<<i+1<<": "<<st.size()<<endl;
  }

  return 0;
}
