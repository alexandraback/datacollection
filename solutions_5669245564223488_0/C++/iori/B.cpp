#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vec;
typedef vector<vec> mat;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);
const int INF = 1e9;
const int mod = 1e9 + 7;
int N;

ll fact(ll n){
  if(n==0)return 1;
  return n * fact(n-1);
}

int array[26]={0};

bool all(string &s){
  int i;
  for(i=1;i<s.size();++i){
    if(s[0]!=s[i])break;
  }
  return i==s.size();
}

int main(){
  int T;
  cin >> T;
  for(int t=1;t<=T;++t){
    cin >> N;

    vector<string> v(N);
    for(int i=0;i<N;++i){
      cin >>v[i];
      string tmp;
      for(int j=0;j<v[i].size();){
	char k = v[i][j];
	tmp += v[i][j];
	while(j < v[i].size() && k==v[i][j] ){
	  j++;
	}
      }
      v[i] = tmp;
    }

    ll ans = 1;
    sort(v.begin(),v.end());
    set<string> S;
    string ss;


    int tmp;
    for(int i=0;i<N;++i){
      if(v.size()<1)continue;
      tmp=1;
      int j =i+1;
      if(all(v[i]))v[i] = v[i].substr(0,1);
      while(j < N && all(v[i]) && v[i][0]==v[j][0] && all(v[j])){
	array[v[i][0]-'A']=1;
	tmp++;
	//v[i]+=v[i];
	//v[i] = v[i].substr(0,1);
	v[j]="";
	j++;
      }
      ans *= fact(tmp);
      //cout << ans << endl;
    }

    sort(v.begin(),v.end());

    for(int k=0;k<4;++k){
    for(int i=0;i<N;++i){
      if(v[i].size()<1)continue;
      int k=v[i][v[i].size()-1];
      if(array[v[i][v.size()-1]-'A']){
	for(int j=0;j<N;++j){
	  if(i==j)continue;
	  if(v[i][v[i].size()-1]==v[j][0]&&all(v[j])){
	    v[j]="";
	  }
	}
      }
      for(int j=0;j<N;++j){
	if(i==j)continue;
	if(v[i][v[i].size()-1]==v[j][0]){
	  v[i]+=v[j];
	  v[j]="";
	}
      }
    }}
    int cnt=0;
    for(int i=0;i<N;++i){
      //cout << v[i] << " ";
      if(v[i].size())cnt++;
    }
    for(int i=1;i<N;++i){
      v[0]+=v[i];
    }

    string s = v[0];
    bool flag = false;
    for(int i=0;i<s.size();){
      char k=s[i];
      while(k==s[i] && i < s.size()){
	i++;
      }
      if(i>=s.size())break;
      for(int j=i;j<s.size();++j){
	if(s[j]==k){
	  flag = true;
	  break;
	}
      }
    }

    cout << "Case #" << t << ": ";
    if(flag)cout << 0 << endl;
    else cout << ans * fact(cnt) << endl;
    cout << endl << endl;
  }
  return 0;
}
