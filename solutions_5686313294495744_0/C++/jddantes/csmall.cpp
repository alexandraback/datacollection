#include <bits/stdc++.h>

using namespace std;
typedef pair<string, string> ps;
int main(){
	int cases;
	scanf("%d", &cases);

	for(int e = 0; e<cases; e++){

		int N;
		scanf("%d", &N);
		vector<ps> input;
		set<string> first_dump;
		set<string> second_dump;
		for(int x = 0; x<N; x++){
			string a, b;
			cin >> a >> b;
			input.push_back(ps(a,b));
			first_dump.insert(a);
			second_dump.insert(b);
		}	

		int best = 0;
		int first_sz = first_dump.size();
		int second_sz = second_dump.size();
		for(int x = 0; x< (1<<N); x++){
			set<string> dump1;
			set<string> dump2;

			int num_on = 0;

			for(int i = 0; i<N; i++){
				if(x & (1<<i)){
					dump1.insert(input[i].first);
					dump2.insert(input[i].second);
					num_on++;
				}
			}

			if(dump1.size() == first_sz && dump2.size() == second_sz){
				int num_off = N - num_on;
				best = max(best, num_off);
			}
		}

		printf("Case #%d: %d\n", e+1, best);

	}	

	return 0;
}