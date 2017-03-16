#include<iostream>
#include<string>
using namespace std;

int main (){
  int t; cin >>t;
  for(int cse = 1; cse<= t; cse++){
    cout<<"Case #"<<cse<<": ";
    string a ; cin >> a;
    string b ;
    for(int i =0 ; i <a.size(); i++)
      if( b.size() == 0 or b[0] > a[i])
         b+=a[i];
      else 
        b = a[i] + b;
    cout<<b<<endl;
  }

}
