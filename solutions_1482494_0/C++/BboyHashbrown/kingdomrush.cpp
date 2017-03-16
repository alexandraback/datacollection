#include <iostream>
#include <algorithm>

using namespace std;

struct obj {
	int stars;
	int needed;
	int oneed;
	int level;
};

bool comp(obj a, obj b) { return (a.stars == b.stars) ? a.oneed-a.needed > b.oneed-b.needed : a.stars > b.stars; }

int main()
{
	freopen("kingrush.in", "r", stdin);
	
	int T, N;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		obj tasks[N*2];
		for (int j = 0, k = 0; j < N*2; j += 2, k++) {
			int n1, n2;
			cin >> n1 >> n2;
			tasks[j] = (obj) {1, n1, n2, k};
			tasks[j+1] = (obj) {2, n2, n1, k};
		}
		sort(tasks, tasks+N*2, comp);
		int checked[N], times = 0, tstars = 0, iterations = 1;
		fill(checked, checked+N, 0);
		cout << "Case #" << (i+1) << ": ";
		while (iterations > 0) {
			iterations = 0;
			for (int j = 0; j < N*2; j++) {
				if (tasks[j].needed <= tstars && checked[tasks[j].level] < tasks[j].stars) {
					iterations++;
					times++;
					tstars += tasks[j].stars-checked[tasks[j].level];
					checked[tasks[j].level] = tasks[j].stars;
					break;
				}
			}
		}
		bool victory = true;
		for (int j = 0; j < N; j++)
			if (checked[j] != 2) {
				victory = 0;
				break;
			}
		if (!victory) cout << "Too Bad" << endl;
		else cout << times << endl;
	}	
}				
