#include <vector>
#include <string>
#include <iostream>
using namespace std;

int DEBUG;
int bit(int n) { return 1<<n; }
int on(int n, int mask) { return ((1<<n)&mask)>0; }
int mem[1024][10][10][10][2];

int doit2(vector<int> v, int mask, int start, int v1, int v2, int f, int ct) {
  if(mem[mask][start][v1][v2][f]!=-1) return mem[mask][start][v1][v2][f];
  int ret=0;
  for(int v3=0;v3<v.size();v3++) if(!on(v3,mask)) {
    if(v[v2]==v1||v[v2]==v3) {
      ret=max(ret,doit2(v,mask|bit(v3),start,v2,v3,f,ct+1));
    }
  }
  for(int v3=0;v3<v.size();v3++) if(!on(v3,mask)) {
    if(v[v2]==v1||v[v2]==v3) {
      if(v[v3]==v2||v[v3]==start) {
        if(f||v[start]==v3) {
          ret=max(ret,ct+1);
        }
      }
    }
  }
  return mem[mask][start][v1][v2][f]=ret;
}
    

int doit(vector<int> v) {
  memset(mem,-1,sizeof(mem));
  int ret=2;
  for(int i=0;i<v.size();i++) {
    for(int j=0;j<v.size();j++) if(i!=j) {
      ret=max(ret,doit2(v,bit(i)|bit(j),i,i,j,v[i]==j,2));
    }
  }
  return ret;
}

int main() {
  int tests;
  cin>>tests;
  for(int i=0;i<tests;i++) {
    int n;
    cin>>n;
    vector<int> v;
    for(int j=0;j<n;j++) {
      int val; cin>>val; v.push_back(val-1);
    }
    DEBUG=0;
    int ret=doit(v);
    cout<<"Case #"<<(i+1)<<": "<<ret<<endl;
  }
  return 0;
}
