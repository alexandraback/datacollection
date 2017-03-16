#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

typedef int ttyp;
#define fors(bg,en) for(int i=bg;i<en;i++)
#define forso(j,bg,en) for(int j=bg;j<en;j++)
#define forz(n) for(int i=0;i<n;i++)
#define forzo(j,n) for(int j=0;j<n;j++)
#define forsz(v) for(int i=0;i<v.size();i++)
#define forszo(j,v) for(int j=0;j<v.size();j++)
#define MP make_pair
#define sz(v) v.size()
#define GCDTYP long long //fill type here

GCDTYP gcd(GCDTYP a, GCDTYP b){
      if(b==0)return a;
        return gcd(b,a%b);
}

long long a, b;
long long strol(string s){
    long long ret;
    istringstream is(s);
    is>>ret;
    return ret;
}
void split(string s){
    int t = s.size();
    forz(t)
    if(s[i]=='/'){
        a = strol(s.substr(0,i));
        b = strol(s.substr(i+1));
    }
}

bool notok(long long a, long long b){
    a -= b;
    if(a==b) return false;
    if(a==0) return false;
    long long t = gcd(a,b);
    a /= t;
    b /= t;
    while((b%2 == 0) && b>a){
        b /= 2L;
    }
    if(b>a || (notok(a,b))){
        return true;
    }
    return false;
}

void doit(){
    int ret=0;
    string s;
    cin>>s;
    split(s);
    while((b%2 == 0) && b>a){
        b /= 2L;
        ret++;
    }
    if(b>a || (notok(a,b))){
        cout<<"impossible"<<endl;
        return;
    }
    cout<<ret<<endl;
  return;
}
int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
      cout<<"Case #"<<i<<": ";
      doit();
    }
    return 0;
}
