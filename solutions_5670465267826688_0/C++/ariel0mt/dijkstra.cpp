/*
 * dijkstra.cpp
 *
 *  Created on: 11/4/2015
 *  Author: ariel
 */
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;

enum var{i,j,k,l};
struct quaternion{
  int signo;
  var q;
};
quaternion asigna(char c){
    quaternion tmp;
    tmp.signo = 1;
    switch(c){
      case 'i':tmp.q = i;break;
      case 'j':tmp.q = j;break;
      case 'k':tmp.q = k;break;
      default: break;
    }
    return tmp;
}

quaternion producto(quaternion A, quaternion B){
    quaternion res;
    res.signo = A.signo * B.signo;
    if(A.q==l&&B.q==l){res.signo*=1;res.q=l;}
    else if(A.q==l&&B.q==i){res.signo*=1;res.q=i;}
    else if(A.q==l&&B.q==j){res.signo*=1;res.q=j;}
    else if(A.q==l&&B.q==k){res.signo*=1;res.q=k;}
    else if(A.q==i&&B.q==l){res.signo*=1;res.q=i;}
    else if(A.q==i&&B.q==i){res.signo*=-1;res.q=l;}
    else if(A.q==i&&B.q==j){res.signo*=1;res.q=k;}
    else if(A.q==i&&B.q==k){res.signo*=-1;res.q=j;}
    else if(A.q==j&&B.q==l){res.signo*=1;res.q=j;}
    else if(A.q==j&&B.q==i){res.signo*=-1;res.q=k;}
    else if(A.q==j&&B.q==j){res.signo*=-1;res.q=l;}
    else if(A.q==j&&B.q==k){res.signo*=1;res.q=i;}
    else if(A.q==k&&B.q==l){res.signo*=1;res.q=k;}
    else if(A.q==k&&B.q==i){res.signo*=1;res.q=j;}
    else if(A.q==k&&B.q==j){res.signo*=-1;res.q=i;}
    else if(A.q==k&&B.q==k){res.signo*=-1;res.q=l;}
    return res;
}

bool leei(quaternion q){
  return (q.q==i&&q.signo==1)?true:false;
}

bool leej(quaternion q){
  return (q.q==j&&q.signo==1)?true:false;
}

bool leek(quaternion q){
  return(q.q==k&&q.signo==1)?true:false;
}

bool simplificak(int x,int lon,int z,string s){
    quaternion resu;
    resu.signo=1;
    resu.q=l;
    for(int i=z;i<lon;i++){
      resu=producto(resu,asigna(s.c_str()[i]));
    }
    x--;
    for(int i=x;i>0;i--){
        for(int j=0;j<lon;j++){
          resu=producto(resu,asigna(s.c_str()[j]));
        }
    }
    return leek(resu);
}

bool simplificajk(int x,int lon,int z,string s){
    quaternion resu;
    resu.signo=1;
    resu.q=l;
    for(int i=z; i<lon; i++){
        resu = producto(resu,asigna(s.c_str()[i]));
        if(leej(resu)){
            if(i==lon-1) return (simplificak(x-1,lon,(i+1)%lon,s))?true:false;
            else return (simplificak(x,lon,(i+1)%lon,s))?true:false;
        }
    }
    x--;
    for(int i=x; i>0; i--){
        for(int j=0; j<lon; j++){
            resu = producto(resu,asigna(s.c_str()[j]));
            if(leej(resu)){
              if(j==lon-1) return (simplificak(i-1,lon,(j+1)%lon,s))?true:false;
              else return(simplificak(i,lon,(j+1)%lon,s))?true:false;
            }
        }
    }
    return false;
}

bool simplifica(int x, int lon, string s){
    x=min(12+(x%4),x);
    quaternion resu;
    resu.signo=1;
    resu.q=l;
    for(int i=x; i>0; i--){
        for(int j=0; j<lon; j++){
            resu = producto(resu,asigna(s.c_str()[j]));
            if(leei(resu)){
                if(j==lon-1) return (simplificajk(i-1,lon,(j+1)%lon,s))?true:false;
                else return (simplificajk(i,lon,(j+1)%lon,s))?true:false;
            }
        }
    }
    return false;
}

void solve(int caso){
  int lon,x;
  string s;
  cin>>lon>>x>>s;
  bool posible=simplifica(x,lon,s);
  cout<<"Case #"<<caso<<": "<<((posible==true)?"YES":"NO")<<endl;

}

int main(){
  //clock_t start = clock();
  freopen("C-small-attempt0.in","r",stdin);
  freopen("C-small-ariel0.out","w",stdout);
  int casos;
  cin>>casos;
  for(int ic=1;ic<=casos;ic++){
    solve(ic);
  }
  //clock_t ends = clock();
  //cout<<"Tiempo:"<<(double)(ends-start)/CLOCKS_PER_SEC<<endl;
  return 0;
}
