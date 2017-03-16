#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;



int main(){
  int testcase;
  string b[4],ans;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    rep(i,4)cin >> b[i];

    ans = "Game has not completed";

    map<char,int> num;
    rep(i,4){
      num.clear();
      rep(j,4)num[b[i][j]]++;
      if(num['X'] == 4 || (num['X'] == 3 && num['T'] == 1)){
	ans = "X won";
      }
      if(num['O'] == 4 || (num['O'] == 3 && num['T'] == 1)){
	ans = "O won";
      }
      num.clear();
      rep(j,4)num[b[j][i]]++;
      if(num['X'] == 4 || (num['X'] == 3 && num['T'] == 1)){
	ans = "X won";
      }
      if(num['O'] == 4 || (num['O'] == 3 && num['T'] == 1)){
	ans = "O won";
      }
    }

    num.clear();
    rep(i,4)num[b[i][i]]++;
    if(num['X'] == 4 || (num['X'] == 3 && num['T'] == 1)){
      ans = "X won";
    }
    if(num['O'] == 4 || (num['O'] == 3 && num['T'] == 1)){
      ans = "O won";
    }

    num.clear();
    rep(i,4)num[b[i][3-i]]++;
    if(num['X'] == 4 || (num['X'] == 3 && num['T'] == 1)){
      ans = "X won";
    }
    if(num['O'] == 4 || (num['O'] == 3 && num['T'] == 1)){
	ans = "O won";
    }

    if(ans.size()!=5){
      rep(i,4)rep(j,4)num[b[i][j]]++;
      if(!num['.'])ans = "Draw";
    }
	
    cout << "Case #" << casenum << ": ";
    cout << ans << endl;
  }
}
