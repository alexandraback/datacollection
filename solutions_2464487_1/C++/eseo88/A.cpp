#include<iostream>
#include<cmath>

using namespace std;

int main() {
  int cas;
  cin>>cas;
  for(int ca=1;ca<=cas;++ca) {
    double r,t;
    cin>>r>>t;
    double agg = 0;
    double a = 2;
    double b= 2*r-1;
    double c = -t;
    long long int ans = (long long int)floor((-b + sqrt(b*b-4*a*c))/(2*a));
    if (ans == (long long int)0) {
      ans++;
    }
    cout<<"Case #"<<ca<<": ";
    cout<<ans<<endl;

    /*
    for(int i=1; i< 11;++i) {
      double add = i*2-1;
      agg += (r+add)*(r+add)-(r+add-1)*(r+add-1);
//      cout<<i<<" "<<agg<<" "<<(2*r-3)*i+(2*(i+1)*i)<<" "<<2*i*i+i*(2*r-1)<<endl;
      if (agg > t) {
        cout<<i-1<<endl;
        break;
      }
    }
    */
  }
}
