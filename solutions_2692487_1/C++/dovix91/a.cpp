#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

int T;
int a, n;
int x[102];
long mat[103][103];

int main() {
	int t;
	int i, j, k, l, r;

    cin>>T;
    for(t=0; t<T; t++) {
		cout<<"Case #"<<t+1<<": ";

		cin>>a>>n;
   	 	for(i=0; i<n; i++) cin>>x[i];

		sort(x, x+n);
		for(i=0; i<=n; i++) for(j=0; j<=n; j++) mat[i][j]=0;

		// first line
		mat[0][0]=a;
		for(j=1; j<=n; j++) {
			long curr = mat[0][j-1]-1;
			if(curr > 1000000) curr = 1000000;
			mat[0][j] = mat[0][j-1]+curr;
		} 

		// next lines
		for(i=1; i<=n; i++) {
			for(j=0; j<=n; j++) {
				if(mat[i-1][j] > x[i-1]) mat[i][j] = max(mat[i][j], mat[i-1][j]+x[i-1]);
				if(j>0) mat[i][j] = max(mat[i][j], mat[i-1][j-1]);
				if(mat[i][j]>0) for(k=j+1; k<n; k++) {
					long curr = mat[i][k-1]-1;
					if(curr > 1000000) curr = 1000000;
					mat[i][k] = max(mat[i][k], mat[i][k-1]+curr);
				}

				//for(l=0; l<=n; l++) { for(r=0; r<=n; r++) cout<<mat[l][r]<<" "; cout<<endl; }
				//cout<<endl;
			}

			//for(l=0; l<=n; l++) { for(r=0; r<=n; r++) cout<<mat[l][r]<<" "; cout<<endl; }
		}

		//for(i=0; i<=n; i++) { for(j=0; j<=n; j++) cout<<mat[i][j]<<" "; cout<<endl; }

		for(j=0; j<=n; j++) {
			if(mat[n][j] > 0) { cout<<j<<endl; break; }
		} 
		
	}


	return 0;
}
