#include<iostream>
#include<map>

using namespace std;

int main(int agrc, char *argv[]){
  int T; cin>>T;
  for(int tc=1; tc<=T; tc++){
    int res = 0;
    int N; cin>>N;
    map<string, int> mf; int fid = 0;
    map<string, int> ms; int sid = 0;
    int first[1000];
    int second[1000];
    for(int i=0; i<N; i++){
      string s, t;
      cin >> s >> t;
      if(mf.find(s) == mf.end())
        mf[s] = fid++;
      if(ms.find(t) == ms.end())
        ms[t] = sid++;

      first[i] = (mf.find(s))->second;
      second[i]= (ms.find(t))->second;
    }
    ms.clear(); mf.clear();
    bool found[50];
    for(int i=0; i<(1<<N); i++){
      int cres = 0;
      for(int k=0; k<fid+sid; k++)
        found[k] = false;
      for(int k=0; k<N; k++)
        if((i&(1<<k))!=0){
          found[first[k]] = true;
          found[fid+second[k]] = true;
        }else{
          cres++;
        } 
      bool ok = true;
      for(int k=0; k<fid+sid; k++)
        ok &= found[k];
      if(ok && cres > res)
        res = cres;
    }
    cout<<"Case #"<< tc << ": " << res << endl;
  }
  return 0;
}
