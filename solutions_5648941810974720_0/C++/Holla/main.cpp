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
void calculate(int t) {
	string S;
	vector<int> C(26, 0);
	vector<int> D(10, 0);
	inp >> S;
	for (unsigned i = 0; i < S.size(); i++) {
		C[S[i] - 'A']++;
	}
	if (C['Z' - 'A']) {
		int cnt = C['Z' - 'A'];
		D[0] = cnt;
		C['Z' - 'A'] -= cnt;
		C['E' - 'A'] -= cnt;
		C['R' - 'A'] -= cnt;
		C['O' - 'A'] -= cnt;
	}
	if (C['W' - 'A']) {
		int cnt = C['W' - 'A'];
		D[2] = cnt;
		C['T' - 'A'] -= cnt;
		C['W' - 'A'] -= cnt;
		C['O' - 'A'] -= cnt;
	}
	if (C['X' - 'A']) {
		int cnt = C['X' - 'A'];
		D[6] = cnt;
		C['S' - 'A'] -= cnt;
		C['I' - 'A'] -= cnt;
		C['X' - 'A'] -= cnt;
	}
	if (C['G' - 'A']) {
		int cnt = C['G' - 'A'];
		D[8] = cnt;
		C['E' - 'A'] -= cnt;
		C['I' - 'A'] -= cnt;
		C['G' - 'A'] -= cnt;
		C['H' - 'A'] -= cnt;
		C['T' - 'A'] -= cnt;
	}
	if (C['H' - 'A']) {
		int cnt = C['H' - 'A'];
		D[3] = cnt;
		C['T' - 'A'] -= cnt;
		C['H' - 'A'] -= cnt;
		C['R' - 'A'] -= cnt;
		C['E' - 'A'] -= cnt;
		C['E' - 'A'] -= cnt;
	}
	if (C['R' - 'A']) {
		int cnt = C['R' - 'A'];
		D[4] = cnt;
		C['F' - 'A'] -= cnt;
		C['O' - 'A'] -= cnt;
		C['U' - 'A'] -= cnt;
		C['R' - 'A'] -= cnt;
	}
	if (C['F' - 'A']) {
		int cnt = C['F' - 'A'];
		D[5] = cnt;
		C['F' - 'A'] -= cnt;
		C['I' - 'A'] -= cnt;
		C['V' - 'A'] -= cnt;
		C['E' - 'A'] -= cnt;
	}
	if (C['V' - 'A']) {
		int cnt = C['V' - 'A'];
		D[7] = cnt;
		C['S' - 'A'] -= cnt;
		C['E' - 'A'] -= cnt;
		C['V' - 'A'] -= cnt;
		C['E' - 'A'] -= cnt;
		C['N' - 'A'] -= cnt;
	}
	if (C['I' - 'A']) {
		int cnt = C['I' - 'A'];
		D[9] = cnt;
		C['N' - 'A'] -= cnt;
		C['I' - 'A'] -= cnt;
		C['N' - 'A'] -= cnt;
		C['E' - 'A'] -= cnt;
	}
	if (C['O' - 'A']) {
		int cnt = C['O' - 'A'];
		D[1] = cnt;
		C['O' - 'A'] -= cnt;
		C['N' - 'A'] -= cnt;
		C['E' - 'A'] -= cnt;
	}
	out << "Case #" << t + 1 << ": ";
	string res;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < D[i]; j++)
			out << i;
	}
	out << endl;
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
