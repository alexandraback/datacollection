#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;



int main(){
	int i,j,k,l;
	int N, T, M;
	long long *powOf2 = new long long[52];
	int **adj;
	powOf2[0] = powOf2[1] = 1;
	for(i = 2 ; i < 51 ; i++)
		powOf2[i] = 2 * powOf2[i - 1];
	cin>>T;
	for(l = 0 ; l < T ; l++)
	{
		cin>>N>>M;
		adj = new int *[N];
		for(i = 0 ; i < N ; i++)
			adj[i] = new int[i];
		for( i = 0 ; i < N ; i++)
			for(j = 0 ; j < N ; j++)
				adj[i][j] = 0;
		for(i = 0 ; i < N - 1 ; i++)
			for(j = i + 1 ; j < N - 1 ; j++)
				adj[i][j] = 1;
		cout<<"Case #"<<l+1<<": ";
		if(M > powOf2[N - 1]){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		cout<<"POSSIBLE\n";
		for(i = N - 2 ; i > 1  ; i--){
			//cout<<powOf2[i]<<"\t";
			if(M >= powOf2[i]){
				adj[i][N-1] = 1;
				M = M - powOf2[i];
			}
		}
		if(M >= powOf2[0]){
				adj[0][N-1] = 1;
				M = M - powOf2[0];
		}

		
		if(M >= powOf2[1]){
				adj[1][N-1] = 1;
				M = M - powOf2[1];
		}
			
		//cout<<"\n";
		for(i = 0 ; i < N ; i++){
			for(j = 0 ; j < N ; j++)
			{
				cout<<adj[i][j]<<"\t";
			}
			cout<<"\n";
		}
		for( i = 0 ; i < N ; i++)
			delete[] adj[i];
		delete[] adj;
	}
	delete[] powOf2;
	return 0;
}	
