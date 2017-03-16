#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

int main() {
  int t;
  int n;
  string str1,str2;
  vector<string> vec1, vec2;
  cin>>t;
  unordered_set<string> myset1;
  unordered_set<string> myset2;
  for (int i=0;i!=t;i++) {
    cin>>n;
    vec1.clear();
    vec2.clear();
    myset1.clear();
    myset2.clear();
    for (int j=0;j!=n;j++) {
      cin>>str1>>str2;
      vec1.push_back(str1);
      vec2.push_back(str2);
      myset1.insert(str1);
      myset2.insert(str2);
    }
    int tot=(1<<n);
    int best=n;
    for (int j=0;j!=tot;j++) {
      int tmp=j;
      int cnt=0;
      int now=0;
      unordered_set<string> tmpset1(myset1);
      unordered_set<string> tmpset2(myset2);
      while (tmp) {
	if (tmp&1) {
	  tmpset1.erase(vec1[cnt]);
	  tmpset2.erase(vec2[cnt]);
	  now++;
	}
	tmp>>=1;
	cnt++;
      }
      if (now<best && tmpset1.empty() && tmpset2.empty()) best=now;
    }
    cout<<"Case #"<<i+1<<": "<<n-best<<endl;
  }
}
