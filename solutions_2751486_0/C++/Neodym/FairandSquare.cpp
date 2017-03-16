#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
#define long long long

  ifstream f("input.txt");
  ofstream of("output.txt");

  long Res(long A[], long n,long si){

   //cout<<"\n";for(long i=0;i<si;++i)cout<<A[i]<<" ";cout<<"\n";

    long d[si+1];

    d[0]=0;

    for (long i=0;i<si;++i)d[i+1]=d[i]+A[i];

    long val=-1;

    long S=0;

    for (long i=n-1;i<si;++i){
        if(d[i+1]-d[i-n+1]==n)val=i;
        if(val!=-1)S+=(val-n+2);
        //cout<<val<<" "<<i<<" "<<S<<"\n";
        }

    return S;

  }



  long Solve(){

    string s;
    f>>s;
    long n;
    f>>n;

    long si=s.length();

    long A[si];

    for(long i=0;i<si;++i){
      A[i]=1;
      if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u')A[i]=0;
    }

    return Res(A,n,si);

  }



int main(){

  long T;

  f>>T;

  for(long i=1;i<=T;++i){
    of<<"Case #"<<i<<": "<<Solve()<<"\n";
  }

return 0;
}
