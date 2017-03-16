#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

long long mmax = 0;



int main()
{
	freopen("C-small-attempt3.in" ,"r" ,stdin);
	freopen("test.out" ,"w" ,stdout);
	int T;
	cin >> T;
	for (int t = 1 ;t <= T ;++t){
		long long a[128] ,b[128];
		int A[128] ,B[128];
		int N ,M;
		cin >> N >> M;
		for (int i= 0 ;i < N ;++i)
			cin >> a[i] >> A[i];
		for (int i = 0 ;i < M ;++i)
			cin >> b[i] >> B[i];
	
		if (N == 3){
			if (A[0] == A[1]){
				a[0] = a[0]+a[1];
				A[1] = A[2];
				a[1] = a[2];
				N = 2;
			}else if (A[1] == A[2]){
				a[1] = a[1]+a[2];
				N = 2;
			} 
		}
		
		if (N == 2){
			if (A[1] == A[0]){
				a[0] = a[0] + a[1];
				N = 1;
			}
		}
		mmax = 0;	
		if (N == 1){
		
			for (int i = 0 ;i < M ;i++){
				if (B[i] == A[0]){
					mmax += b[i];
				}
			}
			mmax = min(mmax ,a[0]);
		}else if (N == 2){
			for (int i = 0 ;i <= M ;i++){
				long long tmmax = 0;
				long long mmax1 = 0;
				for (int j = 0 ;j < i ;++j){
					if (B[j] == A[0]){
						mmax1 += b[j];
					}
				}
				tmmax += min(mmax1 ,a[0]);
				long long mmax2 = 0;
				for (int j = i ;j < M ;++j){
					if (B[j] == A[1]){
						mmax2 += b[j];
					}
				}
				tmmax += min(mmax2 ,a[1]);
				mmax = max(tmmax ,mmax);
			}
		}else if (N == 3){
			for (int i = 0 ;i <= M ;++i){
				for (int j = i ;j <= M ;++j){
					long long tmmax = 0;
					long long mmax1 = 0 ,mmax2 = 0 ,mmax3 = 0;
					for (int k = 0 ;k < i ;++k){
						if (B[k] == A[0])
							mmax1 += b[k];
					}
					tmmax += min(mmax1 ,a[0]);
					for (int k = i ;k < j ;++k){
						if (B[k] == A[1]){
							mmax2 += b[k];
						}
					}
					tmmax += min(mmax2 ,a[1]);
					for (int k = j ;k < M ;++k){
						if (B[k] == A[2]){
							mmax3 += b[k];
						}
					}
					tmmax += min(mmax3 ,a[2]);
//					cout << i << " "<< j << ":" << tmmax << endl;
					mmax = max(mmax ,tmmax);
				}
			}
			if (A[0] == A[2]){
				long long tmmax = 0;
				for (int i = 0 ;i < M ;i++){
					if (B[i] == A[0]){
						tmmax += b[i];
					}
				}
				tmmax = min(tmmax ,a[0]+a[2]);
				mmax = max(mmax ,tmmax);
			}
		}
		cout << "Case #" << t << ": "  << mmax << endl;
		
	}
	return 0;
}
