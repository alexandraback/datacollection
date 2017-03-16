#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


int testcase(){
	long long N;
	cin >> N;
	vector<bool>seen(10,false);
  long long val =-1;
  for(int i=1;i<1000 && val ==-1;i++){
    long long t= N*i;
    while(t>0){
      seen[t%10]=true;
      t=t/10;
    }
    bool ok = true;
    for(int j=0;j<10;j++) if(!seen[j])ok = false;
    if(ok) val = N*i;
  }
  if(val==-1)
    cout<<"INSOMNIA"<<endl;
  else
    cout<< val <<endl;
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
