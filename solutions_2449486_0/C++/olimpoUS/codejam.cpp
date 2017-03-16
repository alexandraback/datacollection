#include<stdio.h>
#include<iostream>
using namespace std;
int t,n,m,A[103],B[103],M[103][103];
bool F(){
	for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
			 if(A[i] > M[i][j])
			   if(B[j] > M[i][j])
			     return false;
	return true;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> t;
	int tt = 1;
	while(t--){
		printf("Case #%d: ",tt++);
		cin >> n >> m;
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++){
				cin >> M[i][j];
				
				if(j == 0)A[i] = M[i][j];
				A[i] = max(A[i],M[i][j]);
				
				if(i == 0)B[j] = M[i][j];
				B[j] = max(B[j],M[i][j]);
			}
		if(F())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
