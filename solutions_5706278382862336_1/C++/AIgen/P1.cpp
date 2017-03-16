#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;

#define LL long long

LL gcd (LL a, LL b){
  if (b==0)return a;
  else return gcd (b, a%b);
}

int main (){
  int t;
  cin>>t;
  for (int te = 1; te <= t ; ++ te){
    LL p, q, q_;
    scanf ("%lld/%lld",&p,&q_);

    LL g = gcd (p,q_);

    p/=g;
    q_/=g;
    q = q_;
    LL tot = 1;
    while (q%2 != 1){
      q/=2;
      tot++;
      if (tot>40)break;
    }
    if (q!=1 || tot>40){
      cout<<"Case #"<<te<<": "<<"impossible"<<"\n";
    }
    else {
      tot = 0;
      while (p < q_){
	p = 2 * p;
	tot++;
      }
      cout<<"Case #"<<te<<": "<<tot<<"\n";
    }
  }
  return 0;
}
