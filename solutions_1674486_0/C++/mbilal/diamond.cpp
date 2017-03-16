#include<cstdio>
#include<iostream>
using namespace std;
//#define DEBUG
int main()
{
	int t;
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++){	
		int n;
		int resmat[50][50];
		int mat[50][50];
		int m;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			for(int k=0; k<n; k++){
				resmat[i][k] = 0;
				mat[i][k] = 0;
			}
			scanf("%d", &m);
			int col;
			for(int j=0; j<m; j++){
				scanf("%d", &col);
				resmat[i][col-1] = 1;
				mat[i][col-1] = 1;
			}
		}
		
		#ifdef DEBUG
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++)
					printf("%d ", mat[i][j]);
				printf("\n");
			}
			printf("\n");
		#endif
		int c[50][50], d[50][50];
		for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					d[i][j] = mat[i][j];
		for(int I=0; I<n; I++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					c[i][j] = 0;
					for(int k=0; k<n; k++)
						c[i][j] += (resmat[i][k]*mat[k][j]);
				}
			}
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++){
					resmat[i][j] = c[i][j];
					d[i][j] += c[i][j];
				}
		}				
		
		#ifdef DEBUG
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++)
					printf("%d ", d[i][j]);
				printf("\n");
			}
		#endif
		
		cout<<"Case #"<<tc<<": ";
		int found = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(d[i][j] >=2){
					found = 1;
				}
			}
		}
		if(found == 1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
				
			
		
			
			
			
			