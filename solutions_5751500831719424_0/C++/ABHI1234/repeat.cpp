#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int t,l=1,n,i,j,g,k,m;
  cin>>t;
  int ans;
  string a[2];
  while(l<=t){
    cin>>n;
    cin>>a[0]>>a[1];
    i = 0;g = 0;
    ans = 0;
    m = a[0].length();
    n = a[1].length();
    while(i < m || g < n ){
      j =0;k=0;
      while(i+j<m && a[0][i] == a[0][i+j] ){
	j++;
      }
      while(g + k < n && a[1][g] == a[1][g+k] ){
	k++;
      }
      if(a[1][g] != a[0][i]){
    	cout<<"Case #"<<l<<": Fegla Won\n";
	 i = m;
	 g = n;
	 ans = -1;
	}
     else{
       if(j != k)
        ans = ans + abs(j-k);
       i += j;
       g += k;
     }
    }
    if (ans != -1)
    cout<<"Case #"<<l<<": "<<ans<<endl;
    l++;
  }
  return 0;
}
