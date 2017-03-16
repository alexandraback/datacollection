#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    string N;
    cin>>N;
    long long sum=0;
    int l = N.length();
    while (l>0) {
      l = N.length();
      long long sum1=0;
      for (int i=l/2-1;i>=0;i--){
	sum1*=10;
	sum1+=N[i]-'0';
      }
      long long sum2=0;
      for (int i=l/2;i<l;i++) {
	sum2*=10;
	sum2+=N[i]-'0';
      }
      //      cout<<N<<' '<<sum1<<' '<<sum2<<endl;
      if (sum2==0) {
	stringstream strstr;
	strstr<<N;
	long long ll;
	strstr>>ll;
	ll--;
	sum++;
	stringstream strstr2;
	strstr2<<ll;
	strstr2>>N;
	continue;
      }
      sum+=sum2;
      sum+=sum1;
      if (sum1>1) {
	sum++;
      }
      l--;
      N="";
      for (int i=0;i<l;i++){
	N+="9";
      }
    }
    cout<<"Case #"<<t<<": "<<sum<<endl;
  }
}
