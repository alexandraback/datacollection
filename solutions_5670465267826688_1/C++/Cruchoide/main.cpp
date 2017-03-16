#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class quaternion {
	public:
		quaternion(char q = '1', bool neg = false) :
			neg(neg), c(q) {}

		ostream& print(ostream& out) const {
			if(neg) out << "-";
			out << c;
			return out;
		}

		quaternion operator*(const quaternion& rhs) const {
			switch(c) {
				case '1':
					switch(rhs.c) {
						case '1': return quaternion('1', neg xor rhs.neg); break;
						case 'i': return quaternion('i', neg xor rhs.neg); break;
						case 'j': return quaternion('j', neg xor rhs.neg); break;
						case 'k': return quaternion('k', neg xor rhs.neg); break;
					}
					break;
				case 'i':
					switch(rhs.c) {
						case '1': return quaternion('i', neg xor rhs.neg); break;
						case 'i': return quaternion('1', not (neg xor rhs.neg)); break;
						case 'j': return quaternion('k', neg xor rhs.neg); break;
						case 'k': return quaternion('j', not (neg xor rhs.neg)); break;
					}
					break;
				case 'j':
					switch(rhs.c) {
						case '1': return quaternion('j', neg xor rhs.neg); break;
						case 'i': return quaternion('k', not (neg xor rhs.neg)); break;
						case 'j': return quaternion('1', not (neg xor rhs.neg)); break;
						case 'k': return quaternion('i', neg xor rhs.neg); break;
					}
					break;
				case 'k':
					switch(rhs.c) {
						case '1': return quaternion('k', neg xor rhs.neg); break;
						case 'i': return quaternion('j', neg xor rhs.neg); break;
						case 'j': return quaternion('i', not (neg xor rhs.neg)); break;
						case 'k': return quaternion('1', not (neg xor rhs.neg)); break;
					}
					break;
			}
			return quaternion('1');
		}

		bool operator==(const quaternion& q) { return c == q.c && neg == q.neg; }
		bool operator!=(const quaternion& q) { return c != q.c || neg != q.neg; }

		quaternion pow(long k) {
			k = k % 4;
			if(k == 0)
				return quaternion();
			if(k == 1)
				return *this;
			quaternion q = *this;
			return (q*q).pow(k/2) * q.pow(k%2);
		}
	private:
		bool neg;
		char c;
};

ostream& operator<<(ostream& out, const quaternion& q) {
	q.print(out);
	return out;
}

template<class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[";
	if(v.size()) {
		out << v.front();
		for(auto i = v.begin()+1, e = v.end(); i != e; ++i)
			out << ", " << *i;
	}
	out << "]";
	return out;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;

	quaternion ijk('1', true);

	for(int t = 0; t < T; ++t) {
		int L;
		long X;
		cin >> L >> X;
		quaternion total;
		vector<quaternion> list;
		for(int l = 0; l < L; ++l) {
			char c;
			cin >> c;
			list.push_back(quaternion(c));
			total = total * list.back();
		}
		if(total.pow(X) != ijk)
			cout << "Case #" << t+1 << ": NO" << endl;
		else {
			long Xt = min(12l+X%4, X);
			long is;
			quaternion i;
			for(is = 0; is < Xt*list.size(); ++is) {
				if(i == quaternion('i'))
					break;
				i = i*list[is%list.size()];
			}
			long js;
			quaternion j;
			for(js = is; js < Xt*list.size(); ++js) {
				if(j == quaternion('j'))
					break;
				j = j*list[js%list.size()];
			}
			if(js < Xt*list.size()) {
				cout << "Case #" << t+1 << ": YES" << endl;
			} else
				cout << "Case #" << t+1 << ": NO" << endl;
		}
	}

	return 0;
}
