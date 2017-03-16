
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<numeric>
using namespace std;

  

int main(){

  freopen("in.dat","r",stdin);
  int T; 
  cin>>T; 

  for (int iT=1;iT<=T;iT++){
    cout<<"Case #"<<iT<<": ";
    int N;
    cin>>N;
    
    vector<double> s,s2; 
    for (int i=0;i<N;i++){
      double score;
      cin>>score;
      s.push_back(score);
    }
    
    s2=s;
 
    double  X = accumulate( s.begin(), s.end(), 0 );
    
    for (int k=0;k<N;k++){
      if (k) cout<<" ";
 
      vector<double> pk;

      vector<double> s= s2;
      s.erase(s.begin()+k);
      sort(s.begin(),s.end());
      
      for (int i=0;i<s.size();i++){
	double tmp=0;
	for ( int j=0;j<=i;j++) tmp+=s[j];
	double numerator= tmp+ X-(i+1)*s2[k];
	double ratio =numerator/(X* (i+2));
	//	cout<<i<<" :"<<numerator<<" "<<ratio<<endl;
	pk.push_back(ratio);
      }
      

      double * result= min_element(&pk[0],(&pk[0])+pk.size());
      if (*result<0) *result=0;
      printf("%.6f",*result*100);
    }
    cout<<endl;

  }

  return 0 ;
}
