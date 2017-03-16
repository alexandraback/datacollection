#include<iostream>
#include<fstream>
using namespace std;

int main()
{
 #define cin fin
 #define cout fout
 ifstream fin("in");
 ofstream fout("out");
 
 int t, r, c, w;
 long long ans;
 cin>>t;
 for(int k=1;k<=t;k++)
 {
  cin>>r>>c>>w;
  ans=c/w;
  ans*=r;
  ans+=(w-1);
  if(c%w!=0)
   ans++;
  cout<<"Case #"<<k<<": "<<ans<<endl;
 }
}


