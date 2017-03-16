#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
  
  freopen("in.dat","r",stdin);

  int T;
  cin>>T;
  
  for (int iT=1;iT<=T;iT++){
    cout<<"Case #"<<iT<<": ";
    
    int A, B;
    cin>>A>>B;
    
    vector<double> p; 
    p.push_back(1);
    for (int i=1;i<=A;i++) {
      double prob;
      cin>>prob;
      p.push_back(prob);
    }

    double E= B+2; 
    vector<double> result; 
    result.push_back(E);

    double Q= 1.0;
    for (int k=0;k<=A; k++){
      Q*= p[k];
      double k1= A-k;
      E= Q * ( k1+k1+B+1-A) + (1-Q)* ( k1+k1+2+B+B-A);
      result.push_back(E);
      }
    
    double answer= *min_element(result.begin(), result.end());
    printf("%.6f\n",answer);
  }

  return 0;
}
