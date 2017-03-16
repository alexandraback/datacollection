#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

static const char decode[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

void main2(){
  int i;
  string str;

  scanf("\n");
  getline(cin,str);
  rep(i,str.size()){
    if(str[i] == ' ') cout << ' ';
    else cout << decode[str[i] - 'a'];
  }
  cout << endl;
}

int main(){
  int T,t;
  scanf("%d",&T);
  rep(t,T){
    printf("Case #%d: ",t+1);
    main2();
  }
  return 0;
}
