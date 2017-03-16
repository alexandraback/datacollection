#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <fstream>


using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                        
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int main(int argc, char *argv[]){
int t,n,m,id=1;
ifstream in(argv[1],ios::in);
ofstream op("output.txt",ios::out);
in>>t;
int flag=0;
int b[1002];
int a[1002][12];
while(t>0){
  in>>n;
for(int i=1;i<=n;i++){
  in>>m;
  for(int j=1;j<=m&&m!=0;j++){
    in>>a[i][j];
  }
  a[i][0]=m;
}

flag=0;
priority_queue<int> q;
for(int i=1;i<=n;i++){
for(int r=0;r<=n;r++)
   b[r]=0;  
q.push(i);
while(!q.empty()){
  int l=q.top();
  q.pop();
  for(int k=1;k<=a[l][0];k++){
    if(b[a[l][k]]==1){
      flag=1;
//      cout<<a[l][k]<<endl;
//      cout<<i;
      
      break;
    }
    else{
      b[a[l][k]]=1;
    }
    q.push(a[l][k]);
  }
  if(flag==1)
     break;
}
}
if(flag==1)
  op<<"Case #"<<id<<": Yes\n";
else
  op<<"Case #"<<id<<": No\n";
id++;
t--;
}
in.close();
op.close();
return 0;
}