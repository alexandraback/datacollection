#include <iostream>
#include <vector>
using namespace std;

bool unlock(vector<int> &key, vector<int> chest, vector<vector<int> > chest_key, vector<bool> &opened, vector<int> &seq){
  if (seq.size()==chest.size()) return true;
  if (key.empty()) return false;
  int ch[250];
  int i,j,k;
  bool tmp=false;
  for (i=0; i<250; i++) ch[i]=0;
  for (i=0; i<key.size(); i++) ch[key[i]]++;
  for (i=0; i<chest.size(); i++)
    if (!opened[i]){
      //ch[chest[i]]--;
      for (j=0; j<chest_key[i].size(); j++)
        ch[chest_key[i][j]]++;
    }
  for (i=0; i<chest.size(); i++)
    if (!opened[i]){
      int tmp=0;
      for (j=0; j<chest_key[i].size(); j++)
        if (chest_key[i][j]==chest[i]) tmp++;
      if (ch[chest[i]]-tmp<=0) return false;
    }
  for (i=0; i<chest.size(); i++)
    if (!opened[i]){
      ch[chest[i]]--;
    }
  for (i=0; i<250; i++) if (ch[i]<0) return false;
  for (i=0; i<chest.size(); i++){
    if (!opened[i]){
      for (j=0; j<key.size(); j++)
        if (key[j]==chest[i]) break;
      if (j!=key.size()){
        opened[i]=true;
        key.erase(key.begin()+j);
        for(k=0;k<chest_key[i].size();k++)
          key.push_back(chest_key[i][k]);
        seq.push_back(i);
        tmp = unlock(key,chest,chest_key,opened,seq);
        if (tmp) break;
        else{
          opened[i]=false;
          key.insert(key.begin()+j,chest[i]);
          for(k=0;k<chest_key[i].size();k++)
            key.pop_back();
          seq.pop_back();
        }
      }
    }
  }
  return tmp;
}

int main(){
  int t,k,n,i,j,m,p,t1,k1,k2;
  int ch[250];
  vector<int> key;
  vector<int> chest;
  vector<bool> opened;
  vector<vector<int> > chest_key;
  vector<int> seq;
  cin>>t;
  for (i=1; i<=t; i++){
    cout << "Case #" << i << ": ";
    for (j=0;j<250;j++) ch[j]=0;
    key.clear();
    chest.clear();
    opened.clear();
    chest_key.clear();
    seq.clear();
    cin>>k>>n;
    for (j=0; j<k; j++){
      cin>>m;
      key.push_back(m);
      ch[m]++;
    }
    for (j=0; j<n; j++){
      cin>>t1>>k1;
      chest.push_back(t1);
      ch[t1]--;
      opened.push_back(false);
      vector<int> v;
      for(p=0;p<k1;p++){
        cin>>k2;
        v.push_back(k2);
        ch[k2]++;
      }
      chest_key.push_back(v);
    }
    for (j=0; j<250; j++)
      if (ch[j]<0) break;
    if (j<250) cout << "IMPOSSIBLE" << endl;
    else if (unlock(key,chest,chest_key,opened,seq)){
      cout << seq[0]+1;
      for(j=1; j<seq.size(); j++)
        cout << ' ' << 1+seq[j];
      cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
