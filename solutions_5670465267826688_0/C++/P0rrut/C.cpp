#include<bits/stdc++.h>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;

long long L,X,T;
string s1,s2;
string pp[4][4] = {
  {"1","i","j","k"},
  {"i","-1","k","-j"},
  {"j","-k","-1","i"},
  {"k","j","-i","-1"}
};

int get(char val){
  if(val=='1') return 0;
  if(val=='i') return 1;
  if(val=='j') return 2;
  return 3;
}

string mult(string x1,char x2){
  int sign = 0;
  if(x1.size()>1) sign=1;
  string ret = "";
  int v2 = get(x2);
  int v1 = get(x1[sign]);
  ret = pp[v1][v2];
  if(sign && ret.size()>1){
    ret = ret.substr(1,1);
  }
  else if(sign){
    ret="-"+ret;
  }
  return ret;
}

int main(){
  cin >> T;
  FOR(t,T){
    printf("Case #%d: ",t+1);
    cin >> L >> X;
    cin >> s1;
    s2.clear();
    FOR(i,X) s2+=s1;
    string voy="ijk";
    string res = "1";
    int k =0;
   // cout << s2 << endl;
    FOR(i,s2.size()){
      //cout << res<<"*"<<s2[i]<<"=";
      res = mult(res,s2[i]);
     //cout << res <<"->" ;
      if(k<2 && res==voy.substr(k,1) ){
        k++;
        res="1";
        //cout << endl;
//        cout << i << endl;
      }
//      cout << res << " ";
    }
//    cout << endl;
//cout << endl <<k << " " << res << endl;
    if(res=="k" && k==2){
      cout <<"YES" << endl;
    }
    else
      cout <<"NO" << endl;
  }


  

  return 0;
}
