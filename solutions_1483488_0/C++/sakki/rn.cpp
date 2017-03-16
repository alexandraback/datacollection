#include <iostream>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <set>

using namespace std;

class Candidate {
	private:

		int digit[8];
		int value;
		int nd;

		inline int computeValue() {
			int mul = 1;
			int ret = 0;

			for(int i = 0; i < nd; i++, mul *= 10) {
				ret += (digit[i] * mul);
			}

			return ret;
		}

	public:

		Candidate(int value) {
			memset(digit, 0, sizeof(int) * 8);
			nd = 0;
			this->value = value;
			while(value > 0) {
				digit[nd++] = value % 10;
				value /= 10;
			}
		}

		inline int getValue() {
			return value;
		}

		int recycle() {
			int t;

			do {
				t = digit[0];
				for(int i = 1; i < nd; i++)
					digit[i-1] = digit[i];
				digit[nd-1] = t;
			} while(t == 0);

			t = computeValue();

			if(t == value)
				return -1;

			return t;
		}
};

int main() {
	const int NC2[] = { 0, 0, 1, 3, 6, 10, 15, 21 };
	bitset<2000000> used;
	int T, A, B;
	set<int> recycled;
	int result;
	int x;

	cin >> T;

	for(int tno=0; tno<T; tno++) {
		cin >> A >> B;

		cout<<"Case #"<<(tno + 1)<<": ";
		//cout<<"["<<A<<" - "<<B<<"]"<<endl;

		used.reset();
		result = 0;
		for(int i = A; i <= B; i++) {
			if(!used[i]) {
				//cout<<i<<": ";
				Candidate c(i);
				recycled.clear();

				used.set(i);
				recycled.insert(i);
				while((x = c.recycle()) > -1)  {
					if(x >= A && x <= B) {
						recycled.insert(x);
						used.set(x);
					}
				}

				if(recycled.size() > 1) {
					result += NC2[recycled.size()];
					/*cout<<"{ ";
					for(set<int>::iterator iter = recycled.begin();
							iter != recycled.end(); iter++) {
						cout<<(*iter)<<" ";
					}
					cout<<"}\n";*/
				}
			}
		}

		cout<<result<<endl;
	}

	return EXIT_SUCCESS;
}

int main1() {
	cout<<"{ ";

	/*
	//	Factorial
	int p = 1;
	for(int i=1; i<8; i++) {
		p *= i;
		cout<<p<<", ";
	}
	*/

	//	nC2
	const int FACT[] = { 1, 1, 2, 6, 24, 120, 720, 5040 };
	for(int i=2; i<8; i++) {
		cout << (FACT[i] / (2 * FACT[i - 2])) <<", ";
	}

	cout<<" }";
	return EXIT_SUCCESS;
}
