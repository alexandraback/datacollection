#include<iostream>
#include<algorithm>
#include<cstdio>
#define loop(i, c) for(int i = 0; i < c; i++)

using namespace std;

int N;

struct M {
	double w;
	bool p;
} m[2000];

bool comp(const M &a, const M &b) {
	return a.w < b.w;
}

int main() {
	int T;
	cin >> T;
	loop(t, T) {
		cin >> N;
		loop(i, N) cin >> m[i].w;
		loop(i, N) cin >> m[N + i].w;
		loop(i, N) m[i].p = true;
		loop(i, N) m[N + i].p = false;
		sort(m, m+2*N, comp);
		int p1 = 0, p2 = 0;
		int s1 = 0;
		loop(i, 2*N) {
			if(!m[i].p) s1++;
			else if(s1) {
				s1--;
				p1++;
			}
			if(m[i].p) p2++;
			else if(p2) p2--;
		}
		printf("Case #%d: %d %d\n", t+1, p1, p2);
	}
}