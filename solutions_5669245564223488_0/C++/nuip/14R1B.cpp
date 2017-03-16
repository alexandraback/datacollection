#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

bool inused[30];

int valid(string str){
  bool used[30];
  fill(used,used+30,0);
    char tmp='A';
  for(int i=0;i<str.size();i++){
    if(tmp==str[i])continue;
    tmp=str[i];
    if(used[tmp-'a'])return 0;
    used[tmp-'a']=1;
  }
  return 1;
}

int main(){
  int t,T;
  cin>>T;
  for(t=1;t<=T;t++){
    cout<<"Case #"<<t<<": ";
    fill(inused,inused+30,0);
    int N,f,i,j,k;
    ll re=0,MOD=1e9+7;
    cin>>N;
    vector<string> strs(N);
    for(i=0;i<N;i++){
      cin>>strs[i];
      for(j=1;j<strs[i].size();j++)
        while(strs[i][j-1]==strs[i][j]&&j<strs[i].size())
          strs[i].erase(j,1);
    //  cout<<strs[i]<<" ";
    }//cout<<endl;
    for(i=0;i<N;i++){
      f=0;
      for(j=0;j<strs[i].size();j++){
        if(inused[strs[i][j]-'a']){
          f=1;
          break;
        }else if(j!=0 && j!=strs[i].size()-1){
          inused[strs[i][j]-'a']=1;
        }
      }
      if(f)break;

      vector<int> per;
      for(i=0;i<N;i++)
        per.pb(i);
      do{
        string temp="";
        for(i=0;i<N;i++){
          temp+=strs[per[i]];
        }
        if(valid(temp))re=(re+1)%MOD;
      }while(next_permutation(per.begin(),per.end()));
    }
    if(f){
      cout<<0<<endl;
      continue;
    }else
      cout<<re<<endl;
  }
  return 0;
}