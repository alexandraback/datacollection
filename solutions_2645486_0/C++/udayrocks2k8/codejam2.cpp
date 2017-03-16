#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int i64;

struct element {
    int n;
    int i;
};

bool cmp(struct element e1, struct element e2) {
    if (e1.n == e2.n) {
        e1.i < e2.i;
    }
    return e1.n > e2.n;
}

void getResult() {
    i64 e, r, n;
    cin >> e >> r >> n;
    i64 res = 0;
    struct element ele[n];
    int val[n];
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        ele[i].n = val[i];
        ele[i].i = i;
    }
    sort(ele, ele + n, cmp);
    
    int prev_index = 0;
    int energy_used[n];
    int energy_left = e;
    memset(energy_used, 0, n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        if (ele[i].i >= prev_index) {
            int max_index = -1;
            int max_value = -1;
            for (int j = prev_index; j < ele[i].i; j++) {
                energy_used[j] = 1;
                energy_left += (r - 1);
                if (val[j] > max_value) {
                    max_index = j;
                    max_value = val[j];
                }
                if (energy_left > e) {
                    energy_used[max_index] += energy_left - e;
                    energy_left = e;
                    max_value = -1;
                }
            }
            energy_used[ele[i].i] = energy_left;
            energy_left = r;
            prev_index = ele[i].i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        res += val[i] * energy_used[i];
    }
    cout << res << endl;
}



int main() {
	int testCases;
	cin >> testCases;
	for (int i = 1; i <= testCases; i++) {
		cout << "Case #" << i << ": ";
		getResult();
	}
	return 0;
}