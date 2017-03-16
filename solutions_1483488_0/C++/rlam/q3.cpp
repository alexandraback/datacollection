#include <iostream>
#include <deque>
#include <map>
using namespace std;


void getN (deque<int> & n, int value) {
	n.clear();
	while (value > 0) {
		n.push_front(value % 10);
		value /= 10;
	}
}

int getNextM(deque<int> & n) {
	deque<int>::iterator it;
	int ans = 0;

	n.push_front(n.back());
	n.pop_back();
		
	for (it = n.begin(); it != n.end(); it++) {
		ans *= 10;
		ans += *it;
	}

	return ans;	
}

int main()
{
	int case_num = 0;
	int i = 0;
	int j = 0;
	int A = 0;
	int B = 0;
	int ans = 0;
	int temp = 0;
	deque<int> n;
	map<int, int> mSet;

	cin >> case_num;
	for (i = 0; i < case_num; i++) {

		cin >> A >> B;
		ans = 0;
		for (j = A; j < B; j++) {
			getN(n, j);			
			mSet.clear();
			for (int k = 1; k < n.size(); k++) {
				int m = getNextM(n);
				if (m > j && m <= B)
					mSet.insert(pair<int,int>(m, m));
			}
			ans += mSet.size();
		}

		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
}
