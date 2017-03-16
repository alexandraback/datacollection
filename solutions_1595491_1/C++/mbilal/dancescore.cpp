#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
	scanf("%d\n",&t);
	for(int tc = 1; tc <= t; tc++){
		printf("Case #%d: ", tc);
		int n, s, p;
		vector<int> scores;
		scanf("%d %d %d ",&n, &s, &p);
		for(int i=0; i<n; i++){
			int val;
			scanf("%d ", &val);
			scores.push_back(val);
		}
		
		int count = 0;
		if(p == 0)
			count = n;
		else{
			sort(scores.begin(), scores.end());
			reverse(scores.begin(), scores.end());
			
			for(int i=0; i<n; i++){
				if(scores[i] >= 3*p - 2) count++;
				else if( (scores[i] >= 3*p -4) && scores[i] > 0 && s != 0){
					count++;
					s--;
				}
				else break;
			}
		}
		
		printf("%d\n", count);
	}
	return 0;
}
			
		