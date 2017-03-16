#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
#include <stack>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

const string mat[4][4] =
{
  { "1", "i", "j", "k" },
  { "i", "-1", "k", "-j" },
  { "j", "-k", "-1", "i" },
  { "k", "j", "-i", "-1" }
};

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout); 
  int tt;
  cin >> tt;
  for(int pp=0; pp<tt; ++pp){
    int L; int X;
    cin >> L >> X;
    string w[L*X];
    for(int qq=0;qq<L;++qq){
      char in; cin >> in;
      w[qq] = in;
      for(int k=qq+L;k<L*X;k+=L) {
	w[k] = w[qq];
      }
    }
    int res=0;
    int i=0;
    if(L>1){
      while(i<L*X && res!=3){
	int row, col;
	if(w[i]=="i" && res==0) ++res;
	else if(w[i]=="j" && res==1) ++res;
	else if(w[i]=="k" && res==2 && i==(L*X)-1) ++res;
	
	else if(i+1<L*X){
	  bool n=false;
	  if(w[i]=="1" || w[i]=="-1") row=0;
	  else if(w[i]=="i" || w[i]=="-i") row=1;
	  else if(w[i]=="j" || w[i]=="-j") row=2;
	  else if(w[i]=="k" || w[i]=="-k") row=3;
	  if(w[i].size()>1) n=true;
	  
	  if(w[i+1]=="1") col=0;
	  else if(w[i+1]=="i") col=1;
	  else if(w[i+1]=="j") col=2;
	  else if(w[i+1]=="k") col=3;
	  
	  string elem = mat[row][col];
	  if(n){
	    if(elem.size()>1) elem = elem[1];
	    else elem = "-" + elem;
	  }
	  w[i+1]=elem;
	}
	++i;
      }
    }
    if(res==3 && i==L*X) cout << "Case #" << pp+1 << ": " << "YES" << endl;
    else cout << "Case #" << pp+1 << ": " << "NO" << endl;
  }
}