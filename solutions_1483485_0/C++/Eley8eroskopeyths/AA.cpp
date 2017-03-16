#include<iostream>
#include<cmath>

using namespace std;

int main() {

  int T;
  cin>>T;

  string A;
  getline(cin,A,'\n');
  for(int i=1;i<=T;i++) {
    getline(cin,A,'\n');
    cout<<"Case #"<<i<<": ";
    for(int j=0;j<=A.length();j++) {
      if(A[j]==' ') cout<<" ";
      else if(A[j]=='a') cout<<"y";
      else if(A[j]=='b') cout<<"h";
      else if(A[j]=='c') cout<<"e";
      else if(A[j]=='d') cout<<"s";
      else if(A[j]=='e') cout<<"o";
      else if(A[j]=='f') cout<<"c";
      else if(A[j]=='g') cout<<"v";
      else if(A[j]=='h') cout<<"x";
      else if(A[j]=='i') cout<<"d";
      else if(A[j]=='j') cout<<"u";
      else if(A[j]=='k') cout<<"i";
      else if(A[j]=='l') cout<<"g";
      else if(A[j]=='m') cout<<"l";
      else if(A[j]=='n') cout<<"b";
      else if(A[j]=='o') cout<<"k";
      else if(A[j]=='p') cout<<"r";
      else if(A[j]=='q') cout<<"z";
      else if(A[j]=='r') cout<<"t";
      else if(A[j]=='s') cout<<"n";
      else if(A[j]=='t') cout<<"w";
      else if(A[j]=='u') cout<<"j";
      else if(A[j]=='v') cout<<"p";
      else if(A[j]=='w') cout<<"f";
      else if(A[j]=='x') cout<<"m";
      else if(A[j]=='y') cout<<"a";
      else if(A[j]=='z') cout<<"q";
    }
    cout<<endl;
  }

  return 0;
}
