#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#define rep(i,n) for(int i=0;i<n;i++)
#define rp(i,n)  for(i=0;i<n;i++)
#define pr(i)    cout<<i<<endl
#define mp(a,b)  make_pair(a,b)
#define bl       cout<<endl;
#define ll       long long 
#define vi       vector<int>
#define vs       vector<string>
#define fst      first 
#define snd      second
#define pb       push_back

using namespace std;

int tt;
int n,nn;
double res[300],sbsum,a[300],sum;
int sbn;

int main(){

  cin>>tt;
  rep(ii,tt){
    cout<<"Case #"<<ii+1<<": ";
    cin>>n;nn=n;
    fill(res,res+250,-1);
    sum=0;rep(i,n){cin>>a[i];sum+=a[i];}sbsum=sum;

    rep(i,n){
      if(res[i]!=0.0&&a[i]>=sum*2.0/n){
	res[i]=0.0;
	nn--;
	sbsum-=a[i];
      }
    }

    rep(i,n){
      if(res[i]==0.0)continue;
      else{ 
	res[i]=((sum+sbsum)/nn-a[i])*100.0/sum;
      }
    }
    
    rep(i,n)printf("%.6f ",res[i]);cout<<endl;
  }

}




