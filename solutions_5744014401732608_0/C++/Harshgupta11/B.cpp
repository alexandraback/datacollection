#include "bits/stdc++.h"

using namespace std;

#define mp make_pair
typedef long long int ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

void solve()
{
	int i,j,B,M;
   cin >> B >> M;
   if(B == 2 && M > 1){ cout << "IMPOSSIBLE\n"; return; }
   if(B == 3 && M > 2){ cout << "IMPOSSIBLE\n"; return; }
   if(B == 4 && M > 4){ cout << "IMPOSSIBLE\n"; return; }
   if(B == 5 && M > 9){ cout << "IMPOSSIBLE\n"; return; }
   if(B == 6 && M > 15){ cout << "IMPOSSIBLE\n"; return; }
   cout << "POSSIBLE\n";
   int matrix[B+1][B+1];
   memset(matrix,0,sizeof(matrix));
   if(M <= B-1){
   	 matrix[1][B] = 1;
   	 for(i = 2;i<=M;++i){
   	 	matrix[i][B] = 1;
   	 	matrix[1][i] = 1;
   	 }
   	 for(i = 1;i<=B;++i){
   	 	for(j = 1;j<=B;++j){
   	 		cout << matrix[i][j];
   	 	}
   	 	cout << '\n';
   	 }
   	 return;
   }
   matrix[1][B] = 1;
   for(i = 2;i<B;++i){
   	  matrix[1][i] = 1;
   	  matrix[i][B] = 1;
   }
   M-=(B-1);
   if(M == 1){
   	 matrix[B-1][B-2] = 1;
   }
   else if(M == 2){
   	 matrix[2][3] = 1;
   	 matrix[B-1][B-2] = 1;
   }
   else if(M == 3){
   	 matrix[B-1][B-2] = 1;
   	 matrix[B-2][B-3] = 1;
   }
   else if(M == 4){
   	 matrix[B-1][B-2] = 1;
   	 matrix[B-2][B-3] = 1;
   	 matrix[B-1][B-3] = 1;   	 
   }
   else if(M == 5){
   	 matrix[B-1][B-2] = 1;
   	 matrix[B-2][B-3] = 1;
   	 matrix[B-1][B-3] = 1; 
   	 matrix[2][3] = 1;     
   }
   else if(M == 6){
   	 matrix[B-1][B-2] = 1;
   	 matrix[B-2][B-3] = 1;
   	 matrix[B-3][B-4] = 1;
   }
   else if(M == 7){
     matrix[B-1][B-2] = 1;
   	 matrix[B-2][B-3] = 1;
   	 matrix[B-3][B-4] = 1;
   	 matrix[B-1][2] = 1;  	
   }
   else if(M == 8){
   	   	 matrix[B-1][B-2] = 1;
   	 matrix[B-2][B-3] = 1;
   	 matrix[B-3][B-4] = 1;
   	 matrix[B-1][3] = 1;
   }
   else if(M == 9){
   	 matrix[B-1][B-2] = 1;
   	 matrix[B-2][B-3] = 1;
   	 matrix[B-3][B-4] = 1;
   	 matrix[B-1][3] = 1;
   	 matrix[B-2][2] = 1;
   }
   else if(M == 10){
    	 matrix[B-1][B-2] = 1;
   	 matrix[B-2][B-3] = 1;
   	 matrix[B-3][B-4] = 1;
   	 matrix[B-1][3] = 1;
   	 matrix[B-2][2] = 1;
   	 matrix[B-1][2] = 1;  	
   }
      	 for(i = 1;i<=B;++i){
   	 	for(j = 1;j<=B;++j){
   	 		cout << matrix[i][j];
   	 	}
   	 	cout << '\n';
   	 }

}

int main()
{
	int T;
	cin >> T;
	for(int i = 1;i<=T;++i){
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;
}
