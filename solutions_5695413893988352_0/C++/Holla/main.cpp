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

struct ConnNode {
	int fav;
	int loopCnt;
	bool isEnd;
	int cnt;
	ConnNode() :loopCnt(-1),isEnd(true), cnt(-1){}
};
int getNext(string S, int i, int M) {
	int N = S.size();
	string R(S);
	reverse(R.begin(), R.end());
	for (; i < M; i++) {
		int t = i;
		bool found = true;
		for (unsigned j = 0; j < N; j++) {
			if ((R[j] != '?') && ((R[j] - '0') != (t % 10))) {
				found = false;
				break;
			}
			t = t / 10;
		}
		if (found)
			return i;
	}
	return M*100;
}
void calculate(int t) {
	string C, J;
	inp >> C >> J;
	int max = 1;
	for (unsigned i = 0; i < C.size(); i++)
		max *= 10;
	int c = getNext(C, 0, max);
	int j = getNext(J, 0, max);
	int min = max;
	int minc, minj;
	while ((c < max) || (j < max)) {
		int t = c > j ? (c - j) : (j - c);
		if (t < min) {
			min = t;
			minc = c;
			minj = j;
		}
		if (c < j)
			c = getNext(C, c+1, max);
		else
			j = getNext(J, j+1, max);
	}
	string NC, NJ;
	for (unsigned i = 0; i < C.size(); i++) {
		NC.push_back((minc % 10) + '0');
		NJ.push_back((minj % 10) + '0');
		minc /= 10;
		minj /= 10;
	}

	reverse(NC.begin(), NC.end());
	reverse(NJ.begin(), NJ.end());
	out << "Case #" << t + 1 << ": " << NC << " " << NJ << endl;
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
