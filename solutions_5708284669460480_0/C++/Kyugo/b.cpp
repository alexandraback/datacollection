#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
// #define DEBUG

using namespace std;

// typedef pair<int,int>P;
// typedef complex<double>P;

typedef long long int ll;
typedef unsigned long long int ull;

const int INF = 1e9;
const double EPS=1e-9;

int K,L,S;

int count_point(string str,const string& str_k,const string& str_l){
  int ret = 0;
  for(int i = 0 ; i+L <= S ; i++){
    bool f = true;
    for(int j = 0 ; j < L ; j++){
      if(str_l[j] != str[i+j])f = false;
    }
    if(f)ret += 1.0;
  }
  return ret;
}

double rec(int now,string str,const string& str_k,const string& str_l,int& maxi){
  double ret = 0.0;
  if(now == S){
    int tmp = count_point(str,str_k,str_l);
    maxi = max(maxi,tmp);
    return tmp;
  }
  for(int i = 0 ; i < K ; i++){
    ret += rec(now+1,str+str_k[i],str_k,str_l,maxi)/K;
  }
  return ret;
}

double solve_small(){
  cin >> K >> L >> S;
  string str_k,str_l;
  cin >> str_k >> str_l;
  int maxi = 0;
  double val = rec(0,"",str_k,str_l,maxi);
  return maxi - val;
}

int main(int argc, char *argv[])
{
  int T;
  cin >> T;
  for(int i = 1 ; i <= T ; i++){
    cout << "Case #" << i << ": ";
    printf("%lf\n",solve_small());
  }
  return 0;
}
