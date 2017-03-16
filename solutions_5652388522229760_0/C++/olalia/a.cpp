#include<iostream>
#include<vector>
#include<set>
#include<algorithm>




using namespace std;


typedef long long ll;


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    ll n; cin>>n;
    set<int> s=set<int>();
    for (int i=1; i<1000000; ++i){
      ll d=n*i;
      while(d>0){
	s.insert(d%10);
	d/=10;
      }
      if (s.size()==10){
	n=n*i;
	break;
      }
      if (i+1==1000000)
	n=-1;
    }
    
    cout<<"Case #"<<tc<<": ";
    if (n==-1)
      cout<<"INSOMNIA\n";
    else
      cout<<n<<endl;
  }
  return 0;
}
