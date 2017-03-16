#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
#define PB push_back
#define MP make_pair
#define sz(v) ((v).size())
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
typedef long long in;
typedef unsigned long long int llu;

void runtc();

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int ntc;
  cin>>ntc;
  for(int i=0;i<ntc;++i) {
    cout<<"Case #"<<(i+1)<<": ";
    runtc();
    cout<<endl;
  }
  
  return 0;
}

//=============================================================================
struct Hiker {
  Hiker(in start, in freq):start(start/360.),speed(1./freq){};
  double start;
  double speed;
  double at(double time) {
    return fmod(start + time * speed, 1);
  }
  double colltime(Hiker rhs, double time) {
    Hiker *slow;
    Hiker *fast;
    double dist, rsp;
    if(rhs.speed < speed) {
      slow = &rhs;
      fast = this;
    } else {
      slow = this;
      fast = &rhs;
    }
    dist = slow->at(time) - fast->at(time);
    if(dist<=0)dist+=1;
    rsp = fast->speed - slow->speed;
    if(rsp==0) {
      return 1e100;
    }
    return time + dist/rsp;
  }
};
void runtc() {
  in n, di, hi, mi;
  vector<Hiker> h;
  cin>>n;
  forn(i,n) {
    cin>>di>>hi>>mi;
    forn(j,hi) {
      h.PB(Hiker(di, mi+j));
    }
  }
  if(h.size()==1) {
    cout<<0;
    return;
  }
  Hiker zero(0, 1);
  zero.speed = 0;

  if(h.size()==2) {
    Hiker* first=&h[0];
    forv(i, h) {
      if(first->start > h[i].start || (first->start == h[i].start && first->speed > h[i].speed)) {
        first = &h[i];
      }
    }
    cerr<<"Follow hiker "<<first<<endl;

    double time = 0;
    Hiker* follow = first;
    while(true) {
      double finish = zero.colltime(*follow,time);
      double coll = 1e100;
      Hiker *other;
      forv(i,h) {
        if(follow == &h[i])
          continue;
        other = &h[i];
        coll = follow->colltime(*other, time);
      }
      if(finish < coll) {
        cout<<0;
        cerr<<"Finish at time "<<finish<<endl;
        return;
      } else {
        if(other->speed > follow->speed) {
          cout<<1;
          cerr<<"Rear-end collision at time "<<time<<endl;
          return;
        } else {
          time = coll;
          follow = other;
          cerr<<"Follow hiker "<<follow<<" at time "<<time<<endl;
        }
      }
    }
  }
}
