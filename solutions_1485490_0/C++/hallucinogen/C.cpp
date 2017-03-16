#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
	int l1Row, l2Row;
	long long l1Count, l2Count;
	long long result;
} data;

#define TROLL 507LL

long long trolling(long long l1, long long l2) {
	return (l1 % TROLL) * (l2 % TROLL) % TROLL;
}

int main() {
	int ntc;
	
	scanf("%d", &ntc);
	
	int tc;
	for (tc = 1; tc <= ntc; ++tc) {
		int n, m;
		long long maksimal = 0;
		
		queue<data> q;
		
		scanf("%d %d", &n, &m);
		pair<long long, int> line1[n], line2[m];
		long long flagDP[n][m][TROLL];
		
		memset(flagDP, -1, sizeof(flagDP));
		for (int i = 0; i < n; ++i) {
			cin >> line1[i].first >> line1[i].second;
		}

		for (int i = 0; i < m; ++i) {
			cin >> line2[i].first >> line2[i].second;
		}
		
		data push;
		push.l1Row = 0;
		push.l2Row = 0;
		push.l1Count = line1[0].first;
		push.l2Count = line2[0].first;
		push.result = 0LL;
		
		q.push(push);
		
		while (!q.empty()) {
			data top = q.front();
			q.pop();
			
			data newData;
			
			//printf("%d %d ", top.l1Row, top.l2Row);
			//cout << top.l1Count << " " << top.l2Count << " >>>>>> " << top.result << endl;
			
			int l1Row = top.l1Row;
			int l2Row = top.l2Row;
			long long l1Count = top.l1Count;
			long long l2Count = top.l2Count;
			int l1Data = line1[l1Row].second;
			int l2Data = line2[l2Row].second;
			long long result = top.result;
			
			int newl1Row, newl2Row;
			long long newl1Count, newl2Count, newResult;
			
			// coba pasangin
			if (l1Data == l2Data) {
				// pasangin semuanya!!
				long long minim = l1Count < l2Count ? l1Count : l2Count;
				newResult = result + minim;
				
				newl1Row = l1Row;
				newl2Row = l2Row;
				
				if (l1Count == minim) {
					newl1Row = newl1Row + 1;
					newl2Row = newl2Row;
					if (newl1Row < n) {
						newl1Count = line1[newl1Row].first;
					}
					newl2Count = l2Count - minim;
				}

				if (l2Count == minim) {
					newl1Row = newl1Row;
					newl2Row = newl2Row + 1;
					// kalau ternyata l1 ngga 0, baru diganti
					if (l1Count != minim) {
						newl1Count = l1Count - minim;
					}
					if (newl2Row < m) {
						newl2Count = line2[newl2Row].first;
					}
				}
				
				maksimal = maksimal < newResult ? newResult : maksimal;

				// masukin ke queue
				if (newl1Row < n && newl2Row < m) {
					newData.l1Row = newl1Row;
					newData.l2Row = newl2Row;
					newData.l1Count = newl1Count;
					newData.l2Count = newl2Count;
					newData.result = newResult;
					
					maksimal = maksimal < newResult ? newResult : maksimal;
					
					if (flagDP[newl1Row][newl2Row][trolling(l1Count, l2Count)] < newResult) {
						flagDP[newl1Row][newl2Row][trolling(l1Count, l2Count)] = newResult;
						q.push(newData);
					}
				}
			}
			
			// coba buang line1
			newl1Row = l1Row + 1;
			newl2Row = l2Row;
			if (newl1Row < n) {
				newl1Count = line1[newl1Row].first;
			}
			newl2Count = l2Count;
			newResult = result;
			
			// masukin ke queue
			if (newl1Row < n && newl2Row < m) {
				newData.l1Row = newl1Row;
				newData.l2Row = newl2Row;
				newData.l1Count = newl1Count;
				newData.l2Count = newl2Count;
				newData.result = newResult;
				
				if (flagDP[newl1Row][newl2Row][trolling(l1Count, l2Count)] < newResult) {
					flagDP[newl1Row][newl2Row][trolling(l1Count, l2Count)] = newResult;
					q.push(newData);
				}
			}

			// coba buang line2
			newl1Row = l1Row;
			newl2Row = l2Row + 1;
			newl1Count = l1Count;
			if (newl2Row < m) {
				newl2Count = line2[newl2Row].first;
			}
			newResult = result;
			
			// masukin ke queue
			if (newl1Row < n && newl2Row < m) {
				newData.l1Row = newl1Row;
				newData.l2Row = newl2Row;
				newData.l1Count = newl1Count;
				newData.l2Count = newl2Count;
				newData.result = newResult;
				
				if (flagDP[newl1Row][newl2Row][trolling(l1Count, l2Count)] < newResult) {
					flagDP[newl1Row][newl2Row][trolling(l1Count, l2Count)] = newResult;
					q.push(newData);
				}
			}
		}
		
		printf("Case #%d: ", tc);
		cout << maksimal << endl;
	}
}
