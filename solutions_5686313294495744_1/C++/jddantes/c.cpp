#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> ps;
typedef pair<int, int> pi;
int main(){
	int cases;
	scanf("%d", &cases);

	for(int e = 0; e<cases; e++){

		int N;
		scanf("%d", &N);

		vector<ps> input;
		set<string> dump1;
		set<string> dump2;

		for(int i = 0; i<N; i++){
			string a, b;
			cin >> a >> b;
			dump1.insert(a);
			dump2.insert(b);
			input.push_back(ps(a,b));
		}

		int dump_sz1 = dump1.size();
		int dump_sz2 = dump2.size();

		map<string, int> dict1, dict2;

		int index = 0;
		for(auto word : dump1){
			dict1[word] = index++;
		}
		index = 0;
		for(auto word : dump2){
			dict2[word] = index++;
		}

		vector<int> taken1(dump_sz1, false);
		vector<int> taken2(dump_sz2, false);
		vector<vector<int>> adjList1(dump_sz1);
		vector<vector<int>> adjList2(dump_sz2);

		for(int i = 0; i<N; i++){
			int a=dict1[input[i].first];
			int b=dict2[input[i].second];

			adjList1[a].push_back(b);
			adjList2[b].push_back(a);
		}

		set<pi> dumpx;

		for(int i = 0; i<dump_sz1; i++){
			if(adjList1[i].size() == 1){
				taken1[i] = true;
				int adj = adjList1[i][0];
				taken2[adj] = true;
				dumpx.insert(pi(i,adj));
			}
		}
		for(int i = 0; i<dump_sz2; i++){
			if(adjList2[i].size() == 1){
				taken2[i] = true;
				int adj = adjList2[i][0];
				taken1[adj] = true;
				dumpx.insert(pi(adj, i));
			}
		}

		int x_sz = dumpx.size();

		int not_taken1 = 0;
		int not_taken2 = 0;

		for(int i = 0; i<dump_sz1; i++){
			if(!taken1[i]){
				not_taken1++;
			}
		}
		for(int i = 0; i<dump_sz2; i++){
			if(!taken2[i]){
				not_taken2++;
			}
		}

		// printf("not taken 1 is %d\nnot taken 2 is %d\n", not_taken1, not_taken2);
		// printf("Xdump is %d\n", x_sz);

		int needed = max(not_taken1, not_taken2) + x_sz;
		int fake = N - needed;

		printf("Case #%d: %d\n", e+1, fake);

	}


	return 0;
}