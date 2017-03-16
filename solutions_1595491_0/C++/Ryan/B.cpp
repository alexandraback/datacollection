#include <iostream>
#include <cassert>

using namespace std;

int solve();

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    cout<<"Case #"<<i+1<<": "<<solve()<<'\n';
  }
}

/*
        b r d   r l h
0 0 0 | 0 0 0 | 0 0 1
0 0 1 | 0 1 1 | 1 1 1
0 1 1 | 0 2 1 | 2 1 2
0 0 2 | 0 2 2 |
0 1 2 | 1 0 1 |
0 2 2 | 1 1 1 |
*/

const int N=3;
const int dlow[N]={0,1,1};
const int dhigh[N]={1,1,2};

int solve(){
  int n,surprises,goal,known=0,possible=0;
  cin>>n>>surprises>>goal;
  for(int i=0;i<n;i++){
    int points;
    cin>>points;
    const int base=points/N,remainder=points%N;
    int low=base+dlow[remainder],high=base+dhigh[remainder];
    if(points==0)
      high=0;
    if(points==1)
      high=1;
    if(low>=goal)
      known++;
    else if(high>=goal)
      possible++;
  }
  return known+min(possible,surprises);
}
