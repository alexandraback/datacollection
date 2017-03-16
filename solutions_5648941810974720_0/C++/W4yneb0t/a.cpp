#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
vector<string> nbs={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
VI cnt;
VI sol;

/*
NINE
 */
void adn(in a){
  forv(i,nbs[a])
    --cnt[nbs[a][i]];
  ++sol[a];
}
void docase(){
  string s;
  cnt=VI(300,0);
  cin>>s;
  forv(i,s)
    cnt[s[i]]++;
  sol=VI(10,0);
  while(cnt['Z']>0)
    adn(0);
  while(cnt['G']>0)
    adn(8);
  while(cnt['W']>0)
    adn(2);
  while(cnt['X']>0)
    adn(6);
  while(cnt['H']>0)
    adn(3);
  while(cnt['R']>0)
    adn(4);
  while(cnt['O']>0)
    adn(1);
  while(cnt['F']>0)
    adn(5);
  while(cnt['V']>0)
    adn(7);
  while(cnt['I']>0)
    adn(9);
  forv(i,cnt)
    assert(cnt[i]==0);
  forv(i,sol){
    forn(j,sol[i]){
      cout<<i;
    }
  }
  cout<<endl;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in T;
  cin>>T;
  for(in zz=1;zz<=T;zz++){
    cout<<"Case #"<<zz<<": ";
    docase();
  }
  return 0;
}
