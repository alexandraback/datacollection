/*GCJ R1C A*/
#include<iostream>
#include<string>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,begin=0;
string nam;

char mother[5]={'a','i','u','e','o'};
bool isMother(char c){
  for(int i=0;i<5;i++){
    if(c==mother[i])return true;
  }
  return false;
}
int table[1000001];
int add[1000001];
int rec(int end){
  if(table[end]!=-1)return table[end];
  if(end+1<n){
    table[end]=0;
  }else if(end-begin+1==n){
    int flg=0;
    for(int i=begin;i<=end;i++){
      if(isMother(nam[i]))flg=1;
    }
    if(flg==1){table[end]=0;}else{ table[end]=1;add[end]=1;}
  }else{
    int flg=0;
    for(int i=end;i>end-n;i--){
      if(isMother(nam[i]))flg=1;
    }
    int pre=rec(end-1);
    if(flg==1){
      int c=end;
      for(int i=end-1;i>=0;i--){
        if(!isMother(nam[i])){
          c=i;break;
        }
      }
      table[end]=pre+add[c];add[end]=add[end-1];
    }else{
      //   cout<<end<<endl;
      table[end]=pre+end+2-n;add[end]=end+2-n;
    }
  }
  return table[end];
}


void main2(){
  for(int i=0;i<1000000;i++){
    table[i]=-1;
    add[i]=0;
  }
  cin>>nam>>n;
  cout<<rec((int)nam.size()-1)<<endl;
  /*for(int i=0;i<(int)nam.size();i++){
    cout<<table[i]<<" ";
    }*/
  cout<<endl;
}
int main(){
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    printf("Case #%d: ",t);
    main2();
  }
}
