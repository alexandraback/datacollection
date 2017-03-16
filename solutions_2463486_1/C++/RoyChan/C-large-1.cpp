#include <iostream>
#include <cmath>
using namespace std;

bool palindrome(string s){
  if (s.length()==1) return true;
  int i,j;
  i=0;j=s.length()-1;
  while(i<j && s[i]==s[j]){i++;j--;}
  return (i>=j);
}

int main(){
  int t,i,j,k;
  double m,n,s,e;
  double ch[]={1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002};
  cin>>t;
  for(i=1;i<=t;i++){
    cout << "Case #" << i << ": ";
    cin>>m>>n;
    s = ceil(sqrt(m));
    e = floor(sqrt(n));
    k=0;
    for (j=0;j<39; j++)
      if (ch[j]>=s && ch[j]<=e) k++;
    cout << k << endl;
  }
  return 0;
}
