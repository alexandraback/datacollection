#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<deque>
#include<utility>
#include<map>
#include<math.h>
#include<memory.h>

#define li long long
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair

using namespace std;

long long INF = 1e9 + 7;

struct attack{
	int day, l, r, power;
};

attack a[1000];

int wall[2000005], wallcopy[2000005];

bool cmp(attack x, attack y){
	if(x.day < y.day)
		return true;
	else
		return false;
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	//cout.setf(ios::fixed);
	//cout.precision(10);
	int T;
	cin >> T;
	for(int z = 0; z < T; z++){
		int N;
		cin >> N;
		int i;
		int k = 0;
		for(i = 0; i < N; i++){
			int day, l, r, power, delta_day, delta_power, delta_lr, n;
			cin >> day >> n >> l >> r >> power >> delta_day >> delta_lr >> delta_power;
			l += 1000000;
			r += 1000000;
			for(int j = 0; j < n; j++){
				a[k].day = day + delta_day * j;
				a[k].l = l + delta_lr * j;
				a[k].r = r + delta_lr * j;
				a[k].power = power + delta_power * j;
				k++;
			}
		}
		sort(a, a + k, cmp);
		memset(wall, 0, sizeof(wall));
		memset(wallcopy, 0, sizeof(wallcopy));
		int sum = 0;
		for(int j = a[i].l; j < a[i].r; j++){
			if(wall[j] < a[0].power){
				sum++;
				for(int w = a[0].l; w < a[0].r; w++){
					wallcopy[w] = max(wallcopy[w], a[0].power);
					wallcopy[w] = max(wallcopy[w], wall[w]);
				}
				break;
			}
		}
		for(i = 1; i < k; i++){
			if(a[i].day != a[i - 1].day)
				memcpy(wall, wallcopy, sizeof(wallcopy));
			for(int j = a[i].l; j < a[i].r; j++){
				//cout << " ";
				if(wall[j] < a[i].power){
					sum++;
					for(int w = a[i].l; w < a[i].r; w++){
						wallcopy[w] = max(wallcopy[w], a[i].power);
						wallcopy[w] = max(wallcopy[w], wall[w]);
					}
					break;
				}
			}
		}
		memcpy(wall, wallcopy, sizeof(wallcopy));
		cout << "Case #" << z + 1 << ": " << sum << "\n";
	}
	return 0;
}