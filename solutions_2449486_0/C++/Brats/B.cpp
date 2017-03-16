#include<iostream>
using namespace std;

int main()
{
    int T, M, N;
	int row[100] = {0};
	int col[100] = {0};
	int v[100][100];
	
	cin >> T;
	int C = 0;
	int i,j;
	
	while (T--) {
	    C++;
	    cin>>N>>M;
		
		for (i=0; i<100; i++) row[i] = col[i] = 0;
		
		for (i=0; i<N; i++) {
		    for (j=0; j<M; j++) {
			    cin>>v[i][j];
				if (v[i][j] > row[i]) row[i] = v[i][j];
				if (v[i][j] > col[j]) col[j] = v[i][j];
			}
		}
		
		for (i=0; i<N; i++) {
		    for (j=0; j<M; j++) {
			    if (v[i][j] != row[i] && v[i][j] != col[j]) break;
			}
			
			if (j<M) break;
		}
		
		cout<<"Case #"<<C<<": ";
		if (i<N) 
		    cout<<"NO\n";
		else
		    cout<<"YES\n";
	}
}
