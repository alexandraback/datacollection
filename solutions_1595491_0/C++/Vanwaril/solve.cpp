#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N;
	
	cin>>N;
	// Case-independent stuff?
	
	// Cases:
	for(int t=1; t<=N; t++)
	{
		// Each Case:
		int output=0;
		
		// random variables
		
		// input variables
		int n, s, p; cin>>n>>s>>p;
		vector<int> scores(n);
		for(int i=0; i<n; i++) {
			cin>>scores[i];
		
		// compute
			if(p > 1) {
		// if score > (p-1)*3, no surprise needed.
			if(scores[i] > (p-1)*3)
				output++;
		// if score < (p-1)*3 -1, can't get even with surprise.
			else if(scores[i] < (p-1)*3 - 1)
				;
			else { // consume a surprise
				if(s > 0) {
					s--;
					output++;
				}
			}
			} else if (p == 0){ // p == 0
				output++;
			} else { // p == 1
				if(scores[i] != 0) output++;
			}
		}
		
		printf("Case #%d: %d\n", t, output);
	}
	return 0;
}
