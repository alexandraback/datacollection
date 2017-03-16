#include <iostream>
#include <cstring>

using namespace std;
int heights[2502];

int main(){
  int t, n, height, printed;

  cin>>t;

  for(int cas=1; cas<=t; cas++) {
    cout<<"Case #"<<cas<<": ";
    cin>>n; 
    memset(heights, 0, 2502*sizeof(int));
    for(int i=0; i<2*n-1; i++)
      for(int j=0; j<n; j++) {
        cin>>height;
        heights[height]++;
      }

    printed=0;
    for(int i=1; i<=2500; i++)
      if(heights[i]%2==1) {
        cout<<i;
        printed++;
        if(printed!=n)cout<<" ";
      }
    cout<<endl;
    
    
  }
}
