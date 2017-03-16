#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007

/*
*
* Zaiiiiiin
*
*/

using namespace std;

typedef pair<int,int> ii;

int T, c, j;
string C, J;
vector<int> a, b;

void solveC(int n = 0, int i = 0){
  if(i == C.size()){
    a.push_back(n);
    return;
  }
  n *= 10;
  if(C[i] != '?') solveC(n + (C[i] - '0'), i+1);
  else for(int j=0; j<10; j++) solveC(n + j, i+1);
}

void solveJ(int n = 0, int i = 0){
  if(i == J.size()){
    b.push_back(n);
    return;
  }
  n *= 10;
  if(J[i] != '?') solveJ(n + (J[i] - '0'), i+1);
  else for(int j=0; j<10; j++) solveJ(n + j, i+1);
}


int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &T);
  for(int t=1; t<=T; t++){
    cin >> C;
    cin >> J;
    int mn = 1000;
    solveC();
    solveJ();
    for(int i: a){
      int p = upper_bound(b.begin(), b.end(), i) - b.begin();
      if(p != 0 && mn > abs(i - b[p-1])){
        mn = abs(i - b[p-1]);
        c = i;
        j = b[p-1];
      }
      if(p != b.size() && mn > abs(i - b[p])){
        mn = abs(i - b[p]);
        c = i;
        j = b[p];
      }
    }
    a.clear();
    b.clear();
    string cc = "", jj = "";
    while(c){
      cc.push_back((c%10) + '0');
      c /= 10;
    }
    while(j){
      jj.push_back((j%10) + '0');
      j /= 10;
    }
    while(cc.size() < C.size()) cc.push_back('0');
    while(jj.size() < J.size()) jj.push_back('0');
    reverse(cc.begin(), cc.end());
    reverse(jj.begin(), jj.end());
    cout << "Case #" << t << ": ";
    cout << cc << " " << jj <<  "\n";
  }
  return 0;
}
