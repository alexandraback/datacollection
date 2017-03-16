#include <istream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <algorithm>

using namespace std;
#define INPFILE "input.in"
#define OUTFILE "output.out"

ifstream inp;
ofstream out;

class Linker {
public:
	Linker(int num, string nm) :mNum(num), name(nm), mParent(nullptr) {

	}
	void join(shared_ptr<Linker> par) {
		//par = par->GetParent();
		while (par->mParent) 
			par = par->mParent;
		if (mParent == nullptr)
			mParent = par;
		else {
			shared_ptr<Linker> npar = GetParent();
			npar->mParent = par;
		}
	}
	int getnum() {
		if(mParent == nullptr)
			return mNum;
		shared_ptr<Linker> npar = GetParent();
		return npar->mNum;
	}
protected:
	shared_ptr<Linker> GetParent() {
		if (mParent == nullptr)
			return nullptr;
		shared_ptr<Linker> npar = mParent;
		while (npar->mParent)
			npar = npar->mParent;
		return npar;
	}
	shared_ptr<Linker> mParent;
	int mNum;
	string name;
};

template <typename T>
struct DLLNode {
	T mVal;
	shared_ptr<DLLNode> prev, next;
	DLLNode(T val):mVal(val), prev(nullptr), next(nullptr){}
};


void calculate(int t) {

	int B, M;
	inp >> B >> M;

	int max = 1 << (B-2);
	if(M > max)
		out << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
	else {
		out << "Case #" << t + 1 << ": POSSIBLE" << endl;
		out << "0";
		int m = max/2;
		int rem = M;
		for(int i = 0; i < B-2; i++){
			if (rem >= m) {
				rem -= m;
				out << "1";
			}
			else
				out << "0";
			m = m / 2;
		}
		if (rem)
			out << "1" << endl;
		else
			out << "0" << endl;
		for (int i = 1; i < B; i++) {
			int j;
			for (j = 0; j <= i; j++) {
				out << "0";
			}
			for (; j < B; j++) {
				out << "1";
			}
			out << endl;
		}
	}
}


int main() {
	int T;
	inp.open(INPFILE);
	out.open(OUTFILE);
	inp >> T;
	for (int t = 0; t < T; t++) {
		calculate(t);
	}
}
