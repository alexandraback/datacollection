#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int reverse_int(int x) {
	int rev = 0;
	while (x) {
		rev *= 10;
		rev += x % 10;
		x /= 10;
	}
	return rev;
}

int solve_case() {
	int n;
	cin>>n;
	queue< pair< int, int > > q;
	map< int, int > done;
	q.push(make_pair(1, 1));
	done[1] = 1;
	while (!q.empty()) {
		int cv = q.front().first;
		int cs = q.front().second;
		q.pop();
		if (cv == n) {
			return cs;
		}
		if (done.find(cv + 1) == done.end()) {
			q.push(make_pair(cv + 1, cs + 1));
			done[cv + 1] = cs + 1;
		}
		int rev = reverse_int(cv);
		if (done.find(rev) == done.end()) {
			q.push(make_pair(rev, cs + 1));
			done[rev] = cs + 1;
		}
	}
}

int main() {
	int tt;
	cin>>tt;
	for (int t = 1; t <= tt; ++t) {
		cout<<"Case #"<<t<<": "<<solve_case()<<endl;
	}
	return 0;
}

