#include<iostream>

using namespace std;

double nao[1001];
double ken[1001];
int main() {
  int ca;
  cin>>ca;
  for(int cas=1;cas<=ca; cas++) {
    int n;
    cin>>n;
    for(int i=0 ;i<n; ++i) {
      cin>>nao[i];
    }
    for(int i=0 ;i<n; ++i) {
      cin>>ken[i];
    }
    sort(nao, nao+n);
    sort(ken, ken+n);
    
    int ns=0, ne=n-1;
    int ks=0, ke=n-1;
    int der = 0;
    while(ns<n && ks<n) {
      while(ns < n && ken[ks] > nao[ns]) {
        ns++; 
      }
      if (ns == n) break;
      der++;
      ns++;
      ks++;
    }

    ks = 0;
    ns = 0;
    int war = 0;
    while (ne>=0) {
      if (nao[ne] > ken[ke]) {
        war++;
        ks++;
      } else {
        ke--;
      }
      ne--;
    }
    cout<<"Case #"<<cas<<": "<<der<<" "<<war<<endl;
  }
}
