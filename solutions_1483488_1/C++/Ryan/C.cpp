#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int N=2000001,none=0,P=8;
long long solve(int a,int b);
int digits(int n);
int get_next_number(int n);
int next[N],visited[N],pow10[P]={1};
int key=0;

int main(){
  for(int i=1;i<P;i++)
    pow10[i]=10*pow10[i-1];
  for(int i=1;i<N;i++)
    next[i]=get_next_number(i);
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int a,b;
    cin>>a>>b;
    cout<<"Case #"<<i+1<<": "<<solve(a,b)<<'\n';
  }
}

int visit(int n,int a,int b){
  if(visited[n]==key)
    return 0;
  visited[n]=key;
  return visit(next[n],a,b)+(a<=n && n<=b);
}

long long pairs(int n){
  return n*(n-1)/2;
}

long long solve(int a,int b){
  key++;
  long long ret=0;
  for(int i=a;i<=b;i++)
    ret+=pairs(visit(i,a,b));
  return ret;
}

int digits(int n){
  int ret=0;
  while(n){
    ret++;
    n/=10;
  }
  return ret;
}

int digit(int n,int i,int d){
  const int p=pow10[d-i-1];
  return n/p%10;
}

int next_number(int n){
  int d=digits(n);
  if(d==1)
    return n;
  for(int i=1;i<d;i++)
    if(digit(n,i,d)!=0){
      const int p=pow10[d-i],other_p=pow10[i];
      int top=n/p,bottom=n%p;
      return bottom*other_p+top;
    }
  return n;
}

int get_next_number(int n){
  while(true){
    int next=next_number(n);
    if(next<N)
      return next;
    n=next;
  }
}
