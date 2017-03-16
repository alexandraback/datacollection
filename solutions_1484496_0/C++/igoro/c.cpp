#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>


using namespace std;

vector<int> v;
int a[2000010];

void printvec(int m, int N) {
	bool first = true;
	for(int j=0; j<N; j++) {
		if (m&(1<<j)) {
			if (first) first = false;
			else cout <<" ";
			cout << v[j];
		}
	}
	cout<<endl;
}

void main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

    int cases;
    cin >> cases;

    for(int c=0; c<cases; c++) {
		int N;
		cin >> N;
		cout << "Case #" <<(c+1) << ":"<<endl;

		v.resize(N);
		for(int i=0; i<N; i++) cin >> v[i];

		memset(a, 0, sizeof(a));
		bool solved = false;
		for(int m=1; m<1<<N; m++) {
			int sum = 0;
			for(int i=0; i<N; i++) if (m & (1<<i)) sum += v[i];
			if (a[sum] != 0) {
				printvec(m, N);
				printvec(a[sum], N);
				break;
			}

			a[sum] = m;
		}
    }
}

