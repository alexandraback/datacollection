#include <bits/stdc++.h>

using namespace std;
int mat[50][50];

int main()
{
    ifstream cin("B-large (1).in");
    ofstream cout("out.txt");
    int t ;
    cin >>t ;
    int cp = 1 ;
    while(t--){
            cout << "Case #" << cp++ << ": " ;
      long long n ,m ;
      cin >> n >> m ;

      if (m>(1LL<<(n-2)) ) {
            cout << "IMPOSSIBLE\n";
      continue;
      }
      cout << "POSSIBLE\n";
      memset(mat , 0 , sizeof mat);
      for(int i =0 ; i< n ; i++){
        for(int j = i+1 ; j<n ; j++) mat[i][j]=1 ;
      }
      if(m!=(1LL<<(n-2))) {
        mat[0][n-1]=0;
        for(int i = 1 ; i< n ; i++){
            if(!((1LL<<(i-1)) & m)) mat[i][n-1]=0;
        }
      }
      for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j< n ; j++) cout <<mat[i][j];
        cout<<endl;
      }
    }
    return 0;
}
