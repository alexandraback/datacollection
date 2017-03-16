#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>

using namespace std;

int J,P,S,K;

map<pair<int,int>,int> ijmap;
map<pair<int,int>,int> ikmap;
map<pair<int,int>,int> jkmap;


void add(map<pair<int,int>,int>& mymap,pair<int,int> p){
  if(mymap.find(p) == mymap.end())
    mymap[p] = 1;
  else
    ++mymap[p];
}

bool check(map<pair<int,int>,int>& mymap,int x,int y){
  auto p = make_pair(x,y);
  if(mymap.find(p) == mymap.end())
    return true;
  if(mymap[p] < K)
    return true;
  return false;
}

bool valid(int i,int j,int k){
//  if(i == 1&&j == 1 && k == 2){
//    printf("..%d %d %d\n",check(ijmap,i,j),check(ikmap,i,k),check(jkmap,j,k));
//    printf("ijmap %d %d\n",ijmap.find(make_pair(i,j)) == ijmap.end(),ijmap[make_pair(i,j)]);
//  }
  if(!check(ijmap,i,j))
    return false;
  if(!check(ikmap,i,k))
    return false;
  if(!check(jkmap,j,k))
    return false;
  return true;
}

void solve(){
  ijmap.clear();
  ikmap.clear();
  jkmap.clear();
  vector<pair<pair<int,int>,int>> ret;
  for(int i = 1;i <= J;++i)
    for(int j = 1;j <= P;++j)
      for(int k = 1;k <= S;++k){
  //      printf("%d %d %d: %d %d\n",i,j,k,ijmap.find(make_pair(i,j)) == ijmap.end(),ijmap[make_pair(1,1)]);
        if(valid(i,j,k)){
          ret.push_back(make_pair(make_pair(i,j),k));
          add(ijmap,make_pair(i,j));
          add(ikmap,make_pair(i,k));
          add(jkmap,make_pair(j,k));
        }
      }

  printf(" %d\n",ret.size());
  for(auto p : ret){
    printf("%d %d %d\n",p.first.first,p.first.second,p.second);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  for(int cas = 1;cas <= T;++cas){
    scanf("%d%d%d%d",&J,&P,&S,&K);
    printf("Case #%d:",cas);
    solve();
  }
  return 0;
}

