#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<utility>
#include<string>
#include<sstream>
#include<cmath>
#include<list>
#include<new>

using namespace std;

#define tr(c, it) \
        for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

#define all(c) (c).begin(),(c).end()

typedef long long int LLI;

int main()
{	
	int N;
	cin >> N;

	for(int i = 0; i < N; i++){

		int e,r,n;
		cin >> e >> r >> n;

		vector<int>v(n,0);

		for(int h = 0; h < n; h++){
			cin >> v[h];
		}
		
		vector< vector<int> > ans(n, vector<int>(e+1,0));
				
		for(int h = n-1; h >= 0; h--){

			for(int k = e; k >= 0; k--){
				
				if(h+1 <= n-1){

					int max_ans = k*v[h] +  ans[h+1][r];
					for(int j = 1; j <= k; j++){
						if(max_ans < ((k-j)*v[h] + ans[h+1][min(e,j+r)])) {
							max_ans = (k-j)*v[h] + ans[h+1][min(e,j+r)];
						}
					}

					ans[h][k] = max_ans;	
				}
	
				else{

					ans[h][k] = k*v[h];	
				}

			}
		}

		int max_ans = ans[0][e];
		for(int k = e-1; k >= 0; k--){
			if(max_ans < ans[0][k]){
				max_ans = ans[0][k];
			}
		}
	
		cout << "Case #" << i+1 << ": " << max_ans << endl;

	}

	return 0;
}
