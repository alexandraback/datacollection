#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<PII> VPII;

typedef vector<double> VD;
typedef vector<string> VS;

typedef long long LL;

int main(){ 	
	int cases;
	scanf("%d\n", &cases);
	
	for(int caseNr = 1; caseNr <= cases; caseNr++){
		// go for it!	
		printf("Case #%d: ", caseNr);
		
		// READ
		int N;
		scanf("%d", &N);
		
		long M[N][N];
		memset(M, 0, sizeof(M));
		
		int c;
		int k;
		for(int i=0; i<N; i++){
			scanf("%d", &c);
			for(int j=0;j<c;j++){
				scanf("%d", &k);
				M[k-1][i] = 1;
			}
		}
		long sum[N][N];		
		memset(sum, 0, sizeof(sum));
		
		long M2[N][N];
		long M3[N][N];	
		// copy M2
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				M2[i][j] = M[i][j];
				sum[i][j] = M[i][j];
			}
		}
			
		long s;
		bool success = false;
		for(int z=0;z<N;z++){
		
			// DEBUG
			/*cout << endl;
			cout << "DBG" << endl;
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					printf("%d ", M2[i][j]);
				}
				cout << endl;
			}*/
		
			// do matrix multiplication: M2 * M
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					s = 0L;
					// no multiplicate row i and column j
					for(int k=0;k<N;k++){
						s += M2[i][k] * M[k][j];
					}
					
					if(s>1){
						success = true;
						goto jump;
					}
					
					M3[i][j] = s;
				}
			}	
			// copy M2
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					M2[i][j] = M3[i][j];
					sum[i][j] += M3[i][j];
					if(sum[i][j]>1){
						success = true;
						goto jump;
					}
				}
			}
			
		}
		
		jump:
		
		
		/*cout << endl;
		cout << "DBG SUM" << endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%d ", sum[i][j]);
			}
			cout << endl;
		}*/
		
		if(success){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		
		fflush(stdout);
	}
	
	return 0;
}
