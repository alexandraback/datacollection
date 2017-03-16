/*
ID: nongeek1
PROG: my
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

ifstream fin("my.in");
ofstream fout("my.out");

inline void output(long long ret){
  static int t=0;
  fout << "Case #"<< ++t <<": " << ret << endl;
}
int a[100];
int n;

int cal(int me, int k){
  cout << me << " " << k << " " << a[k] << endl;
  while(k <n && me>a[k]){
    me += a[k];
    k++;
  }
  if(k==n) return 0;
  
  if(me==1) return n;

  int count = 0;
  while(me<=a[k]){
    me = me+me-1;
    count++;
  }
  cout << count << endl;
  int t=k;
  while(t<n && me>a[t])
    me += a[t++];
  if(count<=t-k)
    return count += cal(me, t);
  else
    return min(n-k, count+cal(me, t));
}
void solve(){
  int me;
  fin >> me >> n;
  cout << "---------" << endl;  
  for(int i=0; i<n; i++)
    fin >> a[i];
  
  for(int i=1; i<n; i++)
    for(int j=0; j<n-i; j++)
      if(a[j]>a[j+1])
	swap(a[j], a[j+1]);
  output(cal(me, 0));

}
int main(){
  int caseN;
  fin >> caseN;
  while(caseN--){
    solve();
  }

  return 0;
}
