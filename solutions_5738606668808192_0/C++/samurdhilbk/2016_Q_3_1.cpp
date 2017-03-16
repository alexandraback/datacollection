#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;

ll isPrime(ll p)
{
    if (p < 2) return false;
    for (ll i = 2; i * i <= p; i++)
        if (p % i == 0)
            return i;
    return -1;
}

int main()
{
  ll limit=(ll)(pow(2.0,16.0)-1.0);

  cout<<"Case #1:"<<endl;

  ll count=0;

  for(ll i=(ll)(pow(2.0,15.0)+1);i<=limit;i+=2){
    bool found=true;
    ui n=i;
    string s (16,'0');
    for(ui j=0;j<16;j++){
      if(n&(1<<j)) s[15-j]='1';
      else s[15-j]='0'; 
    }
    vector<ll> vec (11,0);
    for(ll j=2;j<=10;j++){
      ll u=stoll(s,nullptr,j);
      if(u%2==0){
        vec[j]=2;
      }
      else{
        ll ret=isPrime(u);
        if(ret!=-1) {
          vec[j]=ret;
        }
        else {
          found=false;
          break;
        }
      }
    }
    if(!found) continue;
    count++;
    cout<<s<<" ";
    for(int j=2;j<=10;j++) cout<<vec[j]<<" ";
    cout<<endl;
    if(count==50) break;
  } 

  return 0;
}