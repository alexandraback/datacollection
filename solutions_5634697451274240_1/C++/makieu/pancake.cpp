#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


int testcase(){
  string s;
  cin>>s;
  char curr ='+';
  int swap =0;
  for(int i=s.size()-1;i>=0;i--){
    if(curr!= s[i]){
      curr=s[i];
      swap++;
    }
  }
  cout<<swap<<endl;
}


int main(){
	int nb;
	cin >>nb;
	for(int i=0; i<nb; i++){
		cout << "Case #"<<i+1<<": "; 
    testcase();
  }
	return 0;
}
