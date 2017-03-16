#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<iostream>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
int T,N;
string S;
char ar[]="aiueo";
bool check(char a){
  for(int i=0;i<5;i++){
    if(a==ar[i]) return false;
  }
  return true;
}

int main(){
  cin >> T;
  for(int loop=1;loop<=T;loop++){
    ll res=0;
    cin >> S >> N;
    int co = 0;
    int ind = 0;
    ll sn = (ll)S.size();
    for(int i=0;i<(int)S.size();i++){
      if( check(S[i]) ){
	co++;
	if(co>=N){
	  res += (ll)((i-N+2)-ind)*(sn-(ll)i);
	  ind=i-N+2;
	} 
      } else {
	co=0;
      }
    }

    cout << "Case #" << loop << ": "<< res<<endl;
  }
}
