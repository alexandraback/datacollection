#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

int main(){
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    int N;
    cin>>N;
    vector<string> firsts(N);
    vector<string> seconds(N);
    set<string> fi;
    set<string> se;
    for (int i=0;i<N;i++){
      cin>>firsts[i]>>seconds[i];
    }
    int best=0;
    for (int i=(1<<N)-1;i>0;i--){
      int cur=0;
      for (int j=0;j<N;j++) {
	if (i&(1<<j)) cur++;
      }
      if (cur<=best) continue;
      for (int j=0;j<N;j++) {
	if (i&(1<<j)) continue;
	fi.insert(firsts[j]);
	se.insert(seconds[j]);
      }
      for (int j=0;j<N;j++) {
	if (i&(1<<j)==0) continue;
	if (fi.find(firsts[j]) == fi.end()) {
	  cur=0; break;
	}
	if (se.find(seconds[j]) == se.end()) {
	  cur=0;break;
	}
      }
      fi.clear();
      se.clear();
      if (cur == 0) continue;
      best=cur;
    }
    cout<<"Case #"<<t<<": "<<best<<endl;
  }
}
