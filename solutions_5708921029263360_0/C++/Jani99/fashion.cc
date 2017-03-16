#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


struct Outfits {

	unsigned J,P,S,K;

	std::vector<bool> v;
	std::vector<unsigned> jpsv;

	Outfits(unsigned J, unsigned P, unsigned S, unsigned K):
		J(J),
		P(P),
		S(S),
		K(K),
		v(J*100,false)
		{
			for (unsigned j=0;j<J;++j) {
				for (unsigned p=0;p<P;++p) {
					for (unsigned s=0;s<S;++s) {
						v[j*100+p*10+s] = true;
					}
				}
			}
			jpsv.push_back(S);
			jpsv.push_back(P);
			jpsv.push_back(J);
		}

	unsigned pow10(unsigned ix) {
		unsigned r = 1;
		while (ix>0) {
			r*=10;
			--ix;
		}
		return r;
	}

	unsigned digit10(unsigned n, unsigned d) {
		while (d>0) {
			n/=10;
			--d;
		}
		return n%10;
	}

	unsigned pow(unsigned a, unsigned d) {
		unsigned r = 1;
		while (d > 0) {
			r*=a;
			--d;
		}
		return r;
	}

	unsigned getCombos(unsigned n, unsigned d) {

		unsigned nbase = n - pow(10,d) * digit10(n,d);
		unsigned dbase = pow(10,d);
		unsigned c = 0;

		for (unsigned i=0;i<jpsv[d];++i) {
			if (v[nbase+i*dbase]) {
				++c;
			}
		}

		if (c > K) {
			return c-K;
		}

		return 0;
	}

	unsigned getRedundancy(unsigned n) {
		std::vector<unsigned> r;
		unsigned r1 = 0;
		if (getCombos(n,0) > 0) {
			++r1;
		}
		if (getCombos(n,1) > 0) {
					++r1;
				}
		if (getCombos(n,2) > 0) {
					++r1;
				}

		r.push_back(getCombos(n,0));
		r.push_back(getCombos(n,1));
		r.push_back(getCombos(n,2));

		std::sort(r.begin(),r.end());

		return r1;
		//return r[0] + r[1] + r[2];
	}

	bool eliminateMostRedundant() {

		unsigned maxIx = 0;
		unsigned maxRed = 0;

		for (unsigned i=0;i<v.size();++i) {
			if (v[i]) {
				unsigned red = getRedundancy(i);
				if (red > maxRed) {
					maxRed = red;
					maxIx = i;
				}
			}
		}

		if (maxRed > 0) {
			v[maxIx] = false;
			return true;
		}

		return false;
	}

	void eliminate() {
		while (eliminateMostRedundant()) {
			;
		}
	}

	std::string toString() {

		unsigned n = 0;

		for (unsigned i=0;i<v.size();++i) {
			if (v[i]) {
				++n;
			}
		}

		std::ostringstream oss;
		oss << n << "\n";

		for (unsigned i=0;i<v.size();++i) {
			if (v[i]) {
				oss << digit10(i,2)+1 << " "
						<< digit10(i,1)+1 << " "
						<< digit10(i,0)+1 << "\n";
			}
		}

		return oss.str();
	}
};



int main(int argc, char **argv) {

	unsigned T;
	std::cin >> T;

	for (unsigned i=0; i<T; ++i) {
		unsigned J,P,S,K;
		std::cin >> J >> P >> S >> K;

		Outfits o(J,P,S,K);
		o.eliminate();

		printf("Case #%d: %s",i+1,o.toString().c_str());
	}

	return 0;
}










